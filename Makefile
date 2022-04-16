CXX=g++
CXXFLAGS= -I. -O3 -std=c++11 -fPIC

INC= $(wildcard *.h)
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: main 

%.o: %.cpp $(INC)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ) 
	$(CXX) -o $@ $^ $(CXXFLAGS) -lncurses

.PHONY: run clean

clean:
	rm -f *.o ./main
 