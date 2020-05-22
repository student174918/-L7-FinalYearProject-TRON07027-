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
/*
 * File:   main.c
 * Author: Sourav Gupta
 * By:- circuitdigest.com
 * Created on May 10, 2018, 1:26 PM
 * This program will drive a servo motor.
 */
 
// PIC16F877A Configuration Bit Settings
 
// 'C' source line config statements
 
// CONFIG

 
 
 
#include <xc.h>
#include <stdio.h>
 
/*
 Hardware related definition
 */
 
#define _XTAL_FREQ 200000000 //Crystal Frequency, used in delay
#define speed 1 // Speed Range 10 to 1  10 = lowest , 1 = highest
#define steps 512 // how much step it will take
#define clockwise 0 // clockwise direction macro
#define anti_clockwise 1 // anti clockwise direction macro
 
 
/*
 *Application related function and definition
 */
 

void full_drive (char direction); // This function will drive the motor in full drive mode
void ms_delay(unsigned int val);
uint16_t ADC_Read(uint8_t channel);
void ADC_Init (void);
 
/*
 * main function starts here
 */
char position;
char results[4];
void main(void)
{

   /* Configure the oscillator for the device */
ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

position = 0;
while(1){
    


ADC_Init (); 
  
  results[0] = ADC_Read(0); // read channel 0-> RA0    
  results[1] = ADC_Read(1); // read channel 1-> RA1 
  results[2] = ADC_Read(2); // read channel 2-> RA2  
  results[3] = ADC_Read(3); // read channel 2-> RA3 
  
 
  
  if((results[0] < results[1]) && (results[0] < results[2]) && (results[0] < results[3]))
  {
      
      if(position == 1){
          for(int i=0;i<125;i++)
            {
            full_drive(anti_clockwise);
            }
      }
      
      else if(position == 2){
          for(int i=0;i<250;i++)
            {
            full_drive(anti_clockwise);
            }
      }
      else if(position == 3){
          for(int i=0;i<125;i++)
            {
            full_drive(clockwise);
            }
      }
      position = 0;
      
  }
  
  if(results[1] < results[0] && results[1] < results[2] && results[1] < results[3])
  {
      
      if(position == 0){
          for(int i=0;i<125;i++)
            {
            full_drive(clockwise);
            }
      }
      
      else if(position == 2){
          for(int i=0;i<125;i++)
            {
            full_drive(anti_clockwise);
            }
      }
      else if(position == 3){
          for(int i=0;i<250;i++)
            {
            full_drive(clockwise);
            }
      }
      position = 1;
      
  }
  
   if(results[2] < results[1] && results[2] < results[0] && results[2] < results[3])
  {
      
      if(position == 1){
          for(int i=0;i<125;i++)
            {
            full_drive(clockwise);
            }
      }
      
      else if(position == 0){
          for(int i=0;i<250;i++)
            {
            full_drive(clockwise);
            }
      }
      else if(position == 3){
          for(int i=0;i<125;i++)
            {
            full_drive(anti_clockwise);
            }
      }
      position = 2;
      
  }
  
   if(results[3] < results[1] && results[3] < results[2] && results[3] < results[0])
  {
      
      if(position == 1){
          for(int i=0;i<250;i++)
            {
            full_drive(anti_clockwise);
            }
      }
      
      else if(position == 2){
          for(int i=0;i<125;i++)
            {
            full_drive(clockwise);
            }
      }
      else if(position == 0){
          for(int i=0;i<125;i++)
            {
            full_drive(anti_clockwise);
            }
      }
      position = 3;
      
  }

          
  
ms_delay(700);
}
}
 
/*System Initialising function to set the pin direction Input or Output*/
 

 
/*This will drive the motor in full drive mode depending on the direction*/
 
void full_drive (char direction){
    if (direction == clockwise){
        PORTB = 0b00000011;
        ms_delay(speed);
        PORTB = 0b00000110;
        ms_delay(speed);
        PORTB = 0b00001100;
        ms_delay(speed);
        PORTB = 0b00001001;
        ms_delay(speed);
        PORTB = 0b00000011;
        ms_delay(speed);
    }
    if (direction == anti_clockwise){
        PORTB = 0b00001001;
        ms_delay(speed);
        PORTB = 0b00001100;
        ms_delay(speed);
        PORTB = 0b00000110;
        ms_delay(speed);
        PORTB = 0b00000011;
        ms_delay(speed);
        PORTB = 0b00001001;
        ms_delay(speed);
    }
        
}
 


 
/*This method will create required delay*/
 
void ms_delay(unsigned int val)
{
     unsigned int i,j;
        for(i=0;i<val;i++)
            for(j=0;j<3000;j++);
} 


uint16_t ADC_Read(uint8_t channel)
{
    ADCON0 = (channel<<2);
    ADCON0|=0x03; 

    while(ADCON0bits.GO_nDONE); 

    return ((ADRESH<<8) | (ADRESL));
}


void ADC_Init (void)
{
    
    PVCFG1 = 0;
    PVCFG0 = 0;
   
    NVCFG1 = 0;
    NVCFG0 = 0;
    
    ADCON2 = 0x92;  // A/D CLK=FOSC/32, 4TAD, RIGHT justified
}