#include "skinBubbly.h"
skinBubbly::skinBubbly(Model &m):Display(m),model(m){
	cout <<"skinBubbly created!" << endl;
	initialize();
}

int skinBubbly::getWidth(){
	return width;
}

int skinBubbly::getHeight(){
	return height;
}

int skinBubbly::getSelectedRow(){
	return selectedRow;
}

void skinBubbly::setSelectedRow(int r){
	selectedRow = r;
}

int skinBubbly::getSelectedColumn(){
	return selectedColumn;
}

void skinBubbly::setSelectedColumn(int c){
	selectedColumn = c;
}
int skinBubbly::getNumberOfRows(){
	return numberOfRows;
}

void skinBubbly::setNumberOfRows(int r){
	numberOfRows = r;
}

int skinBubbly::getNumberOfColumns(){
	return numberOfColumns;
}

void skinBubbly::setNumberOfColumns(int c){
	numberOfColumns = c;
}

void skinBubbly::setPercentage(int p){
	percentage = p;
}

VGfloat skinBubbly::getH2(){
	return h2;
}

VGfloat skinBubbly::getW2(){
	return w2;
}

void skinBubbly::drawBackground(){
	StrokeWidth(0);
    Background(0,0,0);
}

void skinBubbly::initialize(){
	init(&width, &height);
	Start(width, height);
	w2 = width/2;
	h2 = height/2;
	numberOfRows = 5;
	numberOfColumns = 6;
	selectedRow = -1;
	selectedColumn= -1;
	virtualKeyboardInitialX = 75;
	virtualKeyboardInitialY = 515;
	menuItemPosX = 800;
	buttonSize = 75;
	buttonOffsetX = 110;
	buttonOffsetY = 110;
	menuItemSizeX = 185;
	menuItemSizeY = 75;
	HelveticaLight=loadfont(HelveticaLight_glyphPoints,
	HelveticaLight_glyphPointIndices,
	HelveticaLight_glyphInstructions,
	HelveticaLight_glyphInstructionIndices,
	HelveticaLight_glyphInstructionCounts,
	HelveticaLight_glyphAdvances, HelveticaLight_characterMap, HelveticaLight_glyphCount);
	cout << "skinBubbly initialized!" << endl;
}

void skinBubbly::show(){
	End();
}

void skinBubbly::drawActiveButton(int x, int y, int diameter, string t){
	VGfloat radius = diameter/2;
	VGfloat reflectionHeight = 0.7 * diameter;
	VGfloat reflectionWidth = 0.85 * diameter;
	VGfloat reflectionGap = 0.025 * diameter;
	int fontsize;
	
	VGfloat stops[] = {
		0.0, 0.0, 0.5, 1.0, 1.0, //posicion, r,g, b ,a
		1.0, 0.054, 0.156, 0.317, 1.0
	};
	
	VGfloat reflection[] = {
		0.0, 1.0, 1.0, 1.0, 0.4, //posicion, r,g, b ,a
		1.0, 1.0, 1.0, 1.0, 0.0
	};
	
	if (t.length() > 1) fontsize = 14;
	else fontsize = 24;
	
	FillLinearGradient(x, y+radius+1, x, y-radius-1, stops, 2);
	StrokeWidth(0);
	Stroke(255,255,255,1);
	Circle(x, y, diameter);
	
	Fill(255,255,255,1);
	TextMid(x, y-(fontsize/2), &t[0], HelveticaLight, fontsize);
	StrokeWidth(0);
	FillLinearGradient(x, y + radius + reflectionHeight - reflectionGap + 1, x, y + radius - reflectionHeight - reflectionGap - 1, reflection, 2);
	Ellipse(x, y + radius - reflectionHeight/2 - reflectionGap, reflectionWidth, reflectionHeight);
}

