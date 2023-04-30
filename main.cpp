//This program prints multiple times the position of the joystick.
//The while loop does not stop with a joystick push but continues
//printing the joystick position on every loop as long as the joystick is pushed


#include "mbed.h"       //add mbed library

Serial pc(USBTX, USBRX);  //TX RX for terminal

InterruptIn d(p12);    //assigns down to pin 12 as d 
InterruptIn l(p13);    //assigns left to pin 13 as l
InterruptIn u(p15);    //assigns up to pin 14 as u
InterruptIn r(p16);    //assigns r to pin 16 as r

int main() {    //main function 
    while(1) {      //start while loop 
        if (d == 1) {           //if down is pressed start if loop
                printf("Joystick Down \r\n");   //print joystick down
        }                       //end if loop
        else if (l == 1) {      //start else if loop if left is pressed  
            printf("Joystick Left \r\n");       //print joystick left
        }                       //end of else if loop
        else if (u == 1) {      //start else if loop if up is pressed 
            printf("Joystick Up \r\n");         //print joystick up
        }                       ////end of else if loop
        else if (r == 1) {      //start else if loop if right is pressed 
            printf("Joystick Right \r\n");      //print joystick right
        }                       //end of else if loop
    }
}