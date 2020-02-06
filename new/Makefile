
CFLAGS= --std=c++11 -I. -I/usr/local/include

verb: main.cpp Conjugation.o
	g++ $(CFLAGS) -o $@ $^

all: verb VerbTest QuizzTest
	@echo done

clean:
	rm -f *.o verb

Conjugation.o: Conjugation.cpp Conjugation.h Verb.h
	g++ $(CFLAGS) -c Conjugation.cpp
