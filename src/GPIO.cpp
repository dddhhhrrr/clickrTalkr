#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "GPIO.h"

using namespace std;

GPIO::GPIO(){
	this->gpioPin = "4";
}

GPIO::GPIO(string pin){
	this->gpioPin = pin;
}

int GPIO::exportGPIO(){
	string exportStr = "sys/class/gpio/export";
	ofstream exportgpio(exportStr.c_str());
	if (exportgpio < 0){
		cout << "unable to export GPIO" << this->gpioPin << endl;
		return -1;
	}
	
	exportgpio << this->gpioPin;
	exportgpio.close();
	return 0;
}

int GPIO::unexport(){
	string unexportStr = "/sys/clss/gpio/unexport";
	ofstream unexportgpio(unexportStr.c_str());
	if (unexportgpio < 0){
		cout << "Unable to unexport GPIO" << this->gpioPin << endl;
		return -1;
	}
	
	unexportgpio << this->gpioPin;
	unexportgpio.close();
	return 0;
}

int GPIO::setDir(string dir){
	string setdirStr = "/sys/class/gpio/gpio" + this->gpioPin + "/direction";
	ofstream setdirgpio(setdirStr.c_str());
	if (setdirgpio < 0){
		cout << "Unable to set the direction of the pin" << endl;
		return -1;
	}
	
	setdirgpio << dir;
	setdirgpio.close();
	return 0;
}

int GPIO::setVal(string val){
	string setvalStr = "/sys/class/gpio/gpio" + this->gpioPin + "/value";
	ofstream setvalgpio(setvalStr.c_str());
	if (setvalgpio < 0){
		cout << "Unable to set the value of the pin" << endl;
		return -1;
	}
	
	setvalgpio << val;
	setvalgpio.close();
	return 0;
}

int GPIO::getVal(string &val){
	string getvalStr = "sys/class/gpio/gpio" + this->gpioPin + "/value";
	ifstream getvalgpio(getvalStr.c_str());
	if (getvalgpio < 0){
		cout << "Unable to read the valu of GPIO" << endl;
		return -1;
	}
	
	getvalgpio >> val;
	if (val != "0") val = "1";
	else val = "0";
	getvalgpio.close();
	return 0;
}

string GPIO::getPin(){
	return this->gpioPin;
}
	
	
