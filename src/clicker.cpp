#include "clicker.h"

using namespace std;

/*   default constructor   */
//   it creates a clicker object with an active low binary input on GPIO1 (wiringPI numbering) and a LED on GPIO3
//   a switch connected to this pin MUST have an external pullup resistor for it to work correctly (or an internal pullup need to be activated by software)
Clicker::Clicker(){
	setClickerPin(CLICKER_PIN);
	setLedPin(LED_PIN);
	cout << "Clicker created!" << endl;
	wiringPiSetup();
	pinMode(clickerPin,INPUT);
	pullUpDnControl(clickerPin,PUD_UP);
	pinMode(LED_PIN,OUTPUT);
	digitalWrite(LED_PIN,LOW);
	isActiveLow(true);
}

/*   constructor with clicker and LED pins as parameters   */
Clicker::Clicker(int cPin, int lPin){
	setClickerPin(cPin);
	setLedPin(lPin);
	//cout << "Clicker created!" << endl;
	wiringPiSetup();
	pinMode(clickerPin,INPUT);
	pullUpDnControl(clickerPin,PUD_OFF);
	pinMode(LED_PIN,OUTPUT);
	digitalWrite(LED_PIN,LOW);
	isActiveLow(true);
}

Clicker::~Clicker(){}

/*   readSensor() returns the RAW value of the sensor (without any filtering or signal conversion)   */
//   Normally, this method shouldn't be used when you want to read the status of the clicker
bool Clicker::readSensor(){
	return digitalRead(CLICKER_PIN);
}

/*   this method returns the abstract value of the clicker (the value after the signal of the sensor has been converted)   */
//   For example, in a digital circuit with a pullup resistor at the input, calling getStatus() will return true when the input is connected to GND (since an input with a pullup is active low)
bool Clicker::getStatus(){
	status = readSensor() ^ isActiveLow(); //for a simple digital sensor, the status is an XOR between the value read from the sensor and the bit indicating if it's active low
	if (status) turnOnLED();
	else turnOffLED();
	return status;
}

/*   returns true if the sensor is active low or false otherwise)   */
bool Clicker::isActiveLow(){
	return activeLow;
}

/*   an overload of the previous method that allows as to set the value of the activeLow parameter (this shouldn't be used for reading the value of activeLow, only for setting it)   */
bool Clicker::isActiveLow(bool al){
	activeLow=al;
	return activeLow;
}

/*   self explaining   */
void Clicker::turnOnLED(){
	digitalWrite(3,HIGH);
}

/*   self explaining   */
void Clicker::turnOffLED(){
	digitalWrite(3,LOW);
}

/*   clickerPin's set   */
void Clicker::setClickerPin(int p){
	clickerPin = p;
}

/*   clickerPin's get   */
int Clicker::getClickerPin(){
	return clickerPin;
}

/*   ledPin's set   */
void Clicker::setLedPin(int p){
	ledPin = p;
}

/*   ledPin's get   */
int Clicker::getLedPin(){
	return ledPin;
}
