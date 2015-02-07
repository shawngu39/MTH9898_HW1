include ./makefile.inc

all: lib_dep serial_scrub

lib_dep:
	$(MAKE) -C ./lib/src

serial_scrub: serial_scrub.o TradeRecord.o
	mkdir -p bin
	$(CC) -o $(BIN)/serial_scrub $(SRC)/serial_scrub.o $(SRC)/TradeRecord.o $(LIBS) -lutil -llog4cpp -pthread

%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(APPL_INCLUDES) -c -o $(SRC)/$@ $<

clean:
	rm -f $(BIN)/*
	rm -f $(SRC)/*.o
	rm -f lib/libs/*.a
	$(MAKE) -C ./lib/src clean
