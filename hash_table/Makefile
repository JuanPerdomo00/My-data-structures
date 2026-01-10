CC = gcc
TARGET = hash_table
CFLAGS = -Wall -Wextra
LDFLAGS = -lm
SRC = main.c hash_table.c prime.c utils.c
OBJS = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fmt:
	clang-format -i --style=Google *.[ch]

clean:
	rm -f $(OBJS) $(TARGET)
