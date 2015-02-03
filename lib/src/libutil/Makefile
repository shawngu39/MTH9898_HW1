include ../makefile.inc

CPP_FILES := $(wildcard $(SRC)/*.cpp)
OBJ_FILES := $(addprefix $(SRC)/,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(OBJ_FILES)
	$(ARC) $(ARCFLAGS) libutil.a $(OBJ_FILES)
	cp libutil.a ../../lib_archive

$(SRC)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm libutil.a
	rm $(SRC)/*.o
