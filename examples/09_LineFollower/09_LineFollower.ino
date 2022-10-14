#include <iBotC.h>

void setup() 
{ 
  iBotC();
}

void loop() 
{
  int LEFT = LineFollowerL();
  int RIGHT = LineFollowerR();
  
  print("Left : ");
  println(LEFT);
  print("Right : ");
  println(RIGHT);
}
