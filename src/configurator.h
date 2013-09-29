#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include "model.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Configurator{
	private:
	Model model;

	public:
	Configurator(Model m);
	//loadAlphabet();
	void configureModel();
	void parseString(string &d, string &v, string &t, string l);
	~Configurator();

};

#endif
