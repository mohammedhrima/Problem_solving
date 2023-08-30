# Define the compiler
# CC = gcc -fsanitize=address -fsanitize=null -g3
CC = gcc
CFLAGS = -fsanitize=address -g3
# Explicitly define the source file

# Name of the output
OUTPUTS = exe
SOURCES = 011.ContainerWithMostWater.c


$(OUTPUTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@
	./exe

all: $(OUTPUTS)
clean:
	rm -f $(OUTPUTS)

fclean: clean

re: clean all
.PHONY: all clean
