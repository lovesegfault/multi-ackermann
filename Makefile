CC=g++
CFLAGS=-Wall -Wextra -Wformat-security -Wmissing-include-dirs -Wuninitialized -Wtrampolines -Wconversion -Wuseless-cast -Wlogical-op -Wctor-dtor-privacy -Wold-style-cast -Wno-reorder -Wno-unused-parameter -Werror=delete-non-virtual-dtor -Werror=return-type -Werror=implicit -std=c++14 -O2 -lgmpxx -lgmp
SOURCES=ack.cpp
all: ackermann.o

ackermann.o:ack.cpp
	$(CC) $(CFLAGS) ack.cpp -o ackermann
clean:
	rm *.o
