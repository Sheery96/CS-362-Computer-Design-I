
#include <Time.h>  // include Time
#include <TimeLib.h> // Include Time.h
#include <LiquidCrystal.h> // IncludeCrystal


// CS-362 Lab 6 ///
// Name: Fnu Nousheerwan //
// Netid: fnoush2 //
// UIN: 659029851 //

// ------------------------------------ Lab Description --------------------------------------------

// Description: 
// • Printing a prompt on the serial monitor,
// • Getting input of date and time from user via the serial monitor
// • Includes error checking for input that doesn't make sense (hours not in range of 0 to 23,
//   Minutes not in range 0 to 59, month not range of 1 to 12, etc). Giving error messages to
//   the 16x2 display
// • setting the Arduino to contain the (valid) date and time entered by the user.
// • Displaying Arduino’s date and time on the 16x2 display
// • Keeping an accurate (continually updating) date and time shown on 16x2 display



// References on Serial:
// https://www.arduino.cc/reference/en/language/functions/communication/serial/
// https://www.arduino.cc/reference/en/language/functions/communication/serial/available/
// https://www.arduino.cc/reference/en/language/functions/communication/serial/read/
// https://www.arduino.cc/reference/en/language/functions/communication/serial/readbytesuntil/
// Date/Time library:
//  • You may need to install the Time Library: https://www.arduino.cc/en/Guide/Libraries
//  • Time Library Discussion: http://playground.arduino.cc/Code/Time
//  • Another Time Library: https://www.arduino.cc/en/Reference/CurieTime
//  Updated Time library:
//  Github : https://github.com/PaulStoffregen/Time
//  Using the library : http://www.pjrc.com/teensy/td_libs_Time.html



//--------------Variables used for time-----------
int Hours;
int Minutes;
int Seconds;
//--------------Variables used for date----------
int months;
int years;
int days;
const int rs = 12, en = 11, d4 =5, d5 =4, d6=3, d7=2;
//-------------Ask for user input ----------------
String Date = "Enter Date : MM/DD/YYYY."; // ask user for date
String Time = "Enter Time : HH:MM:SS."; // ask user for time


String givenDate;
String givenTime;

// define crystal
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);

// setup function below
  void setup()
  {

    LCD.begin(16, 2);
    Serial.begin(9660);

  }

// used for checking if time is within the range
void checkTime(String input){

      String hours, minutes, seconds;
      hours = input.substring(0, input.indexOf(":"));
      minutes = input.substring(5, input.indexOf(":") + 1);
      seconds = input.substring(6);


      Hours = hours.toInt();
      Minutes = minutes.toInt();
      Seconds = seconds.toInt();

    if ((Hours < 0) || (Hours > 23) || (Minutes < 0) || (Minutes > 59) || (Seconds < 0) || (Seconds > 59))
    {

      Serial.println("Not within the range. Try Again !");
      Serial.println(Time);

      while (1)
      {
        if (Serial.available() == 1){ break; }
      }

    if (Serial.available() == 1)
    {

      givenTime = Serial.readString();

      checkTime(givenTime); 
      Serial.print(Hours);
      Serial.print(":");
      Serial.print(Minutes);
      Serial.print(":");
      Serial.println(Seconds);
     }
   }
  }


//---- clock function -----------------------------
void clock(){

      while (1)
      {

        time_t t = now();
        Serial.print(hour(t));
        Serial.print(minute(t));
        Serial.print(second(t));
        Serial.println();
        Serial.println(day(t));
        Serial.println(month(t));
        Serial.println(year(t));

        delay(1000);

        LCD.clear();
        printDate(month(t), day(t), year(t));
        printTime(hour(t), minute(t), second(t));
    }
}

void loop(){
  
    Serial.println(Date);
   
    while (1)
    {
      if (Serial.available() == 1){ break;
      }
    }
    
    if (Serial.available() == 1)
     {

      givenDate = Serial.readString();
      int length = givenDate.length();
      checkDate(givenDate);
      Serial.println(givenDate);
      // error checking for long input
      if (length > 10){ Serial.println("Not Real Date, Try Again"); }
    }
    // calls print function
    Serial.println(Time);


    while (1)
    {
      if (Serial.available() == 1){ break;}
    }


if (Serial.available() == 1)
{

givenTime = Serial.readString();
// calls check time function
checkTime(givenTime);
setTime(Hours, Minutes, Seconds, days, months, years);
// calls clock function
clock();

//print hours
Serial.print(Hours);
Serial.print(":"); // print :

Serial.print(Minutes); // print minutes
Serial.print(":"); // print :

Serial.println(Seconds); // print seconds
  }

}

//------------ Below is function used for checking the date
void checkDate(String Date)

{

String month, DAY, year;
month = Date.substring(0, Date.indexOf("/"));
months = month.toInt();
DAY = Date.substring(5, Date.indexOf("/") + 1);
days = DAY.toInt();
year = Date.substring(6);
years = year.toInt();


if ((months > 12) || (months < 1))
{
Serial.println("Not In Range. Try Again! ");
loop();
}

else if ((months == 4) || (months == 6) || (months == 9) || (months == 11))
{
if ((days > 30) || (days < 1))
{

Serial.println("Not In Range. Try Again!");
loop();
  }

}

else if ((months == 1) || (months == 3) || (months == 5) || (months == 7) || (months == 8) || (months == 10) || (months == 12))
{
if ((days > 31) || (days < 1))
{

  Serial.println("Not In Range. Try Again!");
  loop();
        }
  }
   else if (years % 4 == 0)
{


if (months == 2)
    {
if (days > 29)
{

  Serial.println("Not In Range. Try Again! ");
  loop();
        }
    }
}

else if (months == 2)
{
if (days > 28)
{

  Serial.println("Not In Range. Try Again! ");
  loop();

          }

    }

}




//--------------------Function used for printing

void printDate(int month, int day, int year)
{

LCD.setCursor(10, 0);
LCD.print(year);
LCD.setCursor(9, 0);
LCD.print("/");

LCD.setCursor(7, 0);
LCD.print(day);

LCD.setCursor(5, 0);
LCD.print("/");

LCD.setCursor(3, 0);
LCD.print(month);

}


void printTime(int hour, int minute, int second)
{

LCD.setCursor(10, 1);
if (second < 10){ LCD.print("0"); }


LCD.print(second);
LCD.setCursor(9, 1);
LCD.print(":");


LCD.setCursor(7, 1);
LCD.print(minute);
LCD.setCursor(5, 1);

LCD.print(":");
LCD.setCursor(3, 1);
LCD.print(hour);

}
