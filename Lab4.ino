// CS-362 Lab 4 ///
// Name: Fnu Nousheerwan //
// Netid: fnoush2 //
// UIN: 659029851 //
// Description: Creating a circuit and program that will use a photoresistor and the 16x2 display. 
// It displays the relative amount of light in the room as one of 5 predefined text values based
// on the value read from the photocell. The 5 predefined values that is displays are:
// • dark
// • partially dark
// • medium
// • partially light
// • fully lit

// Reference: Arduino link mentioned in the lab handout.
#include <LiquidCrystal.h>  // include LCD

// ---- Setting the photo resistor ---------------------------------------------

const int photo_resistor = A0;


// -----------------------------------------------------------------------------

// ---- Initializing the required pins of the LCD and the arduino board.--------

const int rs = 12, en = 11, d4 = 5, d5 =4, d6 = 3, d7 =2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int val_res;


// -----------------------------------------------------------------------------


void setup() {
  
  lcd.begin(16,2); 
 
  Serial.begin(9600); 
}

void loop()
{
  val_res = analogRead(photo_resistor); // Value of the photo resistor
  
  Serial.println(val_res); // Printing the value
  
  lcd.clear(); // Clearing the lcd
  lcd.setCursor(0,0); // Setting the cursor
 
  
  
  // -------------- Reasonable Ranges for the values under consideration ------------------------
  
  // ----------- Dark ---------------------
  
  if(val_res < 205)
  {
    lcd.print("dark");
  
  }
  
  // --------------------------------------
  
  
  // ------- Partially Dark ---------------

  else if(val_res < 410) 
  {
    lcd.print("partially dark");
    
  }
  
  // ---------------------------------------
  
  
   // ------------- Medium -----------------

   else if(val_res < 615) 
  {
    lcd.print("medium");
    
  }
  
  // ---------------------------------------


  // ------------- Partially Light ---------

   else if(val_res < 820) 
  {
    lcd.print("partially light");
    
  }
  
   // --------------------------------------
   
   // ------------- Fully Lit -------------- 
   
   else 
   {
    lcd.print("fully lit");
   }
   
  // --------------------------------------------------------------------------------------------- 
   
  delay(200);
}
