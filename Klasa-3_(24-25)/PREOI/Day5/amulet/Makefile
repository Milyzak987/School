CPPFLAGS = -std=c++20 -pedantic -Wall -Wextra -Wformat-security -Wduplicated-cond -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wvla -g3 -O2

all: szy.e

szylib-debug.o: szylib.cpp szylib.h communication.h
	g++ $(CPPFLAGS) -D__NOPASSWORD -D__DEBUG_COMMUNICATION szylib.cpp -c -o szylib-debug.o

szylib-nodebug.o: szylib.cpp szylib.h communication.h
	g++ $(CPPFLAGS) -D__NOPASSWORD szylib.cpp -c -o szylib-nodebug.o

szy.e: szy.cpp szylib-debug.o szylib-nodebug.o
	if [ "$(DEBUG)" = "1" ]; then\
	    g++ $(CPPFLAGS) szylib-debug.o szy.cpp -o szy.e;\
	else\
	    g++ $(CPPFLAGS) szylib-nodebug.o szy.cpp -o szy.e;\
    fi

clean:
	rm -f *.e *.o
