BUILD_DIR = build 

lv: lotka-volterra.o equations.o 
	c++ -o lv lotka-volterra.o equations.o -ltrapfpe -lpgplot -lcpgplot -lX11 -lm  

lotka-volterra.o: lotka-volterra.cpp 
	c++ -o lotka-volterra.o -c lotka-volterra.cpp 

equations.o: equations.cpp equations.h 
	c++ -o equations.o -c equations.cpp  

clean: 
	rm *.o lv 