void skinBubbly::drawInactiveButton(int x, int y, int diameter, string t){
	VGfloat radius = diameter/2;
	VGfloat reflectionHeight = 0.7 * diameter;
	VGfloat reflectionWidth = 0.85 * diameter;
	VGfloat reflectionGap = 0.025 * diameter;
	int fontsize;
	
	VGfloat stops[] = {
		0.0, 0.4, 0.4, 0.4, 1.0, //posicion, r,g, b ,a
		1.0, 0.1, 0.1, 0.1, 1.0
	};

	VGfloat reflection[] = {
		0.0, 1.0, 1.0, 1.0, 0.4, //posicion, r,g, b ,a
		1.0, 1.0, 1.0, 1.0, 0.0
	};
	
	if (t.length() > 1) fontsize = 14;
	else fontsize = 24;
	
	FillLinearGradient(x, y+radius+1, x, y-radius-1, stops, 2);
	StrokeWidth(0);
	Stroke(255,255,255,1);
	Circle(x, y, diameter);
	
	Fill(255,255,255,1);
	TextMid(x, y-(fontsize/2), &t[0], HelveticaLight, fontsize);
	
	StrokeWidth(0);
	FillLinearGradient(x, y + radius + reflectionHeight - reflectionGap + 1, x, y + radius - reflectionHeight - reflectionGap - 1, reflection, 2);
	Ellipse(x, y + radius - reflectionHeight/2 - reflectionGap, reflectionWidth, reflectionHeight);
}

void skinBubbly::drawBattery(int lbcX, int lbcY, int p, string t){
	int fullValue = (p/20)+1;	int emptyValue;
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
	
	TextEnd(lbcX-3, lbcY+2, &percStr[0], HelveticaLight, 10); 
}

void skinBubbly::updateView(){
	drawBackground();
	drawBattery(1118, height - 25, percentage, "clicker");
	drawBattery(1218, height - 25, 100 - percentage, "talker");
	drawVirtualKeyboard();
	//if (i == 1){ selectedRow = 2;}
	//else { selectedRow = -1;}
	drawMenu();
	drawEditor(40, height-180, 1200, 140, model.getPhraseToSay());
	drawTextEditor();
	show();	
}

void skinBubbly::drawSelector(int x, int y, int l){}
void skinBubbly::drawActiveSuggestion(int x,int y, string t){}
void skinBubbly::drawInactiveSuggestion(int x, int y, string t){}
void skinBubbly::drawSuggestions(){}

void skinBubbly::drawEditor(int x1, int y1, int w, int h, string t){
	int fontSize = 24;
	StrokeWidth(2);
	Stroke(255,255,255,1);
	Fill(0,0,0,1);
	Roundrect(x1,y1, w, h, 50,50);
	Fill(255,255,255,1);
	Text((x1+20), y1 + h/2 - fontSize/2, &t[0], HelveticaLight, fontSize);
}
	
void skinBubbly::drawVirtualKeyboard(){
	for (int j = 0; j < numberOfRows; j++){
		for (int i=0; i < numberOfColumns; i++){
			if (selectedRow == j && (selectedColumn == i || selectedColumn == -1)) drawActiveButton(virtualKeyboardInitialX + (buttonOffsetX * i), virtualKeyboardInitialY - (buttonOffsetY * j), buttonSize, model.getLetterAtIndex(i+j*numberOfColumns)->getLetterToDisplay());
			else  drawInactiveButton(virtualKeyboardInitialX + (buttonOffsetX * i), virtualKeyboardInitialY - (buttonOffsetY * j), buttonSize, model.getLetterAtIndex(i+j*numberOfColumns)->getLetterToDisplay());
		}
	}
}
	
	
void skinBubbly::drawActiveMenuItem(int x, int y, string t){
	VGfloat reflectionHeight = 0.7 * menuItemSizeY;
	VGfloat reflectionWidth = 0.85 * menuItemSizeX;
	VGfloat reflectionGap = 0.025 * menuItemSizeY;
	VGfloat stops[] = {
		0.0, 0.0, 0.5, 1.0, 1.0, //posicion, r,g, b ,a
		1.0, 0.054, 0.156, 0.317, 1.0
	};	
	VGfloat reflection[] = {
		0.0, 1.0, 1.0, 1.0, 0.4, //posicion, r,g, b ,a
		1.0, 1.0, 1.0, 1.0, 0.0
	};
	
	FillLinearGradient(x, y+menuItemSizeY/2, x, y-menuItemSizeY/2, stops, 2);
	StrokeWidth(0);
	Stroke(255,255,255,1);
	Roundrect(x - (menuItemSizeX/2), y - (menuItemSizeY/2), menuItemSizeX,  menuItemSizeY, menuItemSizeY, menuItemSizeY);
	StrokeWidth(0);
	FillLinearGradient(x,y + menuItemSizeY/2 + reflectionHeight - reflectionGap +1, x, y + (menuItemSizeY/2) - reflectionHeight - reflectionGap -1, reflection, 2);
	Roundrect(x - (reflectionWidth/2), y + (menuItemSizeY/2) - reflectionHeight - reflectionGap , reflectionWidth, reflectionHeight, reflectionHeight, reflectionHeight);
	Fill(255,255,255,1);
	TextMid(x, y-(18/2), &t[0], HelveticaLight, 18);
}

