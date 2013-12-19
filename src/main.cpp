#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "model.h"
#include "view.h"
#include "controller.h"
#include "configurator.h"
#include "talker.h"

using namespace std;

int main() {
	char a;
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
	 * 	         misc. tests (will NOT stay for final version)         *
	 *                                                                 *
	 ******************************************************************/	
	
	model.printLetters();
	
	/*******************************************************************
	 *                                                                 *
	 *    The application will remain in controller.mainLoop()         *
	 *    until controller.exit == true                                *
	 *                                                                 *
	 ******************************************************************/
	controller.mainLoop();
	controller.turnOffLED();
	return 0;
}

