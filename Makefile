all: quad

quad: main.cpp
	clang++ main.cpp -o quad

test: quad
	./test.quad

clean:
	rm -f quad