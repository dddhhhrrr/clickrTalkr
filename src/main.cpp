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
	string text="Hi, thanks for using clickerTalker, this is a test";
	string suffix="\"";
	string fullTextString = prefix + text + suffix;
	char *fullText = &fullTextString[0]; 
	string value;
	int pin;
	int j = 3;
	
	Model model;
	Model &modelReference = model; 
	View view(modelReference);
	View &viewReference = view;
	Controller controller(viewReference, modelReference);
	Controller &controllerReference = controller;
	Configurator configurator(modelReference);
	configurator.configureModel();
	cout << "This is from the model.printLetters() Method!" << endl;
	model.printLetters();
	if (controller.readSensor()) cout << "pin = HIGH" << endl;
	else cout << "pin = LOW" << endl;
	for (int i = 100; i >= 0; i--){
		
		view.updateView(i,!controller.readSensor());
	}
	system(fullText);
	sleep(1);
    exit(0);
}
