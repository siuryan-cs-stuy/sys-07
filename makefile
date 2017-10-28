all: rand.c
	gcc -o rand rand.c

run: all
	./rand

clean:
	rm *.o
	rm *~
	rm foo
