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
#include "bq25731_driver.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */
// Write byte value to register at reg_address

void bq25731_write(unsigned char reg_address, unsigned char val) {
    I2C_start(); /* Send start condition */
    I2C_write(BQ25731_ADDR << 1, 1); /* Send MPU9250's address, read/write bit not set (AD + R) */
    I2C_write(reg_address, 1); /* Send the register address (RA) */
    I2C_write(val, 1); /* Send the value to set it to */
    I2C_stop(); /* Send stop condition */
}

// Read a byte from register at reg_address and return in *value

void bq25731_read(unsigned char reg_address, unsigned char *val) {
    I2C_start(); /* Send start condition */
    I2C_write(BQ25731_ADDR << 1, 1); /* Send MPU9250's address, read/write bit not set (AD + R) */
    I2C_write(reg_address, 1); /* Send the register address (RA) */
    I2C_restart(); /* Send repeated start condition */
    I2C_write(BQ25731_ADDR << 1 | 1, 1); /* Send MPU9250's address, read/write bit set (AD + W) */
    I2C_read(val, 1); /* Read value from the I2C bus */
    I2C_stop(); /* Send stop condition */
}

void bq25731_write_verify(unsigned char reg_address, unsigned char write_val, unsigned char *read_val) {

    while (1) {
        bq25731_read(reg_address, read_val);

        if (*read_val == write_val) {
            break;
        }

        delay_ms(10);
        bq25731_write(reg_address, write_val);
    }
}

/* *****************************************************************************
 End of File
 */
