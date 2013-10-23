#include "view.h"

View::View(Model &m):model(m),display(m){
	cout << "View created!" << endl;
}

int View::updateView(int i, int j){
	display.setPercentage(i);
	display.updateView(j);
	cout << "view.updateView()"<<endl;
}

View::~View(){
	cout << "View destroyed!" << endl;
}
