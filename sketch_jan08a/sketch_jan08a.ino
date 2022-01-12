#include<Servo.h>
Servo servo;
int value = 0;
int pushButton = 4;
int realvalue = 0;
void setup()
{
  Serial.begin(9600); //시리얼 통신을 하기위한 통신속도설정
  pinMode(8, INPUT);
  pinMode(pushButton, INPUT_PULLUP);
  servo.attach(7);
}
void set_x_value(){
  realvalue = value;
  Serial.print(realvalue);
}
void loop(){
  if(analogRead(A1) <= 506){
    value = 0;
  }
  else {
    value = analogRead(A1) *0.1  - 40;
   }
  if(digitalRead(pushButton) == 1 ) servo.write(value);
  else set_x_value();
  Serial.println(digitalRead(pushButton));
  delay(100);
}
