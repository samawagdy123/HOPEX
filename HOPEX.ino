#include <ESP32Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,16,21,3,1,22);

#define ECHO_PIN 2
#define TRIG_PIN 15

#define ECHO_PIN2 16
#define TRIG_PIN2 4

const int servopin1 = 33;
const int servopin2 = 25;

Servo servo1;
Servo servo2;

int8_t counter = 0;
int8_t points= 0;
float distance;
float distance2 ;
void setup() {
  lcd.begin(16, 2);
  lcd.print("HOPEX");
  delay(3000);
  lcd.setCursor(2, 1);
  lcd.print("HELLO!");
  delay(3000);
  lcd.clear();
  lcd.blink();
  delay(2000);
  lcd.noBlink();
  delay(2000);
  lcd.clear();
  servo1.attach(servopin1, 500, 2400);
  servo2.attach(servopin2, 500, 2400);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
}
void Counter(int x){
   
  lcd.print("num of waste");
  lcd.setCursor(15, 1);
  lcd.print(counter);
  delay(2000);
  lcd.clear();
  points =counter*x;
  lcd.print("your points :");
  lcd.print(points);
  delay(2000);
  lcd.clear();
 
}

float readDistanceCMcans() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

float readDistanceCMbottels() {
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  int duration = pulseIn(ECHO_PIN2, HIGH);
  return duration * 0.034 / 2;
}
int pos = 0;

void loop() {
distance = readDistanceCMcans();
   if(distance <= 4){
    for (pos = 0; pos <= 90; pos += 1) {
      servo1.write(pos);
      delay(150);

      
    }
    counter = counter+1;
    lcd.clear();
    Counter(5);
    delay(1000);

  for (pos = 90; pos >= 0; pos -= 1) {
    servo1.write(pos);
    delay(150); }
  }

float distance2 = readDistanceCMbottels();
   if(distance <= 4){
    for (pos = 0; pos <= 90; pos += 1) {
      servo1.write(pos);
      delay(150);
      }
    counter = counter+1;
    lcd.clear();
    Counter(5);
    delay(1000);

  for (pos = 90; pos >= 0; pos -= 1) {
    servo1.write(pos);
    delay(150);
     }
     }
  }