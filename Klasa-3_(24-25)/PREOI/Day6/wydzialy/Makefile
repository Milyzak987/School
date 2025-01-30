CPPFLAGS = -std=c++20 -pedantic -Wall -Wextra -Wformat-security -Wduplicated-cond -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wvla -g3 -O2

all: wyd.e

wydlib.o: wydlib.cpp wydlib.h communication.h
	g++ $(CPPFLAGS) -D__NOPASSWORD wydlib.cpp -c -o wydlib.o

wyd.e: wyd.cpp wydlib.o
	g++ $(CPPFLAGS) wydlib.o wyd.cpp -o wyd.e;

clean:
	rm -f *.e *.o
