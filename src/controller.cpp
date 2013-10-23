#include "controller.h"

Controller::Controller(View &v, Model &m):view(v),model(m)
{
	cout << "Controller created!" << endl;
	wiringPiSetup();
	pinMode(CLICKR_PIN,INPUT);
	pullUpDnControl(CLICKR_PIN,PUD_OFF);
}


int Controller::readSensor(){
	return digitalRead(CLICKR_PIN);
}

void Controller::wiringDelay(unsigned int ms){
	wiringDelay(ms);
}

Controller::~Controller(){
	cout << "Controller destroyed!" << endl;
}
