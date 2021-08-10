#include<Servo.h>
Servo servo_1;
Servo servo_2;

int servos_1=6;
int servos_2=7;
int led_r=10;
int led_b=11;
int led_g=12;
int led_y=13;
int ir_1=2;
int ir_2=3;
int ir_3=4;
int ir_4=5;
int distanceFromgate;
int A_read=0;
int B_read=0;
int C_read=0;
int D_read=0;
int us_1=8;
int us_2=9;
int distanceFromexit;

long readUltrasonicDistance(int triggerpin, int echopin)
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
{
 Serial.begin(9600);
 servo_1.attach(servos_1); 
 servo_2.attach(servos_2);
 
  pinMode(ir_1, INPUT);
  pinMode(ir_2, INPUT);
  pinMode(ir_3, INPUT);
  pinMode(ir_4, INPUT);
 
}

void loop()
{
distanceFromgate = 0.01723 * readUltrasonicDistance(8, 8);
Serial.println(distanceFromgate);  
servo_2.write(0); 
servo_1.write(0);
  while(distanceFromgate>60){}
  if(distanceFromgate<=60){  
servo_2.write(0); 
servo_1.write(0); // moving the servo at 0 degree
delay(10);
servo_1.write(90);
delay(3000);
servo_1.write(0);
    delay(1000); }
  
  else if(distanceFromgate>60){
    servo_1.write(0);
    servo_2.write(0);
    }
  Serial.println("Please wave your hand over the item you would like to order");
  
     
A_read= digitalRead(ir_1);
  delay(5000);//THIS DELAY ALLOWS CUSTOMER TO WAVE HIS HAND BEFORE ANOTHER REQUIRED ITEM
B_read= digitalRead(ir_2);
  delay(5000);
C_read= digitalRead(ir_3);
  delay(5000);
D_read= digitalRead(ir_4);
 
  
      
      if(A_read== 1 && B_read==0 && C_read==0&& D_read==0){
      digitalWrite(led_r,HIGH);
        delay(1000);
      Serial.println("Item A ordered");
        digitalWrite(led_r,LOW);
       delay(1000); 
      }

    
      else if(A_read== 0 && B_read==1 && C_read==0&&D_read==0){
      digitalWrite(led_b,HIGH);
        delay(1000);
      Serial.println("Item B ordered");
       digitalWrite(led_b,LOW);
        delay(1000);
     
      }
    
      else if(A_read==0 && B_read==0 && C_read== 1 && D_read==0){
      digitalWrite(led_g,HIGH);
        delay(1000);
      Serial.println("Item C ordered");
        digitalWrite(led_g,LOW);
       delay(1000);
      }
    
      else if(A_read== 0 && B_read==0 && C_read==0 && D_read==1){
      digitalWrite(led_y,HIGH);
       delay(1000);
      Serial.println("Item D ordered");
       digitalWrite(led_y,HIGH);
      delay(1000);
      }
      else if(A_read== 1 && B_read==1 && C_read==0 && D_read==0){
      digitalWrite(led_r,HIGH);
      digitalWrite(led_b,HIGH);
       delay(1000);
      Serial.println("Item A and Item B are ordered");
       digitalWrite(led_r,LOW);
      digitalWrite(led_b,LOW);
      delay(1000);
      }
     else if(A_read== 1 && B_read==0 && C_read==1 && D_read==0){
      digitalWrite(led_r,HIGH);
       digitalWrite(led_g,HIGH);
       delay(1000);
      Serial.println("Item A and Item C are ordered");
       digitalWrite(led_r,LOW);
       digitalWrite(led_g,LOW);
         delay(1000);
      }
     else if(A_read== 1 && B_read==0 && C_read==0 && D_read==1){
      digitalWrite(led_r,HIGH);
      digitalWrite(led_y,HIGH);
       delay(1000);
      Serial.println("Item A and Item D are ordered");
       digitalWrite(led_r,LOW);
       digitalWrite(led_y,LOW);
      delay(1000);
      }
    else if(A_read==0 && B_read==1&& C_read==1 && D_read==0){
      digitalWrite(led_b,HIGH);
      digitalWrite(led_g,HIGH);
       delay(1000);
      Serial.println("Item B and Item C are ordered");
       digitalWrite(led_b,LOW);
       digitalWrite(led_g,LOW);
      delay(1000);
    }
   else if(A_read==0 && B_read==1&& C_read==0 && D_read==1){
      digitalWrite(led_b,HIGH);
      digitalWrite(led_y,HIGH);
       delay(1000);
      Serial.println("Item B and Item D are ordered");
       digitalWrite(led_b,LOW);
       digitalWrite(led_y,LOW);
     delay(1000);
    }
   else if(A_read==0 && B_read==0&& C_read==1 && D_read==1){
      digitalWrite(led_y,HIGH);
      digitalWrite(led_g,HIGH);
       delay(1000);
      Serial.println("Item C and Item D are ordered");
       digitalWrite(led_y,LOW);
       digitalWrite(led_g,LOW);
     delay(1000);
    }
  else if(A_read==1 && B_read==1 && C_read==1 && D_read==0){
    digitalWrite(led_r,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_g,HIGH);
     delay(1000);
    Serial.println("Item A,Item B and Item C are ordered");
    digitalWrite(led_r,LOW);
    digitalWrite(led_b,LOW);
    digitalWrite(led_g,LOW);
    delay(1000);
  }
  else if(A_read==1 && B_read==1 && C_read==0 && D_read==1){
    digitalWrite(led_r,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_y,HIGH);
     delay(1000);
    Serial.println("Item A,Item B and Item D are ordered");
    digitalWrite(led_r,LOW);
    digitalWrite(led_b,LOW);
    digitalWrite(led_y,LOW);
    delay(1000);
  }
  else if(A_read==1 && B_read==0 && C_read==1 && D_read==1){
    digitalWrite(led_r,HIGH);
    digitalWrite(led_g,HIGH);
    digitalWrite(led_y,HIGH);
     delay(1000);
    Serial.println("Item A,Item C and Item D are ordered");
    digitalWrite(led_r,LOW);
    digitalWrite(led_g,LOW);
    digitalWrite(led_y,LOW);
    delay(1000);
  }
  else if(A_read==0 && B_read==1 && C_read==1 && D_read==1){
    digitalWrite(led_g,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_y,HIGH);
     delay(1000);
    Serial.println("Item B,Item C and Item D are ordered");
    digitalWrite(led_g,LOW);
    digitalWrite(led_b,LOW);
    digitalWrite(led_y,LOW);
    delay(1000);
  }
  else if(A_read==1 && B_read==1 && C_read==1 && D_read==1){
    digitalWrite(led_r,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_g,HIGH);
    digitalWrite(led_y,HIGH);
     delay(1000);
    Serial.println("Item A,Item B and Item D are ordered");
    digitalWrite(led_r,LOW);
    digitalWrite(led_b,LOW);
    digitalWrite(led_g,LOW);
    digitalWrite(led_y,LOW);
    delay(1000);
  }
  delay(3000);
  
  distanceFromexit = 0.01723 * readUltrasonicDistance(9,9);
  Serial.println(distanceFromexit); 
  
  while (distanceFromexit>60){}
  
  if (distanceFromexit<=60){
    servo_2.write(0);
    delay(10);
    servo_2.write(90);
    delay(3000);
    servo_2.write(0);
    delay(1000);}

}