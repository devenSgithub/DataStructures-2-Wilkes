
CFLAGS = -c -Wall -g
LFLAGS = -g -o assigncolor

assigncolor: assigncolor.o color.o
	g++ assigncolor.o color.o $(LFLAGS)

assigncolor.o: assigncolor.cpp color.h
	g++ $(CFLAGS) assigncolor.cpp

color.o: color.cpp color.h
	g++ $(CFLAGS) color.cpp

clean:
	rm -f assigncolor *.o *~ *#