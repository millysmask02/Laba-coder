
encoder:  stringutils.a encoder.o
    gcc  encoder.o -L. -lstr -o encoder

stringutils.a: stringutils.o
	ar -rc stringutils.a stringutils.o

stringutils.o:
	gcc -c stringutils.c -std=c99

encoder.o:
	gcc -c encoder.c -std=c99

clean:
	rm -rf *.o *.a encoder

