hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/ADD.o -c ./src/ADD.cpp
	g++ -I ./include/ -o ./bin/calistir ./lib/Stack.o ./lib/Node.o ./lib/ADD.o ./src/calistir.cpp
	
calistir:
	./bin/calistir