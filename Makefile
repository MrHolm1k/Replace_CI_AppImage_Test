CC = gcc
TARGET = replace
CFLAGS = -Wall -Wextra -std=c99
SOURCES = main.c replace.c
# just replacement: main.c->main.o
OBJECTS = $(SOURCES:.c=.o)

build: $(TARGET)

# debug can be seperated or included like this
debug: CFLAGS += -g
debug: clean build

# can type $@ $^ or $(TARGET)->$@ $(OBJECTS)->$^
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# can type $(SOURCES) ((THIS IS VERY BAD DON'T DO THAT!!)) or $<-take only fist dependances, $^ - take all fist
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# I don't wanna delete something important so no -f
clean:
	-rm $(OBJECTS) $(TARGET)
