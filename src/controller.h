#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <wiringPi.h>
#include "view.h"
#include "clicker.h"
#include "letterController.h"

class Controller{
	
	//enum Bank {suggestions, virtualKeyboard, menu, textEditor};
	
	private:
		View &view;
		Model &model;
		Clicker clicker;
		vector<LetterController*> buttons;
		
		int currentBank,
		    selectedRow,
		    selectedColumn,
		    numberOfRows,
		    numberOfColumns,
		    numberOfBanks,
		    waitTime;
		   
		bool insideCurrentBank;
	
	public:
		Controller(View &v, Model &m);
		void setCurrentBank(int b);
		int getCurrentBank();
		void setNumberOfBanks(int b);
		int getNumberOfBanks();
		void setSelectedRow(int r);
		int getSelectedRow();
		void setSelectedColumn(int c);
		int getSelectedColumn();
		int getNumberOfRows();
		void setNumberOfRows(int r);
		int getNumberOfColumns();
		void setNumberOfColumns(int c);
		double getWaitTimeInSeconds();
		void setWaitTimeInSeconds(double t);
		int getWaitTime();
		void setWaitTime(int t);
		int getStatus();
		int start();
		void wiringDelay(unsigned int ms);
		int getButtonsVectorSize();
		LetterController* getButtonAtIndex(int x);
		void addButtonToVector(string value, string type);
		int waitForClickOrTimeout();
		void mainLoop();
		~Controller();
		
};

#endif
