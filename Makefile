SRC = board.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

LDFLAGS = -lm

.cpp.o:
	$(CXX) -g -c -Wall $<

main: $(OBJ)
	$(CXX) -o $@ $(LDFLAGS) $^

run: main
	./main

.PHONY: clean
clean:
	rm -f $(OBJ) main
