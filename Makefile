CC=g++
CFLAGS=-std=c++14 -Wall -O2 -lboost_system -lboost_thread -lgmp
LDFLAGS=
SOURCES=ack.cpp
all: ackermann.o

ackermann.o:ack.cpp
	$(CC) $(CFLAGS) ack.cpp -o ackermann.o
clean:
	rm *.o
