#include "controller.h"

/*   constructor that takes as parameters a reference of the model and the view   */
Controller::Controller(View &v, Model &m):view(v),model(m)
{
	currentBank = 2;
	numberOfBanks = 4;
	numberOfRows = 5;
	numberOfColumns = 6;
	insideCurrentBank = false;
	selectedRow = -1;
	selectedColumn = -1;
	focusedRow = -1;
	focusedColumn = -1;
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

void Controller::setFocusedRow(int r){
	focusedRow = r;
}

int Controller::getFocusedRow(){
	return focusedRow;
}

void Controller::setFocusedColumn(int c){
	focusedColumn = c;
}

int Controller::getFocusedColumn(){
	return focusedColumn;
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
		
int Controller::waitForClickOrTimeout(){ //this method will return 1 when a rising edge occurs, 2 when a falling edge occurs, -1 when the status is high, and 0 when there's a timeout
	int prevTime = millis();
	static bool prevStatus = false;
	bool currentStatus;
	while((millis()-prevTime) < waitTime) {
		currentStatus = clicker.getStatus();
		if (currentStatus){
			if (!prevStatus){
				prevStatus = currentStatus;
				cout << "out = 1" << endl;
				return 1;
			}
			else {
				prevStatus = currentStatus;
				cout << "out = -1" << endl;
				return -1;
			}
		}
		
		else {
			if (prevStatus){
				prevStatus = currentStatus;
				cout << "out = 2" << endl;
				return 2;
			}
		}
	}
	prevStatus = currentStatus;
	return 0;
}

void Controller::mainLoop(){
	int event;
	for (int i = 100; i >= 0; i--){
		if (currentBank == 2){
			event = waitForClickOrTimeout();
			switch (event){
				case 0: { focusNext(); break; }
				
				case 1: { 
					if (selectCurrent()){
						 buttons[(selectedRow * numberOfColumns) + selectedColumn]->execute(); 
						 resetValues();
						 break;
					}
				}
			}		 
		}
	view.setPercentage(i);
	updateValues();
	view.updateView();
	}
}

void Controller::resetValues(){
	selectedRow = -1;
	selectedColumn = -1;
	focusedRow = -1;
	focusedColumn = -1;
	updateValues();
}
	
void Controller::focusNext(){
	if (currentBank == 2){ //if I'm in the virtual keyboard
		if (selectedRow == -1){
			if (focusedRow < (numberOfRows - 1)) focusedRow++; //if I haven't reached the last row select the next row
			else focusedRow = 0; //if I reached the last row go to the next bank;
		}
		else if (focusedColumn < (numberOfColumns - 1)) focusedColumn ++;
		else focusedColumn = 0;
	}
	cout << "focusNext()" << endl;
}

void Controller::updateValues(){
	view.setSelectedRow(focusedRow);
	view.setSelectedColumn(focusedColumn);
}

bool Controller::selectCurrent(){
	if (selectedRow == -1) selectedRow = focusedRow;
	else selectedColumn = focusedColumn; 
	//view.setSelectedRow(selectedRow);
	updateValues();
	view.updateView();
	if ( (selectedRow >= 0) && (selectedColumn >=0) ) return true;
	cout << "selectCurrent()" << endl;
	return false;
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
