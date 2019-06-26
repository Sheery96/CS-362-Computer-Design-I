/// CS-362 Lab 1 ///
// Name: Fnu Nousheerwan //
// Netid: fnoush2 //
// UIN: 659029851 //

// Description: The code activates three different pins on the arduino 
// and then activates 3 led's with a unique sequence mentioned in the Lab 1 manual ///
// References: Used the references mentioned in the Lab manual and shown in Lecture ///


int pin1=13, pin2=12, pin3=7;
void setup(){
  // put your setup code here, to run once:
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
}

void loop() {

    // For the led on the Arduino 

  digitalWrite(pin1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  // For the red led ///

  // put your main code here, to run repeatedly:
  digitalWrite(pin3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  // For the green led ///

  digitalWrite(pin2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  
}
