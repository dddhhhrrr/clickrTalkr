//the class clicker (part of the controller) is in charge of reading and interpreting the state of the clicker (the sensor which the user will activate to navigate through the application)

#ifndef CLICKER_H
#define CLICKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include <wiringPi.h>

#define CLICKER_PIN 1 //GPIO1 of the wiringPI library corresponds to GPIO18 of the Broadcom chip on the Rev2 of the Raspberry Pi
#define LED_PIN 3 //GPIO3 of the wiringPI library corresponds to GPIO22 of the Broadcom chip on the Rev2 of the Raspberry Pi 

using namespace std;

class Clicker{
	private:
		bool activeLow; //if the sensor is active low (for example a switch connected to a pull-up resistor) this needs to be set to TRUE, otherwise, set to FALSE
		bool status; //the logic state, after the needed treatment (filtering, inversion, etc) has been given to the clicker signal
		int clickerPin; //the pin to which the input of the clicker is connected (by default 1)
		int ledPin; //the pin to which the LED (if any) on the clicker is connected
	public:
		Clicker();
		Clicker(int cPin, int lPin);
		~Clicker();
		void setClickerPin(int p);
		int getClickerPin();
		void setLedPin(int p);
		int getLedPin();
		bool getStatus();
		bool isActiveLow();
		bool isActiveLow(bool al);
		bool readSensor();
		void turnOnLED();
		void turnOffLED();
};

#endif
