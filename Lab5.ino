// CS-362 Lab 5 ///
// Name: Fnu Nousheerwan //
// Netid: fnoush2 //
// UIN: 659029851 //

// ------------------------------------ Lab Description --------------------------------------------

// Description: 
// • Using 4 LEDS and a photoresistor. All 4 LEDs next to each other with same colors
//   As the amount of light seen by the photoresistor decreases, increase the number of LEDs
//   that are lit. For example, if your circuit receives no light then all of the LEDs should light up. As
//   you continue to increase the amount of light, the number of LEDs that light up will decrease. So
//   when the photoresistor receives the half the amount of light, 2 LEDS should be lit up, and when
//   there is no light, all 4 LEDs should be lit up.

// • In part 2 using the passive buzzer and the potentiometer. Using the
//   potentiometer as an analog input and have the output come from another analog pin. Controlling the
//   volume or tone of the buzzer by adjusting the potentiometer. 



// ------------ Initializing all the required pins and variables ------------------------------------

const int photo_resistor = A0;

const int Led_pin1 = 13;
const int Led_pin2 = 12;
const int Led_pin3 = 11;
const int Led_pin4 = 10;


int buzzer = 6;
int val_res;
int pin = 0, pot = 1,val;



// --------------------------------------------------------------------------------------------------



//-------------------- Setup funtion ----------------------------

void setup(){
	
  pinMode(Led_pin1,OUTPUT);
  pinMode(Led_pin2,OUTPUT);
  pinMode(Led_pin3,OUTPUT);
  pinMode(Led_pin4,OUTPUT);
	
}

// --------------------------------------------------------------



// --------------- Loop -----------------------------------------

void loop(){
	
	val_res = analogRead(photo_resistor); // Reading the value of the photo_resistor
	
	
	// --------------- Ranges setup according to the value received by the photo_resistor --------------------------------------
	
	if (val_res <= 204)
	{
	  digitalWrite(Led_pin1, HIGH); 
      digitalWrite(Led_pin2, HIGH); 
      digitalWrite(Led_pin3, HIGH); 
      digitalWrite(Led_pin4, HIGH);
	}
	
	
	else if (val_res >= 204 && val_res <= 408)
	{
	  digitalWrite(Led_pin1, HIGH); 
      digitalWrite(Led_pin2, HIGH); 
      digitalWrite(Led_pin3, HIGH); 
      digitalWrite(Led_pin4, LOW);
	}
	
	else if (val_res >= 408 && val_res <= 612)
	{
	  digitalWrite(Led_pin1, HIGH); 
      digitalWrite(Led_pin2, HIGH); 
      digitalWrite(Led_pin3, LOW); 
      digitalWrite(Led_pin4, LOW);
	}
	
	else if (val_res >= 612 && val_res <= 812)
	{
	  digitalWrite(Led_pin1, HIGH); 
      digitalWrite(Led_pin2, LOW); 
      digitalWrite(Led_pin3, LOW); 
      digitalWrite(Led_pin4, LOW);
	}
	
	else
	{
	  digitalWrite(Led_pin1, LOW); 
      digitalWrite(Led_pin2, LOW); 
      digitalWrite(Led_pin3, LOW); 
      digitalWrite(Led_pin4, LOW);
		
	}
	
	// ---------------------------------------------------------------------------------------------------------------------------
	
	
	// ------------- Buzzer ----------------------
	
	val = analogRead(pot);

	//analogWrite
    analogWrite(6, val); 
	
	// -------------------------------------------

    //delay 10
    delay(10);
	
	
	
}
 // --------------------------------------------------------------------