#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <wiringPi.h>
#include "view.h"
#include "clicker.h"

class Controller{
	private:
		View &view;
		Model &model;
		Clicker clicker;
	
	public:
		Controller(View &v, Model &m);
		int readSensor();
		void wiringDelay(unsigned int ms);
		~Controller();
};

#endif
