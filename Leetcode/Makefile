# Define the compiler
CC = gcc

# Explicitly define the source file

# Name of the output
OUTPUTS = a.out
SOURCES = 459.\ Repeated\ Substring\ Pattern.c


$(OUTPUTS): $(SOURCES)
	$(CC) "$<" -o "$@"

all: $(OUTPUTS)
clean:
	rm -f $(OUTPUTS)

re: clean all
.PHONY: all clean
