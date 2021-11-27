main: main.o profile.o network.o
	g++ --std=c++11 -o main main.o profile.o network.o
	
tests:	tests.o profile.o network.o
	g++ --std=c++11 -o tests tests.o profile.o network.o
	
main.o:	main.cpp profile.h network.h
	g++ --std=c++11 -c main.cpp
	
tests.o: tests.cpp profile.h network.h
	g++ --std=c++11 -c tests.cpp
	
network.o: network.cpp profile.h network.h 
	g++ --std=c++11 -c network.cpp
	
profile.o: profile.cpp profile.h
	g++ --std=c++11 -c profile.cpp
	
clean:
	rm -f main.o tests.o profile.o network.o
