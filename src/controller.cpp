#include "controller.h"

Controller::Controller(View &v, Model &m):view(v),model(m)
{
	//view = v;
	//model = m;
	wiringPiSetup();
	pinMode(clickrPin,INPUT);
	pullUpDnControl(clickrPin,PUD_OFF);
}

void Controller::updateView(int i){
	view.updateView(!i);
}

int Controller::readSensor(){
	return digitalRead(clickrPin);
}

void Controller::wiringDelay(unsigned int ms){
	wiringDelay(ms);
}
