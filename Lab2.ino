/// CS-362 Lab 2 ///
// Name: Fnu Nousheerwan //
// Netid: fnoush2 //
// UIN: 659029851 //

// Description: Use two push buttons and three LEDs for this circuit. The push buttons will change an internal 3-bit
// count. The LED’s will display the value of this internal 3-bit count.One push button will increment the 3-bit count. This is the “up button”
// The other push button should decrement the 3-bit count. This is the down button.
// The 3-bit count value will be displayed on the three LEDs in binary
// one LED per binary digit
// a binary digit of 1 is indicated when the LED is on

int count_pre = 0;
int count = 0;

int Led_1 = 13;
int Led_2 = 12;
int Led_3 = 8;

// Initilizing Button Pins and States

int Button_Pin = 2;
int Button_Pin2 = 4;
int Button_State = 0;
int Button_State2 = 0;

//-----------------------------------



//---------- Setup and Loop ---------

void setup() { 
   
  pinMode(Led_1,OUTPUT); 
  pinMode(Led_2,OUTPUT); 
  pinMode(Led_3,OUTPUT); 
 }

void loop() { 
  digitalWrite(Led_1, LOW); 
  digitalWrite(Led_2, LOW); 
  digitalWrite(Led_3, LOW); 
  

Button_State = digitalRead(Button_Pin);    // Reading in the button pin status
Button_State2 = digitalRead(Button_Pin2);

   
  
  if(Button_State == 1) // Checking Button press and states 
  {
    delay(50);  // Delay to counter bouncing off 
    
    Button_State = digitalRead(Button_Pin);
   
  
    if (Button_State == 0)
    {
    count = count_pre + 1; // Storing the previous state
    }
  }
  
  
  else if(Button_State2 == 1)
  {
    
    delay(50);
  
    Button_State2 = digitalRead(Button_Pin2);
    
  
    if (Button_State == 0)
    {
    count = count_pre - 1;
    }
  }
  
  else
  {
// ------------------------ Logic for Increment ----------------------------------    
   
    if((count % 2) > 0) 
    { 
   
      digitalWrite(Led_3, HIGH);
      count_pre = count; 
    } 
    else 
    { 
      digitalWrite(8, LOW); 
    }

    if((count % 4) > 1) 
    { 
      digitalWrite(Led_2, HIGH);
      count_pre = count; 
    } 
    else 
    { 
      digitalWrite(12, LOW); 
    }

    if((count % 8) > 3) 
    { 
    
      digitalWrite(Led_1, HIGH);
      count_pre = count; 
    } 
    else 
    { 
      digitalWrite(Led_1, LOW); 
    }
    
      delay(200);  
  
//--------------------------------------------------------------------------------------- 
  
// ------------------ Logic for Decrement ------------------------------  
  if(count == 8)
  {
    count_pre = 0;
  }
  
  if(count <= 0)
  {
    count_pre = 0;
    count = 0;
  }
  
      delay(200); 
 //----------------------------------------------------------------------- 
  
 }
 
}
