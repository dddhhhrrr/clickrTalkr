#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <sstream>

#include "model.h"
#include "display.h"
#include "skinBubbly.h"


class View{
	private:
		Model &model;
		Display display;

	public:
		View(Model &m);
		int updateView(int i, int j);
		~View();
		

};

#endif
