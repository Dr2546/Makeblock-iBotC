#include <iBotC.h>

void setup() 
{ 
  iBotC();
}

void loop() 
{
  int s0 = sensor0();
  int s1 = sensor1();
  int s2 = sensor2();
  int s3 = sensor3();
  
  print("S0 = ");
  print(s0);
  print("\tS1 = ");
  print(s1);
  print("\tS2 = ");
  print(s2);
  print("\tS3 = ");
  println(s3);
}
