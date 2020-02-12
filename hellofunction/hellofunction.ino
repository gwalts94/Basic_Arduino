#include <Servo.h>
Servo servo1;
int trigPin = 10;
int echoPin = 11;
int dist;
void setup()
{
  servo1.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop()
{
  dist = ultra();
  Serial.println(dist);
  if (dist <= 5)
  {
    servo1.write(70);
  }
  else
    if ((dist > 5) && (dist < 15))
    {
      servo1.write(160);
    }
  else
  {
    servo1.write(90);
  }
}

int ultra()
{
  long distance;
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  return distance;
}
