#include "model.h"

using namespace std;

Model::Model(){
	phraseToSay = "";
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
	cout << "\tcurrent word: " <<currentWord << endl;
}

void Model::clearCurrentWord(){
	currentWord = "";
}

void Model::clearPhraseToSay(){
	phraseToSay= "";
}

Model::~Model(){
	cout << "Model destroyed!" << endl;
}
