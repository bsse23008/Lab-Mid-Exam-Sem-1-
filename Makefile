all: run

compRun:
	g++ -std=c++11 main.cpp student.cpp -o r.out

compTest:
	g++ -std=c++11 student.cpp -o a.out

test: clean compTest
	./a.out

run: clean compRun
	./r.out

clean:
	rm -f *.out
