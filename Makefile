CC=g++
CFLAGS=-O2
LINKER=-lSDL2

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

tetris_ai: $(OBJS)
	$(CC) $(CFLAGS) $(LINKER) -o tetris_ai $(OBJS)

all: tetris_ai

clean:
	rm *.o tetris_ai
