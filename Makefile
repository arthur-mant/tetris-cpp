CC=g++
CFLAGS=-O2
LINKER=-lSDL2 -lSDL2_ttf

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

tetris_ai: $(OBJS)
	$(CC) $(CFLAGS) -o tetris_ai $(OBJS) $(LINKER) 

all: tetris_ai

clean:
	rm *.o tetris_ai
