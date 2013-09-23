#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "model.h"
#include "view.h"
#include "controller.h"

using namespace std;

int main() {
	char a;
	string value;
	int pin;
	int j = 3;
	Model model;
	View view(model);
	Controller controller(view, model);
	if (controller.readSensor()) cout << "pin = HIGH" << endl;
	else cout << "pin = LOW" << endl;
	model.loadLetters();

	for (int i = 1000; i >= 0; i--){
		view.setPercentage(i/10);
		view.updateView(!controller.readSensor());
	}
	system("espeak \"Hi, thanks for using ClickerTalker, this is a test\"");
	sleep(1);
    exit(0);
}
