#include "controller.h"

Controller::Controller(View v, Model m){
	view = v;
	model = m;
	wiringPiSetup();
	pinMode(1,INPUT);
	pullUpDnControl(1,PUD_OFF);
}

void Controller::updateView(int i){
	view.updateView(!i);
}

int Controller::readSensor(){
	return digitalRead(1);
}

void Controller::wiringDelay(unsigned int ms){
	wiringDelay(ms);
}
