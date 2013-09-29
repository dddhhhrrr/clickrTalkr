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
		Model model;
		
		VGfloat w2, h2;
		int width,
			height,
			buttonOffsetX,
			buttonOffsetY,
			selectorOffset,
			buttonSizeX,
			buttonSizeY,
			batteryPosX,
			batteryPosY,
			suggestionOffset,
			suggestionX,
			suggestionY,
			percentage;
			
		double  batMax,
				batMin;
		
	public:
		View();
		View(Model m);
		~View();
		
		void initialize();
		int getWidth();
		int getHeight();
		void setPercentage(int p);
		VGfloat getW2();
		VGfloat getH2();
	    void drawBackground();
	    void drawActiveButton(int x, int y, int diameter, char *t);
	    void drawInactiveButton(int x, int y, int diameter, char *t);
	    void drawSelector(int x, int y, int l);
	    void drawActiveSuggestion(int x,int y, char *t);
	    void drawInactiveSuggestion(int x, int y, char *t);
	    void drawSuggestions();
	    void drawEditor(int x1, int y1, int w, int h, char *t);
	    void drawVirtualKeyboard();
	    void drawMenuItem(int x, int y, char *t);
	    void drawMenu();
	    void drawBatteryPercentage(int p);
	    void setBatteryMaximum(double max);
	    void setBatteryMinimum(double min);
	    void drawBattery(double max, double min, double val);
	    void drawBattery(double val);
	    void drawTextEditor();
	    void drawBattery(int leftTopCornerX, int leftTopCornerY, int p, char *t);
	    void show();
	    void updateView(int i);
	    
};

#endif
