#include <iBotC.h>

void setup()
{
  iBotC();
  motor(100, 100);
  delay(1000);
  motor(0, 0);
  delay(1000);
  motor(-100, -100, 500);
}

void loop()
{

}
