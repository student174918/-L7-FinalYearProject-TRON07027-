/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
   /*    ADFM = 0;
    
    ACQT0 = 1;
    ACQT1 = 0;
    ACQT2 = 1;
    
    ADCS0 = 1;
    ADCS1 = 1;
    ADCS2 = 1;
    
    PVCFG1 = 0;
    PVCFG0 = 0;
    
    NVCFG1 = 0;
    NVCFG0 = 0; 
    IRCF0 = 1;
    IRCF1 = 1;
    IRCF2 = 1;
    */
        
    TRISD = 0x00;
    TRISB = 0x00; // PORT B as output port
    PORTB = 0x0F;
    TRISA = 0x1F;
    ANSELA = 0x0F;
    

  
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */

    /* Initialize peripherals */

    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */

    /* Enable interrupts */
}

