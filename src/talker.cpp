#include "talker.h"

using namespace std;

Talker::Talker(){
	
}

Talker::Talker(string s, string l){
	if (s == "eSpeak"){
		if (l == "spanish"){
			setPrefix("espeak -ves-la+f5 \"");
			setSuffix("\"");
		}
		
		else {
			setPrefix("espeak \"");
			setSuffix("\"");
		}
	}
}

Talker::~Talker(){
	
}

string Talker::getPrefix(){
	return prefix;
}

void Talker::setPrefix(string p){
	prefix = p;
}

string Talker::getTextToSay(){
	return textToSay;
}

void Talker::setTextToSay(string t){
	textToSay = t;
}

string Talker::getSuffix(){
	return suffix;
}

void Talker::setSuffix(string s){
	suffix = s;
}

void Talker::sayPhrase(){
	char *fullText;
	string fullTextString = prefix + textToSay + suffix;
	fullText = &fullTextString[0];
	system(fullText);
}

void Talker::sayPhrase(string t){
	char *fullText;
	string fullTextString = prefix + t + suffix;
	fullText = &fullTextString[0];
	system(fullText);
}
