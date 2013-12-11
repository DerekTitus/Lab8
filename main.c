#include <msp430.h> 
#include "MoveBot.h"
#include "RobotSensors.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
//    P1DIR |= BIT0|BIT6;
//    P1OUT &= ~(BIT0|BIT6);
    initSensors();
    initMotors();


    while(1)
        {

        	initLeftSensor();
        	if (initLeftSensor() >= 0x250){
        		MoveSmallRight();
        	}
        	else{
        		MoveForward();
        	}
        	initLeftSensor();
        	if (initLeftSensor() <= 0x270){
        		MoveSmallLeft();
        	}
        	else{
        		MoveForward();
        	}

        	initCenterSensor();
        	if (initCenterSensor() >= 0x300){
        		StopBot();
        		ShortDelay();
        		TurnRight();
        		ShortDelay();
        	}
        	else{
        		MoveForward();
        	}
        	}






	return 0;
}
