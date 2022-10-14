#include <iBotC.h>

void setup()
{
  iBotC();
  println("Press a button to start...");
  waitButton();
}

void loop()
{
  int btn;
  btn = button();

  print("Button state = ");
  println(btn);
}
