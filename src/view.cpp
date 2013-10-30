#include "view.h"

View::View(Model &m):model(m),display(m){
	cout << "View created!" << endl;
}

//View::View(Model &m, Display &d):model(m), display(d){
//}

int View::updateView(int i, int j){
	display.setPercentage(i);
	display.updateView(j);
}

View::~View(){
	cout << "View destroyed!" << endl;
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
}
