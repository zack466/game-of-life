src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lm

main: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

run: main
	./main

.PHONY: clean
clean:
	rm -f $(obj) main
