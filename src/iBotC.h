/*iBotC.h - Simplified library for better understanding of basic programming*/

#ifndef IBOTC_H
#define IBOTC_H

#include <Arduino.h>
#include "Wire.h"

#include "MeConfig.h"

#include "MeMbotDCMotor.h"
#include "MeRGBLed.h"
#include "MeBuzzer.h"
#include "Me4Button.h"

#include "MeSerial.h"
#include "MeIR.h"
#include "MeLineFollower.h"
#include "MeRGBLineFollower.h"
#include "MeColorSensor.h"
#include "MeUltrasonicSensor.h"
 
MePort_Sig mePort[17] =
{
  { NC, NC }, { 11, 12 }, {  9, 10 }, { A2, A3 }, { A0, A1 },
  { NC, NC }, {  8, A6 }, { A7, 13 }, {  8, A6 }, {  6,  7 },
  {  5,  4 }, { NC, NC }, { NC, NC }, { NC, NC }, { NC, NC },
  { NC, NC },{ NC, NC },
};


MeRGBLed lights(7,2);
MeBuzzer buzzer(8);

MeDCMotor motorL(M1);
MeDCMotor motorR(M2);

//MeLineFollower sensor01(PORT_1);
//MeLineFollower sensor23(PORT_2);


MeRGBLineFollower lineFollower(1,0);
MeLineFollower lineFinder(PORT_2);

MeUltrasonicSensor ultraSensor(PORT_3);
MeColorSensor RGBSensor(PORT_4);


void iBotC(){
	RGBSensor.SensorInit();
	lineFollower.begin();
 	lineFollower.updataAllSensorValue();
	Serial.begin(9600);
	pinMode(A7,INPUT);
}

void print(String msg)
{
	Serial.print(msg);
}

void print(int msg)
{
	Serial.print(msg);
}

void print(char msg)
{
	Serial.print(msg);
}

void print(float msg)
{
	Serial.print(msg);
}

void print(double msg)
{
	Serial.print(msg);
}

void print(bool msg)
{
	Serial.print(msg);
}

void print(char* msg)
{
	Serial.print(msg);
}
//
void println(String msg)
{
	Serial.println(msg);
}

void println(int msg)
{
	Serial.println(msg);
}

void println(char msg)
{
	Serial.println(msg);
}

void println(float msg)
{
	Serial.println(msg);
}

void println(double msg)
{
	Serial.println(msg);
}

void println(bool msg)
{
	Serial.println(msg);
}

void println(char* msg)
{
	Serial.println(msg);
}

void motor(int16_t leftspeed,int16_t rightspeed)
{
	motorL.run(-leftspeed);
	motorR.run(rightspeed);
}

void motor(int16_t leftspeed,int16_t rightspeed,int16_t duration)
{
	motorL.run(-leftspeed);
	motorR.run(rightspeed);
	delay(duration);
	motorL.stop();
	motorR.stop();
}
bool LineFollowerL ()
{
	int sensorState = lineFinder.readSensors();
	return sensorState & 1 ;
//  switch(sensorState)
//  {
//    case S1_IN_S2_IN: return 1; break;
//    case S1_IN_S2_OUT: return 1; break;
//    case S1_OUT_S2_IN: return 0; break;
//    case S1_OUT_S2_OUT: return 0; break;
//    default: break;
//  }
  
}
bool LineFollowerR ()
{
	int sensorState = lineFinder.readSensors();
	return sensorState & 2;
//  switch(sensorState)
//  {
//    case S1_IN_S2_IN: return 1; break;
//    case S1_IN_S2_OUT: return 0; break;
//    case S1_OUT_S2_IN: return 1; break;
//    case S1_OUT_S2_OUT: return 0; break;
//    default: break;
//  }
  
}
int sensor0()
{
	int sensorState = lineFollower.getPositionState();
	lineFollower.updataAllSensorValue();
	return (sensorState & (1 << 0)) > 0;
}

int sensor1()
{
	int sensorState = lineFollower.getPositionState();
	lineFollower.updataAllSensorValue();
	return (sensorState & (1 << 1)) > 0;
}

int sensor2()
{
	int sensorState = lineFollower.getPositionState();
	lineFollower.updataAllSensorValue();
	return (sensorState & (1 << 2)) > 0;
}

int sensor3()
{
	int sensorState = lineFollower.getPositionState();
	lineFollower.updataAllSensorValue();
	return (sensorState & (1 << 3)) > 0;
}

double ultraSonic()
{
	return ultraSensor.distanceCm();
}

void led(uint8_t red, uint8_t green, uint8_t blue)
{
	if(red == 0) red = 1;
	if(green == 0) green = 1;
	if(blue == 0) blue = 1;

	lights.setColor(0,red,green,blue);
	lights.show();
}

void led(String RGBcolor)
{
	uint8_t red = 1;
	uint8_t green = 1;
	uint8_t blue = 1;

	if(RGBcolor == "Off")
	{
		red = 1;
		green = 1;
		blue = 1;
	}

	if(RGBcolor == "White")
	{
		red = 255;
		green = 255;
		blue = 255;
	}

	if(RGBcolor == "Red")
	{
		red = 255;
		green = 0;
		blue = 0;
	}

	if(RGBcolor == "Green" || RGBcolor == "Lime")
	{
		red = 0;
		green = 255;
		blue = 0;
	}

	if(RGBcolor == "Blue")
	{
		red = 0;
		green = 0;
		blue = 255;
	}

	if(RGBcolor == "Yellow")
	{
		red = 255;
		green = 255;
		blue = 0;
	}
	
	if(RGBcolor == "Cyan")
	{
		red = 0;
		green = 255;
		blue = 255;
	}

	if(RGBcolor == "Magenta")
	{
		red = 255;
		green = 0;
		blue = 255;
	}

	lights.setColor(0,red,green,blue);
	lights.show();
}

void waitButton()
{
	while(analogRead(A7) > 768);
	delay(100);
}

int button()
{
	return (analogRead(A7) < 768)?1:0;
}

void beep()
{
	buzzer.tone(8,2000,300);
}

void beep(uint8_t times)
{
	for(uint8_t i = 0; i < times; i++)
	{
		buzzer.tone(8,2000,50);
		delay(50);
	}
}

String readColor()
{
	for(int i = 0; i < 5; i++)
		RGBSensor.Returnresult();
	uint8_t colorresult = RGBSensor.Returnresult();
	switch(colorresult)
    {
      case BLACK:
      	return (String)"Black";
      break;
      case BLUE:
      	return (String)"Blue";
      break;
      case YELLOW:
      	return (String)"Yellow";
      break;
      case GREEN:
      	return (String)"Green";
      break;
      case RED:
      	return (String)"Red";
      break;
      case WHITE:
      	return (String)"White";
      break;
      default:
      	return (String)"...";
      break;    
     }
}

uint8_t readRed()
{
	return (uint8_t)(RGBSensor.ReturnColorCode()>>16);
}

uint8_t readGreen()
{
	return (uint8_t)(RGBSensor.ReturnColorCode()>>8);
}

uint8_t readBlue()
{
	return (uint8_t)(RGBSensor.ReturnColorCode());
}

#endif
