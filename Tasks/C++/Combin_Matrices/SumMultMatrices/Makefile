CXX = g++ -std=c++11
EXECUTABLE = output
OBJECTS = main.o Matrix.o

$(EXECUTABLE): $(OBJECTS)
	$(CXX) main.o Matrix.o -o $(EXECUTABLE)

main.o: main.cpp Matrix.h
	$(CXX) -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) -c Matrix.cpp

clean:
	rm *.o $(EXECUTABLE)
