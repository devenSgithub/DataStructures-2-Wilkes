
CFLAGS = -c -Wall -g
LFLAGS = -g -o assign41

assign41: assign41.o list.o
	g++ assign41.o list.o $(LFLAGS)

assign41.o: assign41.cpp list.h
	g++ $(CFLAGS) assign41.cpp

list.o: list.cpp list.h
	g++ $(CFLAGS) list.cpp

clean:
	rm -f assign41 *.o *~ *#