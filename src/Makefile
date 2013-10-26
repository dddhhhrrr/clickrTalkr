all: clickrTalkr

OPENVGLIBDIR=/home/pi/openvg
WIRINGPILIBDIR=/home/pi/wiringPi/wiringPi

clickrTalkr: model.o view.o controller.o configurator.o letter.o main.o display.o skinBubbly.o clicker.o letterController.o $(OPENVGLIBDIR)/libshapes.o $(OPENVGLIBDIR)/oglinit.o
	g++ -o clickrTalkr view.o main.o model.o controller.o configurator.o letter.o display.o skinBubbly.o clicker.o letterController.o $(OPENVGLIBDIR)/libshapes.o $(OPENVGLIBDIR)/oglinit.o -L/opt/vc/lib -L/opt/vc/include -lGLESv2 -ljpeg  -lwiringPi -lpthread -lm -L/usr/local/lib
		
view.o: view.cpp view.h
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I.. -c view.cpp 
	
display.o: display.cpp display.h
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I.. -c display.cpp

main.o: main.cpp
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/phtreads -I.. -c main.cpp

model.o: model.cpp model.h
	g++ -I/opt/vc/include -c model.cpp
	
letter.o: letter.cpp letter.h
	g++ -I/opt/vc/include -c letter.cpp
	
configurator.o: configurator.cpp configurator.h
	g++ -I/opt/vc/include -I.. -c configurator.cpp
	
controller.o: controller.cpp controller.h
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I$(WIRINGPILIBDIR) -I.. -c controller.cpp 

skinBubbly.o: skinBubbly.cpp skinBubbly.h
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I.. -c skinBubbly.cpp

clicker.o: clicker.cpp clicker.h
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I$(WIRINGPILIBDIR) -I.. -c clicker.cpp
	
letterController.o: letterController.cpp letterController.h
	g++ -c letterController.cpp
