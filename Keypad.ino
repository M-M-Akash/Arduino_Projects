#include <Keypad.h>

String mainPassword = "1234B";
String enterPassword;
String  newPasword;

bool reset;
bool access;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 11, 12, 13}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  reset = 0;
  access = 0;
}

void loop() {

  char ok = '#';

  char key = customKeypad.getKey();



  if (key) {  //1

    Serial.println(key);

    if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' ||
        key == 'A' || key == 'B' || key == 'C') {

      if (access == 0) {

        enterPassword += key;
      }
      else if ((access == 1) && (reset == 1)) {

        newPasword += key;
        mainPassword = newPasword ;
      }

    }
    //2
    else if (key == ok && reset == 0 && access == 0) {

      if (mainPassword == enterPassword ) {

        Serial.print("\n ok \n");
      }
      else {

        Serial.print("\n no ");
        Serial.print("\n please press => D and try again \n");

      }

    }
    //3
    else if (key == ok && mainPassword == enterPassword  && reset == 1 && access == 0) {

      access = 1;

      Serial.print("\n new password \n ");

    }
    //4
    else if (key == ok && newPasword == mainPassword && access == 1 ) {

      Serial.println(mainPassword);
      Serial.println("Done");
      newPasword = "";
      reset = 0;
      access = 0;

    }
    //5
    else if (key == 'D') {

      Serial.print("\n try again ");

      enterPassword = "";
      loop();

    }
    //6
    else if (key == '*') {

      Serial.print("\n reset ");
      reset = 1;
      Serial.print(reset);
      Serial.print("enter your old password \n");

    }

    else if(key == ok) {

      Serial.print("please press => D ");

    }

  }
}


