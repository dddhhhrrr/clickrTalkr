#include "controller.h"

Controller::Controller(View &v, Model &m):view(v),model(m)
{
	cout << "Controller created!" << endl;
}


int Controller::readSensor(){
	return clicker.getStatus();
}

void Controller::wiringDelay(unsigned int ms){
	wiringDelay(ms);
}

Controller::~Controller(){
	cout << "Controller destroyed!" << endl;
}
