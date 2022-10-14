#include <iBotC.h>

void setup()
{
  iBotC();
}

void loop()
{
  int distance;
  distance = ultraSonic();
  print("Distance = ");
  println(distance);
}
