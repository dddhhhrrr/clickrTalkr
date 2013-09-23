all: clickrTalkr

OPENVGLIBDIR=/home/pi/openvg
WIRINGPILIBDIR=/home/pi/wiringPi/wiringPi

clickrTalkr: model.o view.o controller.o main.o $(OPENVGLIBDIR)/libshapes.o $(OPENVGLIBDIR)/oglinit.o
	g++ -o clickrTalkr view.o main.o model.o controller.o $(OPENVGLIBDIR)/libshapes.o $(OPENVGLIBDIR)/oglinit.o -L/opt/vc/lib -L/opt/vc/include -lGLESv2 -ljpeg  -lwiringPi -lpthread -lm -L/usr/local/lib
		
view.o: view.cpp view.h
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I.. -c view.cpp 

main.o: main.cpp
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/phtreads -I.. -c main.cpp

model.o: model.cpp model.h
	g++ -c model.cpp
	
controller.o: controller.cpp controller.h
	g++ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I$(WIRINGPILIBDIR) -I.. -c controller.cpp 
