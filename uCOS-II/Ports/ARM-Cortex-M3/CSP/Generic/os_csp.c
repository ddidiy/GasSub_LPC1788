/*
*********************************************************************************************************
*                                               uC/OS-II
*                                         The Real-Time Kernel
*
*
*                                (c) Copyright 2010, Micrium, Weston, FL
*                                          All Rights Reserved
*
*                                     ARM Cortex M3 OS Chip Support
*                                              Generic
*
* File      : os_csp.h
* Version   : V2.92
* By        : FT
*
* For       : ARMv7M Cortex-M3
* Mode      : Thumb2
*********************************************************************************************************
*/

#define  OS_CSP_GLOBALS
#include <ucos_ii.h>
#include <csp.h>


/*$PAGE*/
/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           LOCAL CONSTANTS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          LOCAL DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            LOCAL TABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                     LOCAL CONFIGURATION ERRORS
*********************************************************************************************************
*/



/*$PAGE*/
/*
************************************************************************************************************************
*                                                INITIALIZE TICKER INTERRUPT
*
* Description: Initialize the the Tick Interrupt.
*
* Arguments  : none.
*
* Note(s)    : (1) This function MUST be called after OSStart() & after processor initialization.
************************************************************************************************************************
*/

void  OS_CSP_TickInit (void)
{
    CPU_INT32U  cnts;
    CPU_INT32U  cpu_freq;
    
    
    cpu_freq = CSP_PM_CPU_ClkFreqGet();                         /* Get the CPU clock                                    */
    cnts     = (cpu_freq / OS_TICKS_PER_SEC);                   /* Calculate the number of SysTick counts               */

    OS_CPU_SysTickInit(cnts);                                   /* Call the Generic OS Systick initialization           */
}


/*$PAGE*/
/*
************************************************************************************************************************
*                                               INTERRUPT CONTROLLER HANDLER
*
* Description: Handles all Cortex M3 NVIC's external sources interrupts
*
* Arguments  : none.
*
* Note(s)    : none.
************************************************************************************************************************
*/

void  OS_CPU_IntHandler (void) 
{
    CPU_SR_ALLOC();
    
    
    CPU_CRITICAL_ENTER();                                       /* Tell the OS that we are starting an ISR              */

    OSIntEnter();

    CPU_CRITICAL_EXIT();
    
    CSP_IntHandler();                                           /* Call the generic CSP interrupt handler.              */
    
    OSIntExit();                                                /* Tell the OS that we are leaving the ISR              */
}
