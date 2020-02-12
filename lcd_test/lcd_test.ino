#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
const int buttonPin = 11;
int buttonCounter = 0;
int buttonState = 0;
int bPressed = 0;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display.  

void setup() {

  Serial.begin(9600);
  lcd.init();
lcd.backlight();
pinMode(11,INPUT);
}
void loop() {
 //lcd setcursor(0,0);
  lcd.print("Button Pressed");
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  
  lcd.setCursor(0, 0);
  lcd.print(millis() / 1000);
  Serial.println(digitalRead(11));
}