#include<Stepper.h>
Stepper mystepper(200,8,9,10,11);
int angle=0,previous=0,steps;

void setup()
{
  Serial.begin(9600);
  mystepper.setSpeed(60);
}

void loop()
{
  if(Serial.available()>0)
  {
    angle=Serial.parseInt();
    angle=angle-previous;
    previous=angle;
    steps=(2000*angle)/360;
    mystepper.step(steps);
    Serial.println("----------------");
    Serial.print("Angle: "); Serial.println(angle);
    Serial.print("Steps: "); Serial.println(steps);
    Serial.println("----------------");
    
  }
}

