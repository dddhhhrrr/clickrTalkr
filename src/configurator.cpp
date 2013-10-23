#include "configurator.h"

using namespace std;

Configurator::Configurator(Model &m):model(m){
	cout << "Configurator created!" << endl;
}

Configurator::~Configurator(){
	cout << "Configurator destroyed" << endl;
	
}

void Configurator::configureModel(){
	string line;
	ifstream myFile("alphabet.txt");
	if (myFile.is_open())
	{
		while(getline(myFile,line)){
			string parsedLetterToDisplay;
			string parsedValue;
			string parsedType;
			parseString(parsedLetterToDisplay, parsedValue, parsedType, line);
			model.addLetterToAlphabet(parsedLetterToDisplay, parsedValue, parsedType);
		}
		cout << "Model configured!" << endl;
		myFile.close();
	}
}

void Configurator::parseString(string &d, string &v, string &t, string l){
istringstream iss(l);
getline(iss,d,',');
getline(iss,v,',');
getline(iss,t,',');
}

Display Configurator::createDisplay(string skinName){
	//Display d = iDisplay.getDisplay(skinName);
	//return d;
}
