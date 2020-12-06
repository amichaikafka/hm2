CC=gcc
AR=ar 
FLAGS=-Wall -g

 all:   mains mybanks 

 mains: main.o mybanks
	gcc $(FLAGS) -o mains main.o libmybank.a 

mybanks: myBank.o 
	ar -rcs libmybank.a myBank.o 

main.o: main.c myBank.h
	gcc $(FLAGS) -c main.c 
myBank.o: myBank.c  myBank.h
	gcc $(FLAGS) -c myBank.c 
	
PHONY: clean all

clean:
	rm -f *.o *.a 	mains 	