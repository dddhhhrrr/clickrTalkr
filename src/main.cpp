#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "model.h"
#include "view.h"
#include "controller.h"
#include "configurator.h"

using namespace std;

int main() {
	char a;
	string prefix="espeak \"";
	string text;
	string suffix="\"";
	string fullTextString;
	char *fullText;
	string value;

	/*******************************************************************
	 *                                                                 *
	 * 	                      Creation of Objects                      *
	 *                                                                 *
	 ******************************************************************/
	 
	Model model;
	Model &modelReference = model; 
	View view(modelReference);
	View &viewReference = view;
	Controller controller(viewReference, modelReference);
	Controller &controllerReference = controller;
	Configurator configurator(modelReference, viewReference, controllerReference);
	
	/*******************************************************************
	 *                                                                 *
	 * 	                      Configuration of Objects                 *
	 *                                                                 *
	 ******************************************************************/
	 
	configurator.configureModel();
	configurator.configureView();
	configurator.configureController();
	
	/*******************************************************************
	 *                                                                 *
	 * 	         misc. tests (will NOT stay for final version)         *
	 *                                                                 *
	 ******************************************************************/	
	
	model.printLetters();
	if (controller.getStatus()) cout << "pin = HIGH" << endl;
	else cout << "pin = LOW" << endl;
	
	/*******************************************************************
	 *                                                                 *
	 *    The application will remain in controller.mainLoop()         *
	 *    until controller.exit == true                                *
	 *                                                                 *
	 ******************************************************************/
	controller.mainLoop();
	text = model.getPhraseToSay();
	fullTextString = prefix + text + suffix;
	fullText = &fullTextString[0];
	system(fullText);
	return 0;
}

