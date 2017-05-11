all: clean ctimer cpptimer

ctimer:
	gcc -o ctimer test.c

cpptimer:
	g++ -std=c++11 -o cpptimer test.cpp

test:
	@echo "c timer"
	./ctimer
	@echo "cpp timer"
	./cpptimer

clean:
	rm -f *.o
	rm -f ctimer cpptimer
