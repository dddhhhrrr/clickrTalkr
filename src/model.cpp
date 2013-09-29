#include "model.h"

using namespace std;

Model::Model(){}

void Model::loadLetters(){
	vector<string> testVector;
	string line;
	ifstream myFile("alphabet.txt");
	if (myFile.is_open())
	{
		while(getline(myFile,line)){
			testVector.push_back(line);
		}
		myFile.close();
		for (int i=0; i < testVector.size(); i++)
			cout << testVector[i] << endl;
		cout << "The size of the Vector is: " << testVector.size() << endl;
	}
}

void Model::addLetterToAlphabet(string d, string v, string t){
	Letter letterToAdd(d,v,t);
	alphabet.push_back(letterToAdd);
	cout << "Letter added, array size: " << alphabet.size() << endl;
}

void Model::printLetters(){
	cout << "Array size: " << alphabet.size() << endl;
	for (int i=0; i < alphabet.size(); i++){
		cout << "alphabet[" << i <<"]: d= " << alphabet[i].getLetterToDisplay() << " v= " << alphabet[i].getValue() << " t= " << alphabet[i].getType() << endl;
	}
}
