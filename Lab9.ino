// CS-362 Lab 9 ///
// Name: Fnu Nousheerwan //
// Netid: fnoush2 //
// UIN: 659029851 //

//*******************************************************************************************
// ----------------------------------- Lab 9 Description ------------------------------------
// Connect two analog devices to the arduino and plot the data received on the computer using
// processing.
// Data could be displayed in two separate graphs or both on one graph.
// Some analog devices that you might already have include:
//   • potentiometer
//   • photo resistor

// ---------------------------------- Lab 9 Description -------------------------------------
//*******************************************************************************************


// *********** Reference *****************
//  http://www.arduino.cc/en/Tutorial/Graph

// *********** Reference *****************


void setup() {
  // initializing the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:
  Serial.println(analogRead(A0));
  delay(15);

  // Reading in the second analog value
   Serial.println(analogRead(A1));
   delay(15);

  
}
