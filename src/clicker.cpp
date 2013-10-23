#include "clicker.h"

using namespace std;

Clicker::Clicker()
{
	cout << "Clicker created!" << endl;
	wiringPiSetup();
	pinMode(CLICKER_PIN,INPUT);
	pullUpDnControl(CLICKER_PIN,PUD_OFF);
	pinMode(LED_PIN,OUTPUT);
	digitalWrite(LED_PIN,LOW);
	isActiveLow(false);
}

Clicker::~Clicker(){}

bool Clicker::readSensor(){
	return digitalRead(CLICKER_PIN);
}

bool Clicker::getStatus(){
	status = readSensor();// ^ isActiveLow(); //for a simple digital sensor, the status is an XOR between the value read from the sensor and the bit indicating if it's active low
	if (status) turnOnLED();
	else turnOffLED();
	return status;
}

bool Clicker::isActiveLow(){
	return activeLow;
}

bool Clicker::isActiveLow(bool al){
	activeLow=al;
	return activeLow;
}

void Clicker::turnOnLED(){
	digitalWrite(3,1);
}

void Clicker::turnOffLED(){
	digitalWrite(3,0);
}
