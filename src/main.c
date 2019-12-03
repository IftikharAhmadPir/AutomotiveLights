#include "init.h"

void showData(int value);

/********************************************************************
 *         
 main                                *
 ********************************************************************/
 
 int value; // Global Variable
 
void main(void)
{
    /* board initialization */
    Init();
    
   SIU.GPDO[9].R = 1 ;   /* LED0 */
   SIU.GPDO[42].R = 1;    /* LED1 */
   SIU.GPDO[13].R = 1;   /* LED2 */
   SIU.GPDO[12].R = 1;    /* LED3 */
   SIU.GPDO[62].R = 1;    /* LED4 */
   SIU.GPDO[61].R = 1 ;   /* LED5 */
   SIU.GPDO[59].R = 1;    /* LED6 */
   SIU.GPDO[11].R = 1;      /* LED7 */
    /* forever */
    for(;;)
    {
/********************************************************************
 *                           Main Loop                              *
 *                    _____  ___  ___   ___                         *
 *                   |_   _|/ _ \|   \ / _ \                        *
 *                     | | | (_) | |) | (_) |                       *
 *                     |_|  \___/|___/ \___/                        *
 *                                                                  *
 *                  Write down your logic here.                     *
 ********************************************************************/ 

        
        //value = ADC_0.CDR[2].B.CDATA;       // Task 2.1 (Light Sensor)
        value = ADC_0.CDR[4].B.CDATA;       // Task 2.2 (Potentio Meter)
        showData(value);
     
// Task 3.1 
    
    
        if(SIU.GPDI[0].R == 0){
            
               SIU.GPDO[61].R = 0;  // Glowing LED 5
            
        } else if(SIU.GPDI[1].R == 0){
            
               SIU.GPDO[59].R = 0;  // Glowing LED 6
            
        }else{
            
               SIU.GPDO[61].R = 1; // otherwise mnake it off
               SIU.GPDO[59].R = 1;
         }


        // Task 3.2
         
        if(SIU.GPDI[44].R == 0){
                     
              PIT_ConfigureTimer(0, 1000);
              PIT_StartTimer(0);

        }else{
                    
              SIU.GPDO[11].R = 1;      // LED7
              PIT_StopTimer(0);   
        }
    
    
    
    }
}



void showData(int value)
{
/********************************************************************
 *                    _____  ___  ___   ___                         *
 *                   |_   _|/ _ \|   \ / _ \                        *
 *                     | | | (_) | |) | (_) |                       *
 *                     |_|  \___/|___/ \___/                        *
 *                                                                  *
 ********************************************************************/  
//Subtask 2.2

if(value <= 256)
      {   
        // LED0 - on, LED1 - off, LED2 - off, LED3 - off 
       SIU.GPDO[9].R = 0 ;   // LED0 
       SIU.GPDO[42].R = 1;    // LED1 
       SIU.GPDO[13].R = 1;   // LED2 
       SIU.GPDO[12].R = 1;    // LED3
      }
 
else if(value > 256 && value <= 512)
      {  
        // LED0 - on, LED1 - on, LED2 - off, LED3 - off 
       SIU.GPDO[9].R = 0 ;   // LED0 
       SIU.GPDO[42].R = 0;    // LED1 
       SIU.GPDO[13].R = 1;   // LED2 
       SIU.GPDO[12].R = 1;    // LED3
      }

else if(value > 512 && value <= 768)
      {  
        // LED0 - on, LED1 - on, LED2 - on, LED3 - off 
       SIU.GPDO[9].R = 0 ;   // LED0
       SIU.GPDO[42].R = 0;    // LED1 
       SIU.GPDO[13].R = 0;   // LED2
       SIU.GPDO[12].R = 1;    // LED3
      }    
else
      {  
        // LED0 - on, LED1 - on, LED2 - on, LED3 - on 
        SIU.GPDO[9].R = 0 ;   // LED0 
        SIU.GPDO[42].R = 0;    // LED1
        SIU.GPDO[13].R = 0;   // LED2 
        SIU.GPDO[12].R = 0;    //LED3 
      } 
  
// Task2.3  
 /* 
if(value <= 205)
    {   
    // LED0 - on, LED1 - off, LED2 - off, LED3 - off
       SIU.GPDO[9].R = 0 ;   //LED0 
       SIU.GPDO[42].R = 0;    // LED1 
       SIU.GPDO[13].R = 0;   //LED2 
       SIU.GPDO[12].R = 0;    // LED3
       SIU.GPDO[62].R = 0;  // LED4
  }

else if(value > 205 && value <= 410)
      {  
        // LED0 - on, LED1 - on, LED2 - off, LED3 - off
       SIU.GPDO[9].R = 0;   //LED0 
       SIU.GPDO[42].R = 0;    // LED1 
       SIU.GPDO[13].R = 0;   // LED2 
       SIU.GPDO[12].R = 0;    //LED3 
       SIU.GPDO[62].R = 1;  // LED4 
      }
else if(value > 410 && value <= 615)
      {  
        // LED0 - on, LED1 - on, LED2 - on, LED3 - off 
       SIU.GPDO[9].R = 0;   // LED0 
       SIU.GPDO[42].R = 0;    // LED1 
       SIU.GPDO[13].R = 0;   // LED2 
       SIU.GPDO[12].R = 1;    // LED3 
       SIU.GPDO[62].R = 1;  // LED4
      }    
else if(value > 615 && value <= 820)
      {  
        // LED0 - on, LED1 - on, LED2 - on, LED3 - off 
        SIU.GPDO[9].R = 0 ;   //LED0 
        SIU.GPDO[42].R = 0;    //LED1 
        SIU.GPDO[13].R = 1;   // LED2 
        SIU.GPDO[12].R = 1;    // LED3 
        SIU.GPDO[62].R = 1;  // LED4 
      }    
else
      {  
        // LED0 - on, LED1 - off, LED2 - off, LED3 - on 
        SIU.GPDO[9].R = 0;   //LED0 
        SIU.GPDO[42].R = 1;    //LED1
        SIU.GPDO[13].R = 1;   //LED2 
        SIU.GPDO[12].R = 1;    //LED3 
        SIU.GPDO[62].R = 1;  //LED4 
      }
  */
  
}

/********************************************************************
 *                      Interrupt Functions                         *
 *                    _____  ___  ___   ___                         *
 *                   |_   _|/ _ \|   \ / _ \                        *
 *                     | | | (_) | |) | (_) |                       *
 *                     |_|  \___/|___/ \___/                        *
 *                                                                  *
 *                Interrupts can be handled below.                  *
 ********************************************************************/  
void PITCHANNEL0() {
    /* clear flag */
    PIT.CH[0].TFLG.B.TIF = 1;
    SIU.GPDO[11].R = ~SIU.GPDO[11].R;  // Toggeling LED 7
}

void PITCHANNEL1() {
    /* clear flag */
    PIT.CH[1].TFLG.B.TIF = 1;
}

/********************************************************************
 *                   Interrupt Vector Table                         *
 *                                                                  *
 *                 Don't touch anything below!                      *
 ********************************************************************/
#pragma interrupt Ext_Isr
#pragma section IrqSect RX address=0x040
#pragma use_section IrqSect Ext_Isr

void Ext_Isr() {
    switch(INTC.IACKR.B.INTVEC)
    {
        case 59:
            /* Timer Interrupt */
            PITCHANNEL0();
            break;
        case 60:
            /* Timer Interrupt */
            PITCHANNEL1();
            break;            
        default:
            break;
    }
    /* End of Interrupt Request */
    INTC.EOIR.R = 0x00000000;
}
