/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _APP_TIMER_H    /* Guard against multiple inclusion */
#define _APP_TIMER_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "device.h"


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
#define MAX_VAL_64      0xFFFFFFFFFFFFFFFF
#define MAX_VAL_PERIOD  ((MAX_VAL_64 / 40000000) - 1)


    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
typedef struct app_timer_t {
    /* Describe structure member. */
    unsigned long long period;
    unsigned long long tmr_val;
    unsigned long long start_time;
    unsigned long long period_start_time;
    unsigned long long period_end_time;

    /* Describe structure member. */
    unsigned int enabled;
    unsigned int expired;
    unsigned int recurring;

} app_timer_t;

typedef union clk_64_bit {
    /* Describe structure member. */
    volatile uint32_t *val_32[2];
    volatile uint64_t *val_64;

} clk_64_bit;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

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

uint64_t tmr_get_value();
void tmr_store_time(app_timer_t *tmr);
unsigned long long tmr_runtime(app_timer_t *tmr);
unsigned long long tmr_total_runtime(app_timer_t *tmr);
unsigned int tmr_time_is_up(app_timer_t *tmr);
void tmr_calc_period_end(app_timer_t *tmr);
unsigned int tmr_start(app_timer_t *tmr);
void tmr_stop(app_timer_t *tmr);
unsigned int tmr_set_period_us(app_timer_t *tmr, unsigned long long period);
unsigned int tmr_set_period_ms(app_timer_t *tmr, unsigned long long period);
void tmr_set_recurring(app_timer_t *tmr, unsigned int recurring);
unsigned int tmr_is_enabled(app_timer_t *tmr);
void tmr_force_reset(app_timer_t *tmr);
unsigned int tmr_reset(app_timer_t *tmr);
unsigned int tmr_reset_exact(app_timer_t *tmr);
unsigned int tmr_expired(app_timer_t *tmr);
void tmr_app_enable_global();

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
