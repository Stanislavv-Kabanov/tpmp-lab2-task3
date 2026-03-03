CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic
TARGET = lab2_program

SRCDIR = src
SRCS = $(SRCDIR)/client.c $(SRCDIR)/server.c
OBJS = client.o server.o
HEADERS = $(SRCDIR)/interface.h

all: $(TARGET)

client.o: $(SRCDIR)/client.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $(SRCDIR)/client.c -o client.o

server.o: $(SRCDIR)/server.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $(SRCDIR)/server.c -o server.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
