#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <wiringPi.h>
#include "view.h"

#define CLICKR_PIN 1
#define LED_PIN 2

class Controller{
	private:
		View &view;
		Model &model;
	
	public:
		Controller(View &v, Model &m);
		int readSensor();
		void wiringDelay(unsigned int ms);
		~Controller();
};

#endif
