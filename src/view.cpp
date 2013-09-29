#include "view.h"

View::View(){
}

View::View(Model m){
	model = m;
	initialize();
}

int View::getWidth(){
	return width;
}

int View::getHeight(){
	return height;
}

void View::setPercentage(int p){
	percentage = p;
}

VGfloat View::getH2(){
	return h2;
}

VGfloat View::getW2(){
	return w2;
}

void View::drawBackground(){
	StrokeWidth(0);
    Background(0,0,0);
}

void View::initialize(){
	init(&width, &height);
	Start(width, height);
	w2 = width/2;
	h2 = height/2;
}

void View::show(){
	End();
}

void View::drawActiveButton(int x, int y, int diameter, char *t){
	VGfloat radius = diameter/2;
	VGfloat reflectionHeight = 0.7 * diameter;
	VGfloat reflectionWidth = 0.85 * diameter;
	VGfloat reflectionGap = 0.025 * diameter;
	
	VGfloat stops[] = {
		0.0, 0.0, 0.5, 1.0, 1.0, //posicion, r,g, b ,a
		1.0, 0.054, 0.156, 0.317, 1.0
	};
	
	VGfloat reflection[] = {
		0.0, 1.0, 1.0, 1.0, 0.4, //posicion, r,g, b ,a
		1.0, 1.0, 1.0, 1.0, 0.0
	};
	
	FillRadialGradient(x, y, x, y, radius+1, stops, 2);
	StrokeWidth(1);
	Stroke(255,255,255,1);
	Circle(x, y, diameter);
	
	Fill(255,255,255,1);
	TextMid(x, y-(32/2), t, SerifTypeface, 32);
	StrokeWidth(0);
	FillLinearGradient(x, y + radius + reflectionHeight - reflectionGap + 1, x, y + radius - reflectionHeight - reflectionGap - 1, reflection, 2);
	Ellipse(x, y + radius - reflectionHeight/2 - reflectionGap, reflectionWidth, reflectionHeight);
}

void View::drawInactiveButton(int x, int y, int diameter, char *t){
	VGfloat radius = diameter/2;
	VGfloat reflectionHeight = 0.7 * diameter;
	VGfloat reflectionWidth = 0.85 * diameter;
	VGfloat reflectionGap = 0.025 * diameter;
	
	VGfloat stops[] = {
		0.0, 0.4, 0.4, 0.4, 1.0, //posicion, r,g, b ,a
		1.0, 0.1, 0.1, 0.1, 1.0
	};
	
	VGfloat reflection[] = {
		0.0, 1.0, 1.0, 1.0, 0.4, //posicion, r,g, b ,a
		1.0, 1.0, 1.0, 1.0, 0.0
	};
	
	FillRadialGradient(x, y, x, y, radius+1, stops, 2);
	StrokeWidth(1);
	Stroke(255,255,255,1);
	Circle(x, y, diameter);
	
	Fill(255,255,255,1);
	TextMid(x, y-(32/2), t, SerifTypeface, 32);
	
	StrokeWidth(0);
	FillLinearGradient(x, y + radius + reflectionHeight - reflectionGap + 1, x, y + radius - reflectionHeight - reflectionGap - 1, reflection, 2);
	Ellipse(x, y + radius - reflectionHeight/2 - reflectionGap, reflectionWidth, reflectionHeight);
}

void View::drawBattery(int lbcX, int lbcY, int p, char *t){
	int fullValue = (p/20)+1;
	int emptyValue;
	int barWidth = 3;
	int barHeight = 8;
	if (fullValue > 5) fullValue = 5;
	if (p < 5) fullValue = 0;
	emptyValue = 5 - fullValue;
	double red,grn;
	string percStr;
	ostringstream convert;
	convert << t << " " << p << "%";
	percStr = convert.str();
	char *pri = &percStr[0];
	
	switch(fullValue){
		case 5: { red=0.0; grn=1.0; break; }
		case 4: { red=0.5; grn=1.0; break; }
		case 3: { red=1.0; grn=1.0; break; }
		case 2: { red=1.0; grn=0.5; break; }
		case 1: { red=1.0; grn=0.0; break; }
		case 0: { red=0.0; grn=0.0; break; }
		default: {red=0.0; grn=1.0;}
	}
	
		
	VGfloat gradientFull[] = {
		0.0, red, grn, 0.0, 1.0, //posicion, r,g, b ,a
		1.0, red/4, grn/4, 0.0, 1.0
	};
	
	VGfloat gradientEmpty[] = {
		0.0, 0.5, 0.5, 0.5, 1.0, //posicion, r,g, b ,a
		1.0, 0.125, 0.125, 0.125, 1.0
	};
	
	StrokeWidth(0);
	if (fullValue > 0) Fill(255,255,255,1);
	else Fill(255,0,0,1);
	
	Rect(lbcX,lbcY,(barWidth*5)+4,barHeight + 4);
	Rect(lbcX+(barWidth*5)+3,lbcY+3,3,6);
	Fill(0,0,0,1);
	Rect(lbcX+1,lbcY+1,(barWidth*5)+2,barHeight+2);
	Rect(lbcX+(barWidth*5)+3,lbcY+4,2,4);
	FillLinearGradient(lbcX, lbcY+barHeight+2, lbcX, lbcY+2, gradientFull, 2);
	Rect(lbcX+2,lbcY+2,fullValue*barWidth,barHeight);
	FillLinearGradient(lbcX, lbcY+barHeight+2, lbcX, lbcY+2, gradientEmpty, 2);
	Rect(lbcX+2+(fullValue*barWidth),lbcY+2, (emptyValue * barWidth) ,barHeight);
	Rect(lbcX+3+(barWidth*5), lbcY+5,1,2);
	if (fullValue > 0) {
		StrokeWidth(1);
		Stroke(0,0,0,1);
		Line(lbcX+2+(fullValue*barWidth),lbcY+2,lbcX+2+(fullValue*barWidth),lbcY+2+barHeight);
	}
	
	TextEnd(lbcX-3, lbcY, pri, SerifTypeface, 10); 
}

void View::updateView(int i){
	drawBackground();
	drawBattery(1135, height - 25, percentage, "clicker");
	drawBattery(1246, height - 25, 100 - percentage, "talker");
	if (i == 1) drawActiveButton(getWidth()/2,getHeight()/2,75, "A"); 
	else drawInactiveButton(getWidth()/2,getHeight()/2,75, "B");
	drawEditor(40,height-180, 1200,140,"The journey is the reward");
	show();
}


void View::drawSelector(int x, int y, int l){}
void View::drawActiveSuggestion(int x,int y, char *t){}
void View::drawInactiveSuggestion(int x, int y, char *t){}
void View::drawSuggestions(){}

void View::drawEditor(int x1, int y1, int w, int h, char *t){
	int fontSize = 24;
	StrokeWidth(2);
	Stroke(255,255,255,1);
	Fill(0,0,0,0);
	Roundrect(x1,y1, w, h, 50,50);
	Fill(255,255,255,1);
	Text((x1+20), y1 + h/2 - fontSize/2, t, SerifTypeface, fontSize);
	}
	
void View::drawVirtualKeyboard(){}
void View::drawMenuItem(int x, int y, char *t){
	
	}
	
void View::drawMenu(){}
void View::drawBatteryPercentage(int p){}
void View::setBatteryMaximum(double max){}
void View::setBatteryMinimum(double min){}
void View::drawBattery(double max, double min, double val){}
void View::drawBattery(double val){}
void View::drawTextEditor(){}


View::~View(){
	
}
