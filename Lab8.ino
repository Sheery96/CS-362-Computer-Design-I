// FirstName LastName - UIN
// Fnu Nousheerwan - fnoush2
// UIN: 659920405
// Lab 8 - Interrupts
// Learn how to program with intetrupts
// Program for the arduino that utilizes interrupts. When no button is pressed 16x2 displays "We have been waiting for X seconds", 
// where X will be updated as time goes on
// When the first button is pressed, the display should display “Interrupt received! Press button 2 to continue” State 1
// When the user presses button 2 the display goes back to displaying "We have been waiting for X seconds", and restarts the time a 0 seconds.
//
// Information about how to tell the system to call your Interrupt Service Routine (ISR) can be found at 
//
// http://arduino.cc/en/Reference/attachInterrupt
//
// Information about timer:
//
// https://www.arduino.cc/en/Reference/Millis
//
// Note: using pin two and three for this.


/////////////////////// Libraries ////////////////////////

// define Wire.h
#include <string.h>
#include <Wire.h> 

// define LiquidCrystal.h

#include <LiquidCrystal.h>

// define all the pins

//////////////////////////////////////////////////////////


///////////////// LCD and Buttons //////////////////////


LiquidCrystal LCD(13, 12, 7, 6, 5, 4);

// define button 1 and 2 
int button1 = 2;
int button2 = 3;
int time = 0;


/////////////////////////////////////////////////////////


// -------------------------------- setup ---------------------------------

// void setup used for setting up the 
// LCD both lines 
// define the button and interrupt


void setup() 
{
 LCD.begin(16, 2);
 pinMode(button1, INPUT);
 pinMode(button2, INPUT);
 attachInterrupt(digitalPinToInterrupt(button1), helper_func, RISING);

}

// ------------------------------- setup -----------------------------------




// --------------------------- loop ---------------------------------------

// void loop used for running the code
// sets the cursor , prints the message 
// Also prints the time in seconds 

void loop() 
{
 LCD.setCursor(0, 0);
 LCD.print("Waiting..");
 LCD.print(time);
 LCD.print(" seconds");
 delay(1000);
 ++time;
}


// ---------------------------- loop ---------------------------------------



// -------------------------- Helper Function ------------------------------

// helper_func used for setting the start point
// defines the clear in order to print the time
// prints the message
// sets the cursor
// runs the while loop while button 2 is not pressed
// sets time to zero

void helper_func() 
{
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Interrupt! Press");
  LCD.setCursor(0, 1);
  LCD.print("button2 to continue");
  while(!digitalRead(button2))
  time = 0;
  LCD.clear();
  
}

// ----------------------------- Helper Function -----------------------------

