#include <Servo.h>
#include <NewPing.h>
 int ServoPin =9;
 int trig =11;
 int echo =12;
 int motor_speed =255;
 int slow_motor_speed =150;
 //left motor
 int leftForward =2;
 int leftBack =4;
 int enLeft =3;
 //right motor
 int rightForward =7;
 int rightBack =5;
 int enRight =6;

NewPing Sensor(trig,echo);
Servo myServo;
void turnleft()
{
  digitalWrite(leftForward,LOW);
  digitalWrite(leftBack,HIGH);
  digitalWrite(rightForward,HIGH);
  digitalWrite(rightBack,LOW);
  analogWrite(enLeft,motor_speed);
  analogWrite(enRight,motor_speed);
  
}
void turnright()
{
  digitalWrite(leftForward,HIGH);
  digitalWrite(leftBack,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBack,HIGH);
  analogWrite(enLeft,motor_speed);
  analogWrite(enRight,motor_speed);
  
}
void Stop()
{
  digitalWrite(leftForward,LOW);
  digitalWrite(leftBack,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBack,LOW);
}
void Forward()
{
   digitalWrite(leftForward,HIGH);
  digitalWrite(leftBack,LOW);
  digitalWrite(rightForward,HIGH);
  digitalWrite(rightBack,LOW);
  analogWrite(enLeft,motor_speed);
  analogWrite(enRight,motor_speed);
}
void BackWard()
{
  digitalWrite(leftForward,LOW);
  digitalWrite(leftBack,HIGH);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBack,HIGH);
  analogWrite(enLeft,slow_motor_speed);
  analogWrite(enRight,slow_motor_speed);
  
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftForward,OUTPUT);
  pinMode(leftBack,OUTPUT);
  pinMode(enLeft,OUTPUT);

  pinMode(rightForward,OUTPUT);
  pinMode(rightBack,OUTPUT);
  pinMode(enRight,OUTPUT);

  myServo.attach(ServoPin);
  myServo.write(90);
  
}

void loop() {
  // put your main code here, to run repeatedly:

 int distance = Sensor.ping_cm();
myServo.write(90);
 if (distance >0 && distance<30)
 {    
  Stop();
  delay(500);
  BackWard();
  delay(200);
  Stop();

  myServo.write(160);
  int Left_D =Sensor.ping_cm();
  delay(1000);

  myServo.write(0);
  int right_D = Sensor.ping_cm();
  delay(1000);

  myServo.write(90);
  if(Left_D==0)
  {turnleft();
   delay(200);
  }
  else if (right_D==0)
  {
    turnright();
    delay(200);
  }
  else if (right_D<30&&Left_D<30)
  {
    BackWard();
    delay(500);
  }
  else if(Left_D >=right_D)
  {
    turnleft();
    delay(200);
  }
  
  else turnright();
  delay(200);
  }
  else Forward();
  
  
  }
