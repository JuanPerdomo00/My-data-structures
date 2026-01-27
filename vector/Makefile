CC =gcc
TARGET = vector
CFLAGS = -Wall -Wextra
SRC = main.c vector.c
OBJS = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fmt:
	clang-format -i --style=Google *.[ch]

clean:
	rm -f $(OBJS) $(TARGET)
