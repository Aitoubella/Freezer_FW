/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

static void btn1_handler(GPIO_PIN pin, uintptr_t context)
{
    if (pin == BTN1_D_PIN)
    {
        if (BTN1_D_Get()) {
            TEST_LED_Set();
        }       
        else {
            TEST_LED_Clear();
        }
    }
}
void setup_btn() {
    GPIO_PinInterruptCallbackRegister(BTN1_D_PIN, btn1_handler, 0);
    BTN1_D_InterruptEnable();
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    /* setup button 1 */
    setup_btn();

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        TEST_LED_Set();
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

