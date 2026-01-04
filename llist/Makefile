CC = gcc
TARGET = list
CFLAGS = -Wall -Wextra -Werror -pedantic
SRC = main.c linked_list.c utils.c
OBJS = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
