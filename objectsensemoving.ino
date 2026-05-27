int mL1=13;
int mL2=11;
int mR1=10;
int mR2=2;
int enA=5;
int enB=6;
int speed=120;int trigger=8;//trigger sent sound
int echo=7;
float distance,duration;

void setup() {

  pinMode(mL1,OUTPUT);
  pinMode(mL2,OUTPUT);
  pinMode(mR1,OUTPUT);
  pinMode(mR2,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
pinMode(trigger,OUTPUT);
   pinMode(echo,INPUT);
   Serial.begin(9600);

}

void loop()
 {
 digitalWrite(trigger,LOW);
  delayMicroseconds(5);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);
  duration=pulseIn(echo,HIGH);
  distance=(duration*0.0354)/2;//equation for speed
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  delay(1000);
  

 if(distance<40)
{
  right();
  delay(1000);
}
else if(distance<50)
{
  left();
  delay(1000);
}
else if(distance<10)
{
  stop_now();
  delay(1000);
}
else
{
  forward();
  delay(1000);
}
}

void forward()
{
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,LOW);
  digitalWrite(mR1,HIGH);
  digitalWrite(mR2,LOW);
  analogWrite(enA,speed);
  analogWrite(enB,speed);
}
//void backward()
//{
  //digitalWrite(mL1,LOW);
  //digitalWrite(mL2,HIGH);
  //digitalWrite(mR1,LOW);
  //digitalWrite(mR2,HIGH);
  //analogWrite(enA,speed);
  //analogWrite(enB,speed);
//}
void right()
{
  digitalWrite(mL1,LOW);
  digitalWrite(mL2,LOW);
  digitalWrite(mR1,HIGH);
  digitalWrite(mR2,LOW);
  analogWrite(enA,speed);
  analogWrite(enB,speed);
}
void left()
{
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,HIGH);
  digitalWrite(mR1,LOW);
  digitalWrite(mR2,HIGH);
  analogWrite(enA,speed);
  analogWrite(enB,speed);
}
void stop_now()
{
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,HIGH);
   digitalWrite(mR1,HIGH);
  digitalWrite(mR2,HIGH);
  analogWrite(enA,1);
  analogWrite(enB,1);

}