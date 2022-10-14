#include <iBotC.h>

void setup() 
{ 
  iBotC();
}

void loop() 
{
  beep();
  delay(3000);
  
  beep(3);
  delay(3000);
  
  beep(5);
  delay(3000);
  
  beep(10);
  delay(3000);
}
