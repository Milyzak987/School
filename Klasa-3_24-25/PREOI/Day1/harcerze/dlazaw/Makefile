CPPFLAGS = -std=c++20 -pedantic -Wall -Wextra -Wformat-security -Wduplicated-cond -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wvla -g3 -O2

all: har.e

harlib-debug.o: harlib.cpp harlib.h communication.h config.h
	g++ $(CPPFLAGS) -D__NOPASSWORD -D__DEBUG_COMMUNICATION harlib.cpp -c -o harlib-debug.o

harlib-nodebug.o: harlib.cpp harlib.h communication.h config.h
	g++ $(CPPFLAGS) -D__NOPASSWORD harlib.cpp -c -o harlib-nodebug.o

har.e: har.cpp harlib-debug.o harlib-nodebug.o
	if [ "$(DEBUG)" = "1" ]; then\
	    g++ $(CPPFLAGS) harlib-debug.o har.cpp -o har.e;\
	else\
	    g++ $(CPPFLAGS) harlib-nodebug.o har.cpp -o har.e;\
    fi

clean:
	rm -f *.e *.o
