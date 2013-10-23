#include "model.h"

using namespace std;

Model::Model(){
	cout << "Model created!" <<endl;
	}

void Model::addLetterToAlphabet(string d, string v, string t){
	Letter *letterToAdd = new Letter(d,v,t);
	alphabet.push_back(letterToAdd);
	cout << "Letter added, array size: " << alphabet.size() << endl; 
}

void Model::printLetters(){
	cout << "Array size: " << alphabet.size() << endl;
	for (int i=0; i < alphabet.size(); i++){
		cout << "alphabet[" << i <<"]: d= " << alphabet[i]->getLetterToDisplay() << " v= " << alphabet[i]->getValue() << " t= " << alphabet[i]->getType() << endl;
	}
}

int Model::getAlphabetSize(){
	return alphabet.size();
}

Letter* Model::getLetterAtIndex(int x){
	return alphabet[x];
}

Model::~Model(){
	cout << "Model destroyed!" << endl;
}
