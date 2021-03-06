CPP = g++
CPPFLAGS = -Wall -g -O3 -c
LDFLAGS = -g -larmadillo -llapack -lblas

OBJ = openRDS.o rds.o config.o
BIN = openRDS
MSC = results.dat a.out

prog: $(OBJ) 
	$(CPP) -o $(BIN) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $<

.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ) $(MSC)
