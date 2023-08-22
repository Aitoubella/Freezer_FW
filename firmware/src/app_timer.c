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
//#include "./config/default/peripheral/tmr/plib_tmr2.h"
#include "device.h"
#include "app_timer.h"

/* TODO:  Include other files here if needed. */


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
volatile uint32_t app_timer_clk_val_hi;
clk_64_bit app_tmr_clk;

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
//static int ExampleLocalFunction(int param1, int param2) {
//    return 0;
//}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */

uint64_t tmr_get_value() {
//    volatile uint32_t *ptr = &TMR2;
//    return *ptr;
    //uint32_t val = 0u;
//    return app_timer_clk_val;
//    return (volatile uint32_t) TMR2;
//    return Counter32BitGetSave(2);
//    uint64_t val_64 = *app_tmr_clk.val_64;
//    return val_64;
    return *app_tmr_clk.val_64;
}

void tmr_store_time(app_timer_t *tmr){
    tmr->tmr_val = tmr_get_value();
}

unsigned long long tmr_runtime(app_timer_t *tmr){
    tmr_store_time(tmr);
    return (tmr->tmr_val - tmr->period_start_time);
}

unsigned long long tmr_total_runtime(app_timer_t *tmr){
    tmr_store_time(tmr);
    return (tmr->tmr_val - tmr->start_time);
}

unsigned int tmr_time_is_up(app_timer_t *tmr){
    return (tmr_is_enabled(tmr) && (tmr_runtime(tmr) >= tmr->period));
}

void tmr_calc_period_end(app_timer_t *tmr){
    tmr->period_end_time = tmr->period_start_time + tmr->period;
}

unsigned int tmr_start(app_timer_t *tmr){
    
    if (tmr->period <= 0){
        tmr->enabled = 0;
        return 1;
    }
    
    tmr->enabled = 1;
    tmr_force_reset(tmr);
    tmr->start_time = tmr->tmr_val;
    
    return 0;
}

void tmr_stop(app_timer_t *tmr){
    tmr->enabled = 0;
}

unsigned int tmr_set_period_us(app_timer_t *tmr, uint64_t period){
    if (period > 0){
        if (period < MAX_VAL_PERIOD){
            tmr->period = (period * 40000000) / 1000000;
        }else{
            tmr->period = (period / 1000000) * 40000000;
        }
        
        return 0;
    }
    
    return 1;
}

unsigned int tmr_set_period_ms(app_timer_t *tmr, unsigned long long period){
    return (tmr_set_period_us(tmr, period * 1000));
}

void tmr_set_recurring(app_timer_t *tmr, unsigned int recurring){
    tmr->recurring = (recurring == 1);
}

unsigned int tmr_is_enabled(app_timer_t *tmr){
    return (tmr->enabled == 1);
}

void tmr_force_reset(app_timer_t *tmr){
    tmr_store_time(tmr);
    tmr->period_start_time = tmr->tmr_val;
    tmr_calc_period_end(tmr);
    tmr->expired = 0;
}

unsigned int tmr_is_invalid(app_timer_t *tmr){
    
    if (tmr->period <= 0){
        tmr->enabled = 0;
        return 1;
    }
    
    if (!tmr->enabled){
        return 2;
    }
    
    return 0;
}

unsigned int tmr_reset(app_timer_t *tmr){
    
    unsigned int retval;
    
    retval = tmr_is_invalid(tmr);
    if (retval > 0){
        return retval;
    }
    
    tmr_force_reset(tmr);
    
    return 0;
}

unsigned int tmr_reset_exact(app_timer_t *tmr){
    
    unsigned int retval;
    
    retval = tmr_is_invalid(tmr);
    if (retval > 0){
        return retval;
    }
    
    tmr_store_time(tmr);
    tmr->period_start_time = tmr->period_end_time;
    tmr_calc_period_end(tmr);
    tmr->expired = 0;
   
    return 0;
}

unsigned int tmr_expired(app_timer_t *tmr){
    
    if (tmr_time_is_up(tmr)){
        tmr->expired = 1;
        
        if(tmr->recurring){
            tmr_reset_exact(tmr);
        }else{
            tmr->enabled = 0;
        }
        
        return 1;
    }
    
    return 0;
}

//void TIMER_2_Handler (void);
//
//void __ISR(_TIMER_2_VECTOR, ipl1SOFT) TIMER_2_Handler (void)
//{
////    uint32_t status = IFS0bits.T2IF;
//    IFS0CLR = _IFS0_T2IF_MASK;
//    app_timer_clk_val ++;
//}

void app_timer_isr(uint32_t status, uintptr_t context){
    app_timer_clk_val_hi ++;
}

void tmr_app_enable_global(){
    app_tmr_clk.val_32[0] = &TMR2;
    app_tmr_clk.val_32[1] = &app_timer_clk_val_hi;
    app_timer_clk_val_hi = 0;
//    TMR2_CallbackRegister(&app_timer_isr, 0);
//    TMR2_Start(); 
}

/* *****************************************************************************
 End of File
 */
