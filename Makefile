INCLUDES = -I./include -I../include
CFLAGS = -Wall -g2
ARCFLAGS = -cvq
CC = g++
ARC = ar
SRC = src
LIBS = -L../lib_archive -L../extlib_archive
BIN = ./bin

all: test_sample

test_sample: test_sample.o
	$(CC) -o $(BIN)/test_sample $(SRC)/test_sample.o $(LIBS) -lutil -llog4cpp -pthread

%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $(SRC)/$@ $<

clean:
	rm -f $(BIN)/*
	rm $(SRC)/*.o
