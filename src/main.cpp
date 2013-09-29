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
	//string prefix="espeak \"";
	//string text="Hi, thanks for using clickerTalker, this is a test";
	//string suffix="\"";
	char *fullText; 
	string value;
	int pin;
	int j = 3;
	
	Model model;
	View view(model);
	Controller controller(view, model);
	Configurator configurator(model);
	configurator.configureModel();
	model.printLetters();
	//fullText = prefix + text + suffix;
	if (controller.readSensor()) cout << "pin = HIGH" << endl;
	else cout << "pin = LOW" << endl;
	//model.loadLetters();

	for (int i = 1000; i >= 0; i--){
		view.setPercentage(i/10);
		view.updateView(!controller.readSensor());
	}
	//system(fullText);
	sleep(1);
    exit(0);
}
