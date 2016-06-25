CC=g++
CFLAGS=-std=c++14 -Wall -O2 -lgmpxx -lgmp
LDFLAGS=
SOURCES=ack.cpp
all: ackermann.o

ackermann.o:ack.cpp
	$(CC) $(CFLAGS) ack.cpp -o ackermann.o
clean:
	rm *.o
