CC=g++
CFLAGS=-std=c++14 -Wall -lboost_system -lboost_thread
LDFLAGS=
SOURCES=ack.cpp, threadtest.cpp
all: ackermann.o threadtest.o

ackermann.o:ack.cpp
	$(CC) $(CFLAGS) ack.cpp -o ackermann.o
clean:
	rm *.o
