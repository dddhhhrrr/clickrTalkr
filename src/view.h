#ifndef VIEW_H
#define VIEW_H

#include "VG/openvg.h"
#include "VG/vgu.h"
#include "model.h"
#include <iostream>
#include <string>
#include <sstream>
//#include "asap.inc"

extern "C"{
#include "fontinfo.h"
#include "shapes.h"
}

//Fontinfo Asap;

class View{
	private:
		Model &model;
		
		VGfloat w2, h2;
		int width,
			height,
			numberOfRows,
			numberOfColumns,
			selectedRow,
			selectedColumn,
			buttonSize,
			buttonOffsetX,
			buttonOffsetY,
			virtualKeyboardInitialX,
			virtualKeyboardInitialY,
			selectorOffset,
			buttonSizeX,
			buttonSizeY,
			menuItemSizeX,
			menuItemSizeY,
			menuItemPosX,
			batteryPosX,
			batteryPosY,
			suggestionOffset,
			suggestionX,
			suggestionY,
			percentage;
			
		double  batMax,
				batMin;
		
	public:
		View(Model &m);
		~View();
		
		void initialize();
		int getWidth();
		int getHeight();
		int getSelectedRow();
		void setSelectedRow(int r);
		int getSelectedColumn();
		void setSelectedColumn(int c);
		int getNumberOfRows();
		void setNumberOfRows(int r);
		int getNumberOfColumns();
		void setNumberOfColumns(int c);
		void setPercentage(int p);
		VGfloat getW2();
		VGfloat getH2();
	    void drawBackground();
	    void drawActiveButton(int x, int y, int diameter, string t);
	    void drawInactiveButton(int x, int y, int diameter, string t);
	    void drawSelector(int x, int y, int l);
	    void drawActiveSuggestion(int x,int y, string t);
	    void drawInactiveSuggestion(int x, int y, string t);
	    void drawSuggestions();
	    void drawEditor(int x1, int y1, int w, int h, string t);
	    void drawVirtualKeyboard();
	    void drawActiveMenuItem(int x, int y, string t);
	    void drawInactiveMenuItem(int x, int y, string t);
	    void drawMenu();
	    void drawBatteryPercentage(int p);
	    void setBatteryMaximum(double max);
	    void setBatteryMinimum(double min);
	    void drawBattery(double max, double min, double val);
	    void drawBattery(double val);
	    void drawTextEditor();
	    void drawBattery(int leftTopCornerX, int leftTopCornerY, int p, string t);
	    void show();
	    void updateView(int i);
	    
};

#endif
