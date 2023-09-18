/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "freezer_i2c.h"
#include "device.h"
#include "definitions.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
// I2C_wait_for_idle() waits until the I2C peripheral is no longer doing anything  

unsigned int count;

void delay_us(unsigned int us) {

    // Convert microseconds us into how many clock ticks it will take
    us *= CPU_CLOCK_FREQUENCY / 1000000 / 2; // Core Timer updates every 2 ticks

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    //    while (us > _CP0_GET_COUNT()); // Wait until Core Timer count reaches the number we calculated earlier
    do {
        count = _CP0_GET_COUNT();
    } while (us > count); // Wait until Core Timer count reaches the number we calculated earlier
}

void delay_ms(unsigned int ms) {
    delay_us(ms * 1000);
}

void I2C_init(double frequency) {
    double BRG;

    I2C1CON = 0; // Turn off I2C1 module
    I2C1CONbits.DISSLW = 1; // Disable slew rate for 100kHz

    BRG = (1 / (2 * frequency)) - 0.000000104;
    BRG *= (CPU_CLOCK_FREQUENCY / 2) - 2;

    I2C1BRG = (int) BRG; // Set baud rate
    I2C1CONbits.ON = 1; // Turn on I2C1 module
}

void I2C_wait_for_idle(void) {
    while (I2C1CON & 0x1F); // Acknowledge sequence not in progress
    // Receive sequence not in progress
    // Stop condition not in progress
    // Repeated Start condition not in progress
    // Start condition not in progress
    while (I2C1STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress
}

// I2C_start() sends a start condition  

void I2C_start(void) {
    I2C_wait_for_idle();
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN == 1);
}

// I2C_stop() sends a stop condition  

void I2C_stop(void) {
    I2C_wait_for_idle();
    I2C1CONbits.PEN = 1;
}

// I2C_restart() sends a repeated start/restart condition

void I2C_restart(void) {
    I2C_wait_for_idle();
    I2C1CONbits.RSEN = 1;
    while (I2C1CONbits.RSEN == 1);
}

// I2C_ack() sends an ACK condition

void I2C_ack(void) {
    I2C_wait_for_idle();
    I2C1CONbits.ACKDT = 0; // Set hardware to send ACK bit
    I2C1CONbits.ACKEN = 1; // Send ACK bit, will be automatically cleared by hardware when sent  
    while (I2C1CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning ACK bit has been sent
}

// I2C_nack() sends a NACK condition

void I2C_nack(void) // Acknowledge Data bit
{
    I2C_wait_for_idle();
    I2C1CONbits.ACKDT = 1; // Set hardware to send NACK bit
    I2C1CONbits.ACKEN = 1; // Send NACK bit, will be automatically cleared by hardware when sent  
    while (I2C1CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning NACK bit has been sent
}

// address is I2C slave address, set wait_ack to 1 to wait for ACK bit or anything else to skip ACK checking  

signed char I2C_write(unsigned char address, char wait_ack) {

//    static unsigned int mode = 0;
    //    static unsigned int next_mode = 0;
//    static unsigned int count = 0;

    //    switch (mode) {
    //
    //        case 0:
    //            count = 0;
    //            I2C1TRN = address | 0; // Send slave address with Read/Write bit cleared
    //            //            next_mode = 20;
    //            mode = 20;
    //            break;
    //
    //        case 10:
    //            delay_ms(10);
    //            break;
    //
    //        case 20:
    //            if (I2C1STATbits.TBF == 1) {
    //                mode = 30;
    //            } else if (count > 100) {
    //                mode = 0;
    //                return -1;
    //            } else {
    //                count++;
    //            }
    //            break;
    //
    //        case 30:
    //            count = 0;
    //            I2C_wait_for_idle(); // Wait until I2C bus is idle
    //            if (wait_ack) {
    //                mode = 40;
    //            } else if (count > 100) {
    //                mode = 0;
    //                return -1;
    //            } else {
    //                count++;
    //            }
    //            break;
    //
    //        case 40:
    //            if (I2C1STATbits.ACKSTAT == 1) { // Wait until ACK is received  
    //                mode = 0;
    //                return 0;
    //            } else if (count > 100) {
    //                mode = 0;
    //                return -1;
    //            } else {
    //                count++;
    //            }
    //            break;
    //
    //        default:
    //            mode = 0;
    //    }

    I2C1TRN = address | 0; // Send slave address with Read/Write bit cleared
    while (I2C1STATbits.TBF == 1) {
        delay_ms(10);
    }
    I2C_wait_for_idle(); // Wait until I2C bus is idle
    if (wait_ack) {

        while (I2C1STATbits.ACKSTAT == 1) { // Wait until ACK is received  
            delay_ms(10);
        }
    }

    return 1;

}

// value is the value of the data we want to send, set ack_nack to 0 to send an ACK or anything else to send a NACK  

void I2C_read(unsigned char *val, char ack_nack) {
    I2C1CONbits.RCEN = 1; // Receive enable
    delay_us(10);
    while (I2C1CONbits.RCEN) { // Wait until RCEN is cleared (automatic)  
        delay_ms(10);
    }
    while (!I2C1STATbits.RBF) { // Wait until Receive Buffer is Full (RBF flag)  
        delay_ms(10);
    }
    *val = I2C1RCV; // Retrieve value from I2C1RCV

    if (!ack_nack) // Do we need to send an ACK or a NACK?  
        I2C_ack(); // Send ACK  
    else
        I2C_nack(); // Send NACK  
}

/* *****************************************************************************
 End of File
 */
