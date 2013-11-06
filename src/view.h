#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <sstream>

//the view is in charge of all the outputs of the program, and is also a facade of several classes that create different types of output (display, talker, outputFile)

#include "model.h"
#include "display.h"
#include "skinBubbly.h"


class View{
	private:
		Model &model;
		Display display;
		
		int selectedRow,
			selectedColumn,
			numberOfRows,
			numberOfColumns,
			currentBank,
			numberOfBanks,
			focusedRow,
			focusedColumn,
			percentage;

	public:
		View(Model &m);
		View(Model &m, Display &d);
		int updateView();
		~View();
		
		int getSelectedRow();
		void setSelectedRow(int r);
		int getSelectedColumn();
		void setSelectedColumn(int c);
		int getNumberOfRows();
		void setNumberOfRows(int r);
		int getNumberOfColumns();
		void setNumberOfColumns(int c);
		int getCurrentBank();
		void setCurrentBank(int b);
		void setPercentage(int p);
		void setFocusedRow(int r);
		int getFocusedRow();
		void setFocusedColumn(int c);
		int getFocusedColumn();

};

#endif
