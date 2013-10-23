#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <sstream>

#include "model.h"
#include "display.h"
#include "skinBubbly.h"


class View{
	private:
		Model &model;
		skinBubbly display;
		
		int selectedRow,
			selectedColumn,
			numberOfRows,
			numberOfColumns,
			currentBank,
			numberOfBanks;

	public:
		View(Model &m);
		int updateView(int i, int j);
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
		

};

#endif
