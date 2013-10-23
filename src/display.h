#ifndef DISPLAY_H
#define DISPLAY_H

#include "VG/openvg.h"
#include "VG/vgu.h"
#include "model.h"
#include <iostream>
#include <string>
#include <sstream>
#include "HelveticaLight.inc"

extern "C"{
#include "fontinfoHelveticaLight.h"
#include "shapes.h"
}

class Display{
	private:
		Model &model;
		
		VGfloat w2, h2; //w2 is half the width of the screen, h2 is half the height, so (w2,h2) represents the center of the 
		int width, //on initialization this attribute will take the value of the width of the screen			
			height, //on initialization this attribute will take the value of the height of the screen
			numberOfRows, //number of rows for the virtual keyboard
			numberOfColumns, //number of columns for the virtual keyboad
			selectedRow, //the row on the virtual keyboard that is currently selected (or -1 when none is selected)
			selectedColumn, //the column on the virtual keyboard that is currently selected (or -1 when none is selected)
			buttonSize, //REMOVE?
			buttonOffsetX, //the horizontal offset between one button and the next of the vireual kwyboard
			buttonOffsetY, //the vertical offset between one button and the next of the virtual keyboard
			virtualKeyboardInitialX, //the leftmost position for the virtual keyboard (for the center of the first column of buttons)
			virtualKeyboardInitialY, //the topmost position for the virtual keyboard (for the center of the first row of buttons)
			selectorOffset, //the separation between the selector and the buttons
			buttonSizeX, //the width of the buttons on the virtual keyboard
			buttonSizeY, //the height of the buttons on the virtual keyboard
			menuItemSizeX, //the width of the buttons on the menu
			menuItemSizeY, //the height of the buttons on the menu
			menuItemPosX, //the horizontal position in which menu items are placed (the center of the button)
			batteryPosX, //position where the left edge of the battery should be placed
			batteryPosY, //position where the bottom edge of the battery should be placed
			suggestionOffset, //separation between each of the (up to four) suggestion words
			suggestionX, //horizontal position where the first suggestion should be placed
			suggestionY, //vertical position where the suggestions should be placed
			percentage; //the remaining battery life expressed as a percentage
			
		double  batMax,
				batMin;
	protected:
		Fontinfo HelveticaLight;
		
	public:
		Display(Model &m);
		~Display();
		
		
		
		virtual void initialize();
		virtual int getWidth();
		virtual int getHeight();
		virtual int getSelectedRow();
		virtual void setSelectedRow(int r);
		virtual int getSelectedColumn();
		virtual void setSelectedColumn(int c);
		virtual int getNumberOfRows();
		virtual void setNumberOfRows(int r);
		virtual int getNumberOfColumns();
		virtual void setNumberOfColumns(int c);
		virtual void setPercentage(int p);
		virtual VGfloat getW2();
		virtual VGfloat getH2();
	    virtual void drawBackground();
	    virtual void drawActiveButton(int x, int y, int diameter, string t);
	    virtual void drawInactiveButton(int x, int y, int diameter, string t);
	    virtual void drawSelector(int x, int y, int l);
	    virtual void drawActiveSuggestion(int x,int y, string t);
	    virtual void drawInactiveSuggestion(int x, int y, string t);
	    virtual void drawSuggestions();
	    virtual void drawEditor(int x1, int y1, int w, int h, string t);
	    virtual void drawVirtualKeyboard();
	    virtual void drawActiveMenuItem(int x, int y, string t);
	    virtual void drawInactiveMenuItem(int x, int y, string t);
	    virtual void drawMenu();
	    virtual void drawBatteryPercentage(int p);
	    virtual void setBatteryMaximum(double max);
	    virtual void setBatteryMinimum(double min);
	    virtual void drawBattery(double max, double min, double val);
	    virtual void drawBattery(double val);
	    virtual void drawTextEditor();
	    virtual void drawBattery(int leftTopCornerX, int leftTopCornerY, int p, string t);
	    virtual void show();
	    virtual void updateView(int i);
	    
};

#endif
