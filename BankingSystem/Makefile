CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = bank
OBJS = main.o queue.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

rebuild: clean all

.PHONY: all clean run rebuild
