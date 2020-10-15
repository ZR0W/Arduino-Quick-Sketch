#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char special;

String eyes[3] = {"|O   O|", "|-   -|", "#^   ^#"}; 
String mouth[3] = {"---", "---", " . "};

int inPin = 7;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

int blinkInterval = 500;
unsigned long previousMillis = 0;

void setup() {
  special = 0x1100;
  // set up the LCD's number of columns and rows:
  pinMode(inPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  stateChangeDetection();
  blink();
  lcd.setCursor(0,0);
  lcd.print(special);
}

void showFace(int n) {
//  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print(eyes[n]);
  lcd.setCursor(7,1);
  lcd.print(mouth[n]);
}

bool stateChangeDetection() {
  // read the pushbutton input pin:
  buttonState = digitalRead(inPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      lastButtonState = buttonState;

      special += 1;
      Serial.println(special);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
      lastButtonState = buttonState;


    }
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
}

void blink() {
  showFace(1);
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= blinkInterval) {
    
    showFace(0);
  }
  
  delay(500);
}
