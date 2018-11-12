
CFLAGS= --std=c++11 -I. -I/usr/local/include

verb: main.cpp Verb.o Quizz.o Grammar.o
	g++ $(CFLAGS) -o $@ $^

all: verb VerbTest QuizzTest
	@echo done

runtest: VerbTest QuizzTest
	./VerbTest
	./QuizzTest

clean:
	rm -f *.o VerbTest QuizzTest verb

Verb.o: Verb.cpp Verb.h Grammar.h
	g++ $(CFLAGS) -c Verb.cpp

Quizz.o: Quizz.cpp Quizz.h Grammar.h
	g++ $(CFLAGS) -c Quizz.cpp

Grammar.o: Grammar.cpp Grammar.h
	g++ $(CFLAGS) -c Grammar.cpp

VerbTest: Verb.o Grammar.o VerbTest.cpp
	g++ $(CFLAGS) Verb.o Grammar.o VerbTest.cpp -o $@ -lgtest

QuizzTest: Quizz.o Verb.o Grammar.o QuizzTest.cpp
		g++ $(CFLAGS) Quizz.o Verb.o Grammar.o QuizzTest.cpp -o $@ -lgtest
