CC=g++
CFLAGS=-c -Wall -std=c++11 -w -g
SOURCES=main.cpp My_vec.cpp sparsematrix.cpp
LIBS=
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o main
