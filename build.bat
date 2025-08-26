g++ -c Solver.cpp       
g++ -c TesterReader.cpp
g++ -c InputOutput.cpp  
g++ -c main.cpp
g++ TesterReader.o Solver.o InputOutput.o main.o -o hello
.\hello