CC = gcc
CFLAGS = -I/usr/include/SDL2
LDFLAGS = -lSDL2 -lSDL2_ttf -ldl

cnake: main.o controls.o display.o food.o snake.o ui.o
	$(CC) main.o controls.o display.o food.o snake.o ui.o -o cnake $(LDFLAGS)

main.o: main.c 
	$(CC) -c main.c $(CFLAGS)

display.o: src/display.c src/display.h 
	$(CC) -c src/display.c $(CFLAGS)

food.o: src/food.c src/food.h 
	$(CC) -c src/food.c $(CFLAGS)

snake.o: src/snake.c src/snake.h 
	$(CC) -c src/snake.c $(CFLAGS)

ui.o: src/ui.c src/ui.h 
	$(CC) -c src/ui.c $(CFLAGS)

controls.o: src/controls.c src/controls.h 
	$(CC) -c src/controls.c $(CFLAGS)

clean:
	rm -f *.o cnake
