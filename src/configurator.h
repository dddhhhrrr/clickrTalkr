#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include "model.h"
#include "view.h"
#include "controller.h"
#include "display.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Configurator{
	private:
	Model &model;
	View &view;
	Controller &controller;

	public:
	Configurator(Model &m, View &v, Controller &c);
	int configureModel();
	int configureView();
	int configureController();
	Display createDisplay(string skinName);
	int parseLetterString(string &d, string &v, string &t, string l);
	int parseAndConfigure(string l);
	~Configurator();

};

#endif
