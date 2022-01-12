#include <Wire.h> 
#include <Servo.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>


hd44780_I2Cexp lcd;
Servo servo; 
void setup(){ 
  Serial.begin(9600);
  servo.attach(7);
    // initialize the LCD
  lcd.begin(16, 2);

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
  } 
void loop(){ 
  int humidity = map(analogRead(A1), 0, 1023, 100, 0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("humidity : ");
  lcd.print(humidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  if( humidity <= 35){
    servo.write(10);
    lcd.print("GIVE ME WATER");
  }else{
    servo.write(90);
    lcd.print("I'm OK");
  }
  delay(1000); 
}
