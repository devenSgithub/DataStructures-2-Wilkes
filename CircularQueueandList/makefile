
CFLAGS = -c -Wall -g
LFLAGS = -g -o assign44

assign44: assign44.o list.o
	g++ assign44.o list.o $(LFLAGS)

assign44.o: assign44.cpp list.h
	g++ $(CFLAGS) assign44.cpp

list.o: list.cpp list.h
	g++ $(CFLAGS) list.cpp

clean:
	rm -f assign44 *.o *~ *#
