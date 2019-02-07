all: quad

quad: main.cpp
	clang++ main.cpp -o quad
	clang++ randomGenerator.cpp -o random
	clang++ -std=c++11 diffTest.cpp -o diff

fuzzer:
	./fuzz

test: quad
	./test.quad

clean:
	rm -f quad
	rm -f random
	rm -f diff