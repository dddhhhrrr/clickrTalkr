#include "controller.h"

/*   constructor that takes as parameters a reference of the model and the view   */
/*   it initializes a lot of values, some of them are HARDCODED instead of read   */
/*   from setting.txt, MUST CHANGE THAT											  */
Controller::Controller(View &v, Model &m):view(v),model(m)
{
	currentBank = -1;
	numberOfBanks = 4;
	numberOfRows = 5;
	numberOfColumns = 6;
	insideCurrentBank = false;
	selectedRow = -1;
	selectedColumn = -1;
	focusedRow = -1;
	focusedColumn = -1;
	//waitTime = 500;
	exit = false;
	cout << "Controller created!" << endl;
}

/*   reads the value from the clicker   */
int Controller::getStatus(){
	return clicker.getStatus();
}

void Controller::wiringDelay(unsigned int ms){
	wiringDelay(ms);
}

/***********************************************************************
 *                                                                     *
 * 	         Sets and gets, move on, nothing to see here...            *
 *                                                                     *
 **********************************************************************/

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

/***********************************************************************
 *                                                                     *
 * 	        Interesting part about controller starts here              *
 *                                                                     *
 **********************************************************************/

//method that returns 1 when a rising edge occurs, 2 when a falling edge
//occurs, 0 when a timeout occurs and -1 when clicker.status == true		
int Controller::waitForClickOrTimeout(){
	int prevTime = millis();
	static bool prevStatus = false;
	bool currentStatus;
	while((millis()-prevTime) < waitTime) {
		currentStatus = clicker.getStatus();
		if (currentStatus){	//return 1 if a rising edge is detected (!prevStatus && currentStatus)
			if (!prevStatus){
				prevStatus = currentStatus;
//				cout << "out = 1" << endl;
				return 1;
			}
			else {
				prevStatus = currentStatus;
//				cout << "out = -1" << endl;
				return -1; //return -1 when the clicker is pressed (prevStatus == currentStatus == true)
			}
		}
		
		else {
			if (prevStatus){ 
				prevStatus = currentStatus;
//				cout << "out = 2" << endl;
				return 2; //return 2 on falling edge (prevStatus && !currentStatus)
			}
		}
	}
	prevStatus = currentStatus;
	return 0; //return a clicker.status == false for waitTime milliseconds
}

//the main loop checks what type of event occured (timeout or click) and depending on that
//focus the next element on the GUI or select the current element and does the action
//associated with that element. It keeps doing it until exit == true
void Controller::mainLoop(){
	int event;
	while(!exit){
		event = waitForClickOrTimeout();
		switch (event){
			case 0: { 
				focusNext(); 
				break; 
				}
				
			case 1: { 
				if (selectCurrent()){ //selectCurrent will return true when an element has been selected
					 switch(currentBank){
						 case 0: {break;}
						 case 1: {break;}//execute the action associated to that element of the GUI
						 case 2: {buttons[(selectedRow * numberOfColumns) + selectedColumn]->execute(); break;}
						 case 3: {break;}
						 case 4: {break;}
					 }
					 resetValues(); //values are reset to run a new iteration
					 break;
				}
			}
		}		 	
	view.setPercentage(65); //this is for debugging purposes
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

//this method focus the next element on the current selection bank, or
//the next bank if the end of the current selection bank is reached
//THIS IS STILL UNDER CONSTRUCTION	
void Controller::focusNext(){
	if (currentBank == 0) {
		currentBank = 1;	
	}
	else if (currentBank == 1){ //if I'm in the suggestions selection bank
		//if (selectedRow == -1){ //and nothing has been selected
			focusedRow = 0;
			currentBank = 2; //go to the virtual keyboard
			
		//}
		//else {
			//if (focusedColumn < (numberOfColumns - 1)) focusedColumn++;
			//else focusedColumn = 0;
		//}
	}
	
	else if (currentBank == 2){ //if I'm in the virtual keyboard
		if (selectedRow == -1){ //and nothing has been selected
			if (focusedRow < (numberOfRows - 1)) focusedRow++; //and I haven't reached the last row select the next row add one to the focused row
			else { //if I reached the end of the virtual keyboard
				currentBank = 3; //go to the next selection back
				resetValues(); //and reset the values
			}
		}
		else if (focusedColumn < (numberOfColumns - 1)) focusedColumn ++; //if I have selected a row but not a column select a column
		else focusedColumn = 0; //if the end of the columns has been reached go to the begining
	}
	
	else if (currentBank == 3){ //if I'm in the menu items selection bank
		if (selectedColumn == -1){ //and nothing has been selected
		currentBank=0; //go to the virtual keyboard again
		resetValues();
		}
		else {
			if (focusedRow < (numberOfRows - 1)) focusedRow++;
			else focusedRow = 0;
		}
	}
	
	else if (currentBank == 4){ //if I'm in the text editor selection bank
		currentBank++;
	}
	else {
		currentBank=0;
		resetValues();
	}
	view.setCurrentBank(currentBank);
//	cout << "focusNext()" << endl; //for debugging purposes
}

//This method preselect a whole row or, if a row has been selected,
//selects a column to select a single element, and return true if
//that was done
bool Controller::selectCurrent(){
	if (currentBank == 2){
		if (selectedRow == -1) selectedRow = focusedRow;
		else selectedColumn = focusedColumn; 
		updateValues();
		view.updateView();
		if ( (selectedRow >= 0) && (selectedColumn >=0) ) return true;
//		cout << "selectCurrent()" << endl;
		return false;
	}
	
	else if (currentBank == 3){
		if (selectedColumn == -1) {selectedColumn = 1; focusedColumn = 1;}
		else selectedRow = focusedRow;
		if (selectedRow == 4) exit = 1;
		updateValues();
		view.updateView();
		if ( (selectedRow >=0) && (selectedColumn >=0) ) return true;
		return false;
	}
	else if (currentBank == 0) {
		view.sayPhrase(model.getPhraseToSay());
		model.setPhraseToSay("");
	}
	else currentBank = 0;
	return false;
}

void Controller::updateValues(){
	view.setSelectedRow(focusedRow);
	view.setSelectedColumn(focusedColumn);
	view.setCurrentBank(currentBank);
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

void Controller::turnOffLED(){
	clicker.turnOffLED();
}

Controller::~Controller(){
	cout << "Controller destroyed!" << endl;
}
