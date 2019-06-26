// CS-362 Lab 3 ///
// Name: Fnu Nousheerwan //
// Netid: fnoush2 //
// UIN: 659029851 //
// Description: Displaying the name and favorite quote on the 16x2 display, name on first line and quote on
//the second line. The quote does not fits on the screen and scrolls across the screen. Name 
// does not scroll across the screen, only the quote scrolls.

// Reference: Arduino link mentioned in the lab handout.

#include <LiquidCrystal.h>

// ---- Initializing the required pins of the LCD and the arduino board.--------

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// ------------------------------------------------------------------------------


// ----- Initializing the required variables to print out the name and the quote

String myName = "  Nousheerwan", sub_String[11];
int string_Length = 0, i = 0, set_Delay = 250, Lcd_width = 11;

// -------------------------------------------------------------------------------



void setup() {
  // ---- Setting up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  delay(1000);
}


void loop() {
	
  // ------ The required quote	
  display_content(1, "Keep your friends close, but enemies closer ");
}

// ------- Making a display_content function to output the content on the LCD

void display_content(int l, String str) 
{
  string_Length = str.length();
  
  for (i = Lcd_width; i >= 0; i--)
  {
	  
    lcd.setCursor(0, l - 1); // Setting the cursor
    lcd.print(myName); // Printing the name
    lcd.setCursor(i, l);
    lcd.print(str.substring(0, 16));
    delay(set_Delay); // Setting the delay
  }
  
   // ---------- A loop for displaying the quotation 

  for (int j=0 ; j!= string_Length;)
  {
    j++;
    lcd.setCursor(0, l); // Setting the cursor
    lcd.print(str.substring(j,j+16)); // Printing the quote
    delay(set_Delay); // Setting the delay
  }
  
}

// ---------------------------------------------------------------------------------
