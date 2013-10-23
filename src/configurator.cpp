#include "configurator.h"

using namespace std;

Configurator::Configurator(Model &m, View &v, Controller &c):model(m), view(v), controller(c){
	cout << "Configurator created!" << endl;
}

Configurator::~Configurator(){
	cout << "Configurator destroyed" << endl;
	
}

int Configurator::configureModel(){
	string line;
	ifstream inputFile("alphabet.txt");
	if (inputFile.is_open())
	{
		while(getline(inputFile,line)){
			string parsedLetterToDisplay;
			string parsedValue;
			string parsedType;
			parseLetterString(parsedLetterToDisplay, parsedValue, parsedType, line);
			model.addLetterToAlphabet(parsedLetterToDisplay, parsedValue, parsedType);
		}
		cout << "Model configured!" << endl;
		inputFile.close();
		return 1;
	}
	else cout << "alphabet.txt not found..." << endl;
	return -1;
}

int Configurator::configureView(){
	string line;
	ifstream inputFile("settings.txt");
	if (inputFile.is_open())
	{
		while(getline(inputFile,line)){
			parseAndConfigure(line);
		}
		cout << "View configured!" << endl;
		inputFile.close();
		return 1;
	}
	else cout << "settings.txt not found..." << endl;
	return -1;
}

int Configurator::configureController(){
}

int Configurator::parseLetterString(string &d, string &v, string &t, string l){
istringstream iss(l);
getline(iss,d,',');
getline(iss,v,',');
getline(iss,t,',');
return 1;
}

int Configurator::parseAndConfigure(string l){
string attributeToConfigure, value;
istringstream iss(l);
getline(iss, attributeToConfigure, '=');
getline(iss, value, '\n');
cout << "Attribute to configure: " << attributeToConfigure << ", value: " << value << endl;
}

Display Configurator::createDisplay(string skinName){
	//Display d = iDisplay.getDisplay(skinName);
	//return d;
}
