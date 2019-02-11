CC = gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)
APP_NAME = hello

all: main.o menu.o date_functions.o file_functions.o menu_functions.o menu_functions_actions.o
	$(CC) -o $(APP_NAME) main.o menu.o date_functions.o file_functions.o menu_functions.o menu_functions_actions.o $(LIBS)

main.o: main.c structures.h
	$(CC) -c main.c $(CFLAGS)

menu.o: menu.c menu.h structures.h
	$(CC) -c menu.c $(CFLAGS)

date_functions.o: date_functions.c date_functions.h structures.h
	$(CC) -c date_functions.c $(CFLAGS)

file_functions.o: file_functions.c file_functions.h structures.h
	$(CC) -c file_functions.c $(CFLAGS)

menu_functions.o: menu_functions.c menu_functions.h structures.h
	$(CC) -c menu_functions.c $(CFLAGS)

menu_functions_actions.o: menu_functions_actions.c menu_functions_actions.h structures.h
	$(CC) -c menu_functions_actions.c $(CFLAGS)

clean:
	rm -f *.o $(APP_NAME)
