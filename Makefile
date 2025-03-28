CC := gcc

football.exe: football.o football_main.o
	$(CC) -o football.exe football.o football_main.o

football.o: football.c football.h
	$(CC) -c football.c

football_main.o: football_main.c football.h
	$(CC) -c football_main.c

temperature.exe: temperature.o temperature_main.o
	$(CC) -o temperature.exe temperature.o temperature_main.o

temperature.o: temperature.c temperature.h
	$(CC) -c temperature.c

temperature_main.o: temperature_main.c temperature.h
	$(CC) -c temperature_main.c

clean:
	rm -f *.o football.exe temperature.exe

all: football.exe temperature.exe