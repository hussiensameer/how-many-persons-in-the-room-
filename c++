#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int IR1 = 4; // IR Sensor 1
int IR2 = 7; // IR Sensor 2
int Slot = 10;      //Enter Total number of parking Slots
int flag1 = 0;
int flag2 = 0;
constexpr uint8_t greenLed = 5;
void setup()
{
    pinMode(greenLed, OUTPUT);
  lcd.begin();   // LCD screen
  lcd.backlight();
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);

lcd.setCursor (0,0);
lcd.print("10 person in the");
lcd.setCursor (0,1);
lcd.print("room SYSTEM ");
delay (2000);
lcd.clear();
}
void loop(){
if(digitalRead (IR1) == LOW && flag1==0){
if(Slot>0){flag1=1;
if(flag2==0){ Slot = Slot-1;}
}else{
lcd.setCursor (0,0);
lcd.print("  SORRY   ");
lcd.setCursor (0,1);
lcd.print(" the room is full ");
digitalWrite(greenLed, HIGH);
delay(3000);
digitalWrite(greenLed, LOW);
delay (3000);
lcd.clear();
}
}
if(digitalRead (IR2) == LOW && flag2==0){flag2=1;
if(flag1==0){ Slot = Slot+1;if(Slot>10){Slot=10;};}
}
if(flag1==1 && flag2==1){
delay (1000);
flag1=0, flag2=0;
}
lcd.setCursor (0,0);
lcd.print("there's spase    ");
lcd.setCursor (0,1);
lcd.print("for: ");
lcd.print(Slot);
}
