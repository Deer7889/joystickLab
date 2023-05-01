//The final program uses the LCD for display and interrupts to hold 
//the joystick button pressed messages on the screen until the 
//button is released.
//The program now prints only one line while the joystick buttons are pressed

#include "mbed.h"       //mbed library
#include "C12832.h"     //lcd library

C12832 lcd(p5, p7, p6, p8, p11);  //define lcd and pins

InterruptIn d(p12);     //assigns down to pin 12 as d 
InterruptIn l(p13);     //assigns left to pin 13 as l
InterruptIn u(p15);     //assigns up to pin 14 as u
InterruptIn r(p16);     //assigns r to pin 16 as r

void flipdp() {         //start void flip down press loop
    lcd.printf("Joystick Down\n");  //print joystick down 
}                       //end loop
void flipdr() {         //start void flip down release loop
       lcd.cls();       //clear lcd
}                       //end loop
void fliplp() {         //start void flip left press loop
    lcd.printf("Joystick Left\n");  //print joystick left
}                       //end loop
void fliplr() {         //start void flip left release loop
    lcd.cls();          //clear lcd
}                       //end loop
void flipup() {         //start void flip up press loop
    lcd.printf("Joystick Up\n");    //print joystick up
}                       //end loop
void flipur() {         //start void flip up release loop
    lcd.cls();          //clear lcd
}                       //end loop
void fliprp() {         //start void flip right press loop
    lcd.printf("Joystick Right\n"); //print joystick right
}                       //end loop
void fliprr() {         //start void flip right release loop
    lcd.cls();          //clear lcd
}                       //end loop

int main() {    //start main program

    d.rise(&flipdp);    //down joystick pressed rise signal
    d.fall(&flipdr);    //down joystick released
    l.rise(&fliplp);    //left joystick pressed rise signal
    l.fall(&fliplr);    //left joystick released
    u.rise(&flipup);    //up joystick pressed rise signal
    u.fall(&flipur);    //up joystick released
    r.rise(&fliprp);    //right joystick pressed rise signal
    r.fall(&fliprr);    //right joystick released

    while(1) {          // while loop start interrupts will interrupt this
       lcd.locate(0,0); //reset lcd location
        wait(0.02);     //debounce
    }               //close while loop
}               //end main program