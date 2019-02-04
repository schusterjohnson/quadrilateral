all: quad

quad: main.cpp
	clang++ main.cpp -o quad
	clang++ randomGenerator.cpp -o random

fuzz:
	./fuzz.quad

test: quad
	./test.quad

clean:
	rm -f quad
	rm -f random