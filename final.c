#include <Servo.h>

#include <Servo.h>

Servo tap_servo;

int rainsensor_pin = 9;            //4
int tap_servo_pin =10;             //5
int rainsensor_digital_value;



int trig=2;
int echo=4;
#define led 11
byte pump1 = 12;

long timeInMicro;

long distanceInCm;

void setup()
{
  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(4,INPUT);

  pinMode(rainsensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);

  while (!Serial);
  pinMode(pump1, OUTPUT);
  pinMode(led,OUTPUT);
}

void loop()  
{
 rainsensor_digital_value = digitalRead(rainsensor_pin);

 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);

 timeInMicro= pulseIn(echo,HIGH);

 distanceInCm = ((timeInMicro/29)/2);

 Serial.println(distanceInCm);
 delay(100);
 

 
  if (rainsensor_digital_value==1){
    tap_servo.write(180);      // gate off

  }

  if (rainsensor_digital_value==0 ){
    tap_servo.write(0);       // gate open
  }



  if (rainsensor_digital_value==1 &&  distanceInCm >=4){
    tap_servo.write(180);      // gate off
    digitalWrite(pump1, LOW); // pump1 activated   //
    digitalWrite(led, HIGH);  // light activated
  }

  else if (rainsensor_digital_value==1 &&  distanceInCm <3){
    tap_servo.write(180);       // gate off       
    digitalWrite(pump1, HIGH); // pump1 deactivated
    digitalWrite(led,LOW);     // light deactivate
  }

  if (rainsensor_digital_value==0 &&  distanceInCm >=4){
    tap_servo.write(0);   // gate open
    digitalWrite(pump1, LOW); // pump1 activated
    digitalWrite(led, HIGH);  // light activated
   
  }
  else if (rainsensor_digital_value==0 &&  distanceInCm <3){
    tap_servo.write(0);   // gate open
    digitalWrite(pump1, HIGH); // pump1 deactivated
    digitalWrite(led,LOW);     // light deactivate
  }
 
 

}
