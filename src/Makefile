CFLAGS=-g -ansi -pedantic -Wall -Werror -D_XOPEN_SOURCE=600
LDFLAGS=-pthread 
CC=gcc
OBJECTS=MsgQueueMain.o MsgQueue.o Queue.o MyMalloc.o
TARGET=MsgQueueMain

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CC) $(OBJECTS) -o $@$(LDFLAGS)

include depends

depends:
    $(CC) -MM $(OBJECTS:.o=.c) > depends

clean:
    rm ./$(TARGET) *.o