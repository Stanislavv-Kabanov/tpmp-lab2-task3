CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic
TARGET = note2_program

SRCDIR = src
SRCS = $(SRCDIR)/main.c $(SRCDIR)/note2_server.c
OBJS = main.o note2_server.o
HEADERS = $(SRCDIR)/note2.h

all: $(TARGET)

main.o: $(SRCDIR)/main.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $(SRCDIR)/main.c -o main.o

note2_server.o: $(SRCDIR)/note2_server.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $(SRCDIR)/note2_server.c -o note2_server.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
