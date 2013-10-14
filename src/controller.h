#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <wiringPi.h>
#include "view.h"

#define clickrPin 1

class Controller{
	private:
		View &view;
		Model &model;
	
	public:
		Controller(View &v, Model &m);
		void updateView(int i);
		int readSensor();
		void wiringDelay(unsigned int ms);
	
};

#endif
