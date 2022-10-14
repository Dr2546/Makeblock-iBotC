#include <iBotC.h>

void setup() 
{ 
  iBotC();
  waitButton();
  beep();
}

void loop() 
{
  int s0 = sensor0();
  int s1 = sensor1();
  int s2 = sensor2();
  int s3 = sensor3();

  println(s1);
  
  if(s0 == 1 || s3 == 1)
  {
    motor(0,0); 
    delay(1500);
    motor(100,100,1000);
  }
  if(s1 == 1 && s2 == 1)
  {
    motor(100,100,100);
  }
  if(s1 == 0 && s2 == 1)
  {
    motor(200,100,100);
  }
  if(s1 == 1 && s2 == 0)
  {
    motor(100,200,100);
  }
}
