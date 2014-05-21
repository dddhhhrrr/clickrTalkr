#include "model.h"

using namespace std;

Model::Model(){
	phraseToSay = "";

	setSuggestion(0, "prueba");
	setSuggestion(1, "prueba1");
	setSuggestion(2, "prueba2");
	setSuggestion(3, "prueba3");

	cout << "Model created!" <<endl;
	cout << getSuggestion(0) << endl;
	cout << getSuggestion(1) << endl;
	cout << getSuggestion(2) << endl;
	cout << getSuggestion(3) << endl;
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

void Model::backspace(){
	if (phraseToSay.size() > 0)
	phraseToSay = phraseToSay.substr(0, phraseToSay.size()-1);
}

Letter* Model::getLetterAtIndex(int x){
	return alphabet[x];
}

string Model::getCurrentWord(){
	return currentWord;
}

void Model::setCurrentWord(string w){
	currentWord = w;
}

string Model::getPhraseToSay(){
	return phraseToSay;
}

void Model::setPhraseToSay(string ph){
	phraseToSay = ph;
}

void Model::addLetterToPhraseToSay(string l){
	phraseToSay.append(l);
}

void Model::addLetterToCurrentWord(string l){
		currentWord.append(l);
}

void Model::updateCurrentWord(string l){
	char letterToTest = (char)l[0];
	if ( (letterToTest >= 'a' && letterToTest <= 'z') || (letterToTest >= 'A' && letterToTest <= 'Z') ){
		currentWord.append(l);
	}
	else if (l == "~"){
		if (currentWord.size() > 0)
		currentWord = currentWord.substr(0, currentWord.size()-1);
	}
	else clearCurrentWord();
	cout << "current word: " <<currentWord << endl;
}

void Model::clearCurrentWord(){
	currentWord = "";
}

void Model::clearPhraseToSay(){
	phraseToSay= "";
}

void Model::setSuggestion(int index, char* str){
	strcpy(&suggestion[index][0], str);
}

string Model::getSuggestion(int index){
	string test;
	strcpy(&test[0], &suggestion[index][0]);
	return test;
}

Model::~Model(){
	cout << "Model destroyed!" << endl;
}
