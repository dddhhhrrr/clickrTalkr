#include "controller.h"

Controller::Controller(View &v, Model &m):view(v),model(m)
{
	currentBank = 2;
	numberOfBanks = 4;
	numberOfRows = 5;
	numberOfColumns = 6;
	insideCurrentBank = false;
	waitTime = 1000;
	cout << "Controller created!" << endl;
}

int Controller::getStatus(){
	return clicker.getStatus();
}

void Controller::wiringDelay(unsigned int ms){
	wiringDelay(ms);
}

void Controller::setCurrentBank(int b){
	currentBank = b;
}

int Controller::getCurrentBank(){
	return currentBank;
}

void Controller::setNumberOfBanks(int b){
	numberOfBanks = b;
}

int Controller::getNumberOfBanks(){
	return numberOfBanks;
}

void Controller::setSelectedRow(int r){
	selectedRow = r;
}

int Controller::getSelectedRow(){
	return selectedRow;
}

void Controller::setSelectedColumn(int c){
	selectedColumn = c;
}

int Controller::getSelectedColumn(){
	return selectedColumn;
}

void Controller::setNumberOfRows(int r){
	numberOfRows = r;
}

int Controller::getNumberOfRows(){
	return numberOfRows;
} 

void Controller::setNumberOfColumns(int c){
	numberOfColumns = c;
}

int Controller::getNumberOfColumns(){
	return numberOfColumns;
}

double Controller:: getWaitTimeInSeconds(){
	return (double)waitTime/1000.0;
}

void Controller::setWaitTimeInSeconds(double t){
	waitTime = (int)(t * 1000);
}

int Controller::getWaitTime(){
	return waitTime;
}

void Controller::setWaitTime(int t){
	waitTime = t;
}
		
int Controller::waitForClickOrTimeout(){
	int prevTime = millis();
	static bool prevStatus = false;
	bool currentStatus;
	while((millis()-prevTime) < waitTime) {
		currentStatus = clicker.getStatus();
		if (currentStatus){
			if (!prevStatus){
				prevStatus = currentStatus;
				return 1;
			}
			else {
				prevStatus = currentStatus;
				return -1;
			}
		}
		
		else {
			if (prevStatus){
				prevStatus = currentStatus;
				return 2;
			}
		}
	}
	prevStatus = currentStatus;
	return 0;
}

void Controller::mainLoop(){
	int event;
	if (currentBank == 2){
		event = waitForClickOrTimeout();
	}
			
}

int Controller::getButtonsVectorSize(){
	return buttons.size();
}

LetterController* Controller::getButtonAtIndex(int x){
	return buttons[x];
}

void Controller::addButtonToVector(string value, string type){
	LetterController *buttonToAdd = new LetterController(model,value,type);
	buttons.push_back(buttonToAdd);
	cout << "button added, array size: " << buttons.size() << endl; 
}

Controller::~Controller(){
	cout << "Controller destroyed!" << endl;
}
