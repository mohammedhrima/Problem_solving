# Define the compiler
CC = gcc -fsanitize=address -g3

# Explicitly define the source file

# Name of the output
OUTPUTS = a.out
SOURCES = 605.Can_Place_Flowers.c


$(OUTPUTS): $(SOURCES)
	$(CC) "$<" -o "$@"

all: $(OUTPUTS)
clean:
	rm -f $(OUTPUTS)

re: clean all
.PHONY: all clean
