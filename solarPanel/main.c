/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
#include "mcc_generated_files/mcc.h"
#define _XTAL_FREQ 100000000 //Crystal Frequency, used in delay
uint16_t map(int value, int inputMin, int inMax, int outMin, int outMax);
int pos=74;
void main(void)
{
    /* Configure the oscillator for the device */
void SYSTEM_Initialize();
    /* Initialize I/O and Peripherals for application */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */
    

    while (1)
    {
        uint16_t position1 = ADC_GetConversion(5);
        uint16_t position2 = ADC_GetConversion(6);
        uint16_t mappedValue1 = map(position1,0,1023,99,49);
        uint16_t mappedValue2 = map(position2,0,1023,99,49);
       
   
 if(mappedValue1  > (mappedValue2))
  {    

    if(pos<99){
    pos=pos+1;
   
     PWM4_LoadDutyValue(pos);  

  }
        }

  else if(mappedValue2 > (mappedValue1))

  {

    if(pos>49){

     pos=pos-1;

   PWM4_LoadDutyValue(pos);
        
   

  }     
        
    }
}
}

uint16_t map(int value, int inputMin, int inMax, int outMin, int outMax){
    return (value - inputMin) * (outMax - outMin) / (inMax - inputMin) + outMin;
}