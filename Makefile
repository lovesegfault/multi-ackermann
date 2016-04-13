CC=g++
CFLAGS=-std=c++14 -Wall -lboost_system -lboost_thread
LDFLAGS=
SOURCES=ack.cpp, threadtest.cpp
all: ackermann.o threadtest.o

ackermann.o:ack.cpp
	$(CC) $(CFLAGS) ack.cpp -o ackermann.o
threadtest.o:threadtest.cpp
	$(CC) $(CFLAGS) threadtest.cpp -o threadtest.o
clean:
	rm *.o
