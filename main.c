/*
 * File:   main.c
 * Author: nagay
 *
 * Created on April 17, 2020, 1:50 AM
 */


#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include "DIO.h"
#include "lcd.h"

#define  BUTTON0         0 //port B
#define  BUTTON1         4 //port B
#define  BUTTON2         2 //port D

#define  LED0            2 //port C
#define  LED1            7 //port C
#define  LED2            3 //port D

#define portA            1
#define portB            2
#define portC            3
#define portD            4

int main(void) {
    PINBas(BUTTON0,IN);//set pin in port B as input
   // PINBas(BUTTON1,IN);
   // PINDas(BUTTON2,IN);
    
    PINCas(LED0,OUT);//set pin in port C as output
    PINCas(LED1,OUT);
    PINDas(LED2,OUT);
    
    int data=1;
    int flag=0;
    int temp=0;
    //setPIN(LED0,portC);
    while (1) {
        
        if(isPressedB(BUTTON0))
        {
            while(isPressedB(BUTTON0)){}
            if (flag>=0&& temp==0&& flag!=3)
            {
                flag++;
            }
            else 
            {
                temp=1;
            }
            
           if (flag<=3 && temp==1 && flag!=1)
           {
               flag--;  
           }
  
            if(flag==1&& temp==1)
            {
                temp=0;
            }
            
        }
        
        if (flag==1)
            {
            setPIN(LED0,portC);
            resetPIN(LED1,portC);
            resetPIN(LED2,portD);
            } 
        else if (flag==2)
            {
            resetPIN(LED0,portC);
            setPIN(LED1,portC);
            resetPIN(LED2,portD);
            } 
        else if (flag==3)
            {
            resetPIN(LED0,portC);
            resetPIN(LED1,portC);
            setPIN(LED2,portD);
            } 
    }
}
