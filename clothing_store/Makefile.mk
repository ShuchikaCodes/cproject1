all: customer

customer: customer.o store.o
	gcc -o customer customer.o store.o

customer.o: customer.c store.h
	gcc -c customer.c

store.o: store.c store.h
	gcc -c store.c

clean:
	rm -f *.o customer