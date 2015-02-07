include ../../../makefile.inc

CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

all: $(OBJ_FILES)
	$(ARC) $(ARCFLAGS) libutil.a $(OBJ_FILES)
	mkdir -p ../../libs
	cp libutil.a ../../libs

%.o: %.cpp
	$(CC) $(CFLAGS) $(LIB_INCLUDES) -c -o $@ $<

clean:
	rm -f libutil.a
	rm -f *.o
