#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

//the configurator class is in charge of configuring all (or at least, most) of the classes that make clickrTalkr

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
	int parseConfigurationLine(string &attr, string &val, string l);
	~Configurator();

};

#endif
