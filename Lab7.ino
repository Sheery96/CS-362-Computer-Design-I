// FirstName LastName - UIN
// Fnu Nousheerwan, Syed A Ayyaz - fnoush2, sayaz3
// UIN: 659920405
// Lab 7 - Arduino 2 Arduiono communicatuons
//
//Be able to have two arduinos communicate with eachother
//work with a partner, or if you have two arduino devices you can work alone
//connect two arduino's via a hardwired serial connection (no usb cable) (digital pins 0 and 1)
//connect a button and an external LED to each device
//pressing the button on one arduino should cause the other arduino's LED to change state (on to off, or off to on)
//Button press on one arduino should toggle the state of the LED on the other (on/off) and not keep the LED lit while being pressed
//refer to lab 6 for all the info about serial communication and lab2 for maintaining led states with button presses .
// 
//
//Hints:
//
//Both boards have to share the same ground in order for the serial communication to work properly
//
//
// ========================================================================================
// defining the LED's


#define Button 8//define pins
#define LED 13


int ledState = 0;//states to enable toggling
int prev_state = 0;


void sendData()
{
  int current_state = digitalRead(Button);  
  
  if(current_state != prev_state){            
    if(current_state) Serial.write(1);       // and the button is pressed down send out signal
    prev_state = current_state;               // update previous state
  }
}

void getData(){
  if(Serial.available() > 0){           // check data is recieved
    if(Serial.read()){                  // read the information that was sent
      ledState = !ledState;                   // if on turn off / if off turn on
      if(ledState) {
        digitalWrite(LED, HIGH);
      }
      else   {
        digitalWrite(LED, LOW);
      }
    }
  }
}
// set up led and Serial monitor which will be usedive information 
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  sendData();  
  getData();
  delay(1);
}
