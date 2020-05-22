/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F45K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.35	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN12 aliases
#define channel_AN12_TRIS                 TRISBbits.TRISB0
#define channel_AN12_LAT                  LATBbits.LATB0
#define channel_AN12_PORT                 PORTBbits.RB0
#define channel_AN12_WPU                  WPUBbits.WPUB0
#define channel_AN12_ANS                  ANSELBbits.ANSB0
#define channel_AN12_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define channel_AN12_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define channel_AN12_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define channel_AN12_GetValue()           PORTBbits.RB0
#define channel_AN12_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define channel_AN12_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define channel_AN12_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define channel_AN12_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define channel_AN12_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define channel_AN12_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set channel_AN10 aliases
#define channel_AN10_TRIS                 TRISBbits.TRISB1
#define channel_AN10_LAT                  LATBbits.LATB1
#define channel_AN10_PORT                 PORTBbits.RB1
#define channel_AN10_WPU                  WPUBbits.WPUB1
#define channel_AN10_ANS                  ANSELBbits.ANSB1
#define channel_AN10_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define channel_AN10_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define channel_AN10_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define channel_AN10_GetValue()           PORTBbits.RB1
#define channel_AN10_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define channel_AN10_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define channel_AN10_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define channel_AN10_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define channel_AN10_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define channel_AN10_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSD1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/