# Define the compiler
# CC = gcc -fsanitize=address -fsanitize=null -g3
CC = gcc

# Explicitly define the source file

# Name of the output
OUTPUTS = exe
SOURCES = 100.Same_Tree.c


$(OUTPUTS): $(SOURCES)
	$(CC) "$<" -o "$@"

all: $(OUTPUTS)
clean:
	rm -f $(OUTPUTS)

fclean: clean

re: clean all
.PHONY: all clean
