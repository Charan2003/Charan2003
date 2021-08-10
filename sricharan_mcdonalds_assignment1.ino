#include <Servo.h>
#include<IRremote.h>
Servo servo_1;
Servo servo_2;
int servo_1signal=7;
int servo_2signal=6;
int led_r =5;
int led_g=4;
int led_y=3;
int led_b=2;
int ir_1=11;
IRrecv irrecv(ir_1);
decode_results results;
int us_1=13;
int us_2=8;
float ir1read;
float ir2read;
float ir3read;
float ir4read;
int DistanceFromTheEntryGate;
int DistanceFromTheExitGate;
long distanceFromTheus (int triggerpin,int echopin)

{pinMode(triggerpin,OUTPUT);
 digitalWrite(us_1,LOW);
 delayMicroseconds(2);
 digitalWrite(us_1,HIGH);
 delayMicroseconds(10);
 digitalWrite(us_1,LOW);
 return pulseIn(us_1,HIGH);
 digitalWrite(triggerpin,OUTPUT);
 
 digitalWrite(us_2,LOW);
 delayMicroseconds(2);
 digitalWrite(us_2,HIGH);
 delayMicroseconds(10);
 digitalWrite(us_2,LOW);
 return pulseIn(us_2,HIGH);
 
 
 
 
 }
  

 
 

void setup()
{ Serial.begin(9600);
 servo_1.attach(servo_1signal);
 servo_2.attach(servo_2signal);
 pinMode(led_r,OUTPUT);
 pinMode(led_b,OUTPUT);
 pinMode(led_g,OUTPUT);
 pinMode(led_y,OUTPUT);
 irrecv.enableIRIn();
 
 }

void loop()
{ DistanceFromTheEntryGate = 0.01723*distanceFromTheus(13,13);
  servo_1.write(0);
  servo_2.write(0);
 while (DistanceFromTheEntryGate>60) {}
   if (DistanceFromTheEntryGate<=60) {
   servo_1.write(0);
   servo_2.write(0);
   delay(1000);
   servo_1.write(90);
   delay(1000);
   servo_1.write(0);
   delay(1000);
   
   }
 else if (DistanceFromTheEntryGate>60) {
   servo_1.write(0);
   servo_2.write(0);
 }
 if(irrecv.decode(&results)) {
       Serial.println("PLEASE ENTER THE ITEM NUMBER");
  Serial.println("ALSO,IF MORE THAN ONE ITEM IS REQUIRED THEN YOU CAN ENTER THE REQUIRED MENU ITEM NUMBERS ONE AFTER THE OTHER");
  Serial.println("FOR EXAMPLE,IF YOU WANT TO SELECT ITEM 1 AND ITEM 3,FIRST YOU SHOULD WAVE YOUR HAND IN FRONT ANY ITEM EITHER 1 OR 3 AND THEN THE OTHER CAN BE SELECTED BY WAVING YOUR HAND AGAIN");
      unsigned int value=results.value ; 
     Serial.println(value);
       switch (value) {
      case 2295: 
      	digitalWrite(led_r, HIGH);
      	delay(500);
      	digitalWrite(led_r, LOW);
      	break;
      
      case 34935:
      	digitalWrite(led_g, HIGH);
      	delay(500);
      	digitalWrite(led_g, LOW);
      	break;
      
      case 18615:
      	digitalWrite(led_y, HIGH);
      	delay(500);
      	digitalWrite(led_y, LOW);
      	break;
      
      case 10455:
      	digitalWrite(led_b, HIGH);
      	delay(500);
      	digitalWrite(led_b, LOW);
    }
      irrecv.resume();
       }
         
  
   DistanceFromTheEntryGate = 0.01723*distanceFromTheus(13,13);
  servo_1.write(0);
  servo_2.write(0);
 while (DistanceFromTheExitGate>60) {}
   if (DistanceFromTheExitGate<=60) {
   servo_1.write(0);
   servo_2.write(0);
   delay(1000);
   servo_2.write(90);
   delay(1000);
   servo_2.write(0);
   delay(1000);
   
   }
 else if (DistanceFromTheExitGate>60) {
   servo_1.write(0);
   servo_2.write(0);
 }
                               
} 
 
 
  
  
    
  
  
  
  

