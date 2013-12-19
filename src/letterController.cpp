#include "letterController.h"

using namespace std;

LetterController::LetterController(Model &m, string v, string t):model(m){
	value = v;
	type = t;
	cout << "letterController created!" << endl;
}

LetterController::~LetterController(){
	cout << "letterController destroyed!" << endl;
}

void LetterController::execute(){
	if (value == "~") model.backspace();
	else model.addLetterToPhraseToSay(value);
}	