void skinBubbly::drawInactiveMenuItem(int x, int y, string t){
	VGfloat reflectionHeight = 0.7 * menuItemSizeY;
	VGfloat reflectionWidth = 0.85 * menuItemSizeX;
	VGfloat reflectionGap = 0.025 * menuItemSizeY;
	
	VGfloat stops[] = {
		0.0, 0.4, 0.4, 0.4, 1.0, //posicion, r,g, b ,a
		1.0, 0.1, 0.1, 0.1, 1.0
	};
	
	VGfloat reflection[] = {
		0.0, 1.0, 1.0, 1.0, 0.4, //posicion, r,g, b ,a
		1.0, 1.0, 1.0, 1.0, 0.0
	};
	
	FillLinearGradient(x, y+menuItemSizeY/2, x, y-menuItemSizeY/2, stops, 2);
	StrokeWidth(0);
	Stroke(255,255,255,1);
	Roundrect(x - (menuItemSizeX/2), y - (menuItemSizeY/2), menuItemSizeX,  menuItemSizeY, menuItemSizeY, menuItemSizeY);
	
	StrokeWidth(0);
	FillLinearGradient(x,y + menuItemSizeY/2 + reflectionHeight - reflectionGap +1, x, y + (menuItemSizeY/2) - reflectionHeight - reflectionGap -1, reflection, 2);
	Roundrect(x - (reflectionWidth/2), y + (menuItemSizeY/2) - reflectionHeight - reflectionGap , reflectionWidth, reflectionHeight, reflectionHeight, reflectionHeight);
	
	Fill(255,255,255,1);
	TextMid(x, y-(18/2), &t[0], HelveticaLight, 18);	
}
	
void skinBubbly::drawMenu(){
	drawActiveMenuItem(menuItemPosX, virtualKeyboardInitialY, "Settings");
	drawInactiveMenuItem(menuItemPosX, virtualKeyboardInitialY-buttonOffsetY, "Open File...");
	drawInactiveMenuItem(menuItemPosX, virtualKeyboardInitialY-buttonOffsetY*2, "Close File...");
	drawInactiveMenuItem(menuItemPosX, virtualKeyboardInitialY-buttonOffsetY*3, "Help");
	drawInactiveMenuItem(menuItemPosX, virtualKeyboardInitialY-buttonOffsetY*4, "Sleep");
}

void skinBubbly::drawBatteryPercentage(int p){}
void skinBubbly::setBatteryMaximum(double max){}
void skinBubbly::setBatteryMinimum(double min){}
void skinBubbly::drawBattery(double max, double min, double val){}
void skinBubbly::drawBattery(double val){}

void skinBubbly::drawTextEditor(){
	Stroke(255,255,255,1);
	Fill(0,0,0,0);
	Rect(940,35,300,520);
}


skinBubbly::~skinBubbly(){
	cout << "skinBubbly destroyed!" << endl;
}

