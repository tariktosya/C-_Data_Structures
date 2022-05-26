hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Cevir.o -c ./src/Cevir.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp 
	g++ -I ./include/ -o ./lib/algoritma.o -c ./src/algoritma.cpp 
	g++ -I ./include/ -o ./bin/calistir ./lib/algoritma.o ./lib/Node.o ./lib/Cevir.o ./src/calistir.cpp
	
calistir:
	./bin/calistir