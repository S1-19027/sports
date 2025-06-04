CC = gcc
CFLAGS = -Wall -std=c99

SRCS = main.c sports.c file_io.c
OBJS = $(SRCS:.c=.o)
TARGET = sports_system

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c sports.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean