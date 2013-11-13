#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "model.h"
#include "view.h"
#include "controller.h"
#include "configurator.h"

#define NUMBER_OF_ROWS 5
#define NUMBER_OF_COLUMNS 6

using namespace std;

int main() {
	char a;
	string prefix="espeak \"";
	string text;
	string suffix="\"";
	string fullTextString;
	char *fullText;
	string value;
	int pin;
	int j = 3;
	
	Model model;
	Model &modelReference = model; 
	View view(modelReference);
	View &viewReference = view;
	Controller controller(viewReference, modelReference);
	Controller &controllerReference = controller;
	Configurator configurator(modelReference, viewReference, controllerReference);
	configurator.configureModel();
	configurator.configureView();
	configurator.configureController();
	model.printLetters();
	if (controller.getStatus()) cout << "pin = HIGH" << endl;
	else cout << "pin = LOW" << endl;
	controller.mainLoop();
	text = model.getPhraseToSay();
	fullTextString = prefix + text + suffix;
	fullText = &fullTextString[0];
	system(fullText);
	return 0;
}

