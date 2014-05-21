#include "view.h"

View::View(Model &m):model(m),display(m),talker("eSpeak"){
	cout << "View created!" << endl;
}

int View::updateView(){
	display.setPercentage(percentage);
//	cout << "selectedRow: " << selectedRow << ", selectedColumn: " << selectedColumn << "currentBank: " << currentBank << endl;
	display.setSelectedRow(selectedRow);
	display.setSelectedColumn(selectedColumn);
	display.currentBank = currentBank;
	display.updateView();
}

View::~View(){
	cout << "View destroyed!" << endl;
}

void View::sayPhrase(string p){
	talker.sayPhrase(p);
}

int View::getSelectedRow(){
	return selectedRow;
}

void View::setSelectedRow(int r){
	selectedRow = r;
}

int View::getSelectedColumn(){
	return selectedColumn;
}

void View::setSelectedColumn(int c){
	selectedColumn = c;
}

int View::getNumberOfRows(){
	return numberOfRows;
}

void View::setNumberOfRows(int r){
	numberOfRows = r;
	display.setNumberOfRows(r);
}

int View::getNumberOfColumns(){
	return numberOfColumns;
}

void View::setNumberOfColumns(int c){
	numberOfColumns = c;
	display.setNumberOfColumns(c);
}

int View::getCurrentBank(){
	return currentBank;
}

void View::setCurrentBank(int b){
	currentBank = b;
	display.currentBank = currentBank;
}

void View::setFocusedRow(int r){
	focusedRow = r;
}

int View::getFocusedRow(){
	return focusedRow;
}

void View::setFocusedColumn(int c){
	focusedColumn = c;
}

int View::getFocusedColumn(){
	return focusedColumn;
}

void View::setPercentage(int p){
	percentage = p;
	display.setPercentage(p);
}
