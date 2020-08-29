/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2017
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 ADC demo code
//***********************************************************************************************************

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"

#include <stdlib.h>
//#include <string.h>
//--#include <strings.h>

// ***** Set one of these in oled_spi_i2c.h: *****
//  #define  Enable_OLED_DisplayString          1
//  #define  Enable_OLED_SPI                    1
// ***** *****

#include "oled_spi_i2c.h"
#include "logo.h"

//debug test ----
//#include "NuTiny8051.h"

//Globals
int xcount = 42;

void do_oled_test(void);

void blink(uint16_t count){

    if (count > 250) count = 250;

    uint16_t blink_delay = 1000/(count + 2);

    Timer0_Delay1ms (blink_delay);
    P12 =! P12;

    while (count > 0)
    {
        count--;
        Timer0_Delay1ms (blink_delay);
        P12 =! P12;
    }
    

}

/******************************************************************************
 The main C function.  Program execution starts
 here after stack initialization.
 ******************************************************************************/
void main (void) 
{

    blink(10);

//int xcount = 42;

Set_All_GPIO_Quasi_Mode;
    
    InitialUART0_Timer1(115200);
    printf("\nHello Test %u\n", xcount);
    Timer0_Delay1ms (100);

    blink(1);

    do_oled_test();
}

void do_oled_test()
{		 
    //Timer0_Delay1ms (2000);
    OLED_Init();

    //Timer0_Delay1ms (2000);

    blink(1);
while(true){
    OLED_EnableInversion();
    //OLED_DisableInversion();

    OLED_DisplayLogo(LogoBitMap);
    Timer0_Delay1ms (4000);
    OLED_DisableInversion();
    Timer0_Delay1ms (4000);
    OLED_Clear();

    OLED_SetCursor(2,0);  //Set cursor at 2nd-line 0th-Position
    OLED_DisplayString("Oled Interface");	
    
    OLED_SetCursor(4,20); //Set cursor at 4th-line 20th-Position
    OLED_DisplayString("With 8051 From");
    
    OLED_SetCursor(6,30); //Set cursor at 6th-line 30th-Position
    OLED_DisplayString("Exploreembedded");    

    Timer0_Delay1ms (2000);
    OLED_EnableInversion();
    OLED_Clear();
    //Timer0_Delay1ms (2000);

    OLED_SetCursor(0,0); //Set cursor at 4th-line 20th-Position
    OLED_DisplayString("*****");

    OLED_SetCursor(4,0); //Set cursor at 4th-line 20th-Position
    OLED_DisplayString("Hello World -- ");
    //OLED_DisplayNumber(10, xcount, C_DisplayDefaultDigits_U8);
    //OLED_DisplayNumber(10, 3456, 5);

    char stringnumber[8];
    //_itoa(xcount++, stringnumber, 10);
    _itoa(xcount--, stringnumber, 10);
    OLED_DisplayString(stringnumber);

    Timer0_Delay1ms (4000);
    OLED_DisableInversion();

    Timer0_Delay1ms (6000);
}
    while(1);
}
