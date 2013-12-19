#include "configurator.h"

using namespace std;

Configurator::Configurator(Model &m, View &v, Controller &c):model(m), view(v), controller(c){
	cout << "Configurator created!" << endl;
	configureModel();
	configureView();
	configureController();
}

Configurator::~Configurator(){
	cout << "Configurator destroyed" << endl;
	
}

/*   this method reads a textfile (alphabet.txt) and creates a vector  of objects of type Letter which will be used to create the virtual keyboard   */
int Configurator::configureModel(){
	string line;
	ifstream inputFile("alphabet.txt");
	if (inputFile.is_open())
	{
		while(getline(inputFile,line)){ //for each line in the file, parse it and return the values as parsedLetterToDisplay, parsedValue and parsedType to create a new Letter in the model
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
	else cout << endl << "alphabet.txt not found..." << endl;
	exit(0);
	return -1;
}

/*   this method reads settings.txt and configure some values on the view depending on the content of the textfile   */
int Configurator::configureView(){
	string line;
	ifstream inputFile("settings.txt");
	if (inputFile.is_open())
	{
		while(getline(inputFile,line)){
			string attribute, value;
			parseConfigurationLine(attribute, value, line);
			if (attribute == "number of rows") view.setNumberOfRows(atoi(&value[0]));
			if (attribute == "number of columns") view.setNumberOfColumns(atoi(&value[0]));
			if (attribute == "skin") {}//view.doSomething();
		}
		cout << "View configured!" << endl;
		inputFile.close();
		return 1;
	}
	else cout << endl << "settings.txt not found..." << endl;
	exit(0);
	return -1;
}

/* this method will configure the controller depending on different values on the model and the view   */
int Configurator::configureController(){
	controller.setNumberOfRows(view.getNumberOfRows());
	controller.setNumberOfColumns(view.getNumberOfColumns());
	for (int i = 0; i < model.getAlphabetSize(); i++){
		controller.addButtonToVector(model.getLetterAtIndex(i)->getValue(), model.getLetterAtIndex(i)->getType());
	}
}

int Configurator::parseLetterString(string &d, string &v, string &t, string l){
istringstream iss(l);
getline(iss,d,',');
getline(iss,v,',');
getline(iss,t,',');
return 1;
}

int Configurator::parseConfigurationLine(string &attr, string &val, string l){
istringstream iss(l);
getline(iss, attr, '=');
getline(iss, val, '\n');
cout << "Attribute to configure: " << attr << ", value: " << val << endl;
}

Display Configurator::createDisplay(string skinName){
	//Display d = iDisplay.getDisplay(skinName);
	//return d;
}
