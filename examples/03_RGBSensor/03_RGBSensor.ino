#include <iBotC.h>

void setup() 
{ 
  iBotC();
}

void loop() 
{
  String color = readColor();
  int red = readRed();
  int green = readGreen();
  int blue = readBlue();
  
  print("Color detected = ");
  println(color);
  
  print("Red = ");
  print(red);
  print("\tGreen = ");
  print(green);
  print("\tBlue = ");
  println(blue);
  
  delay(500);
}
