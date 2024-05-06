# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude
# Linker flags
LDFLAGS=-lreadline

# The build target executable:
TARGET=minios

# Source, Object files
<<<<<<< HEAD
SRCS=kernel/kernel.c kernel/system.c kernel/20192650/fork.c kernel/20192650/ipc.c
=======
SRCS=kernel/kernel.c kernel/system.c kernel/20192650/fork.c kernel/20192650/ipc.c kernel/20192650/ipc.c 
>>>>>>> 3c963fd68c47e345ce0b69d548ccbc6229b64c6d
OBJS=$(SRCS:.c=.o) 

# Include directory
INCLUDE_DIR=include

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# To obtain object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up:
clean:
	rm -f $(OBJS) $(TARGET)
