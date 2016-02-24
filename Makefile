all : 11512099 11512099test


11512099 : src/main.o src/Image.o src/Pixel.o

	gcc main.o Image.o Pixel.o -o 11512099.out -lm

main.o : src/main.c src/Image.h src/Pixel.h

	gcc -c -Wall -ansi -pedantic src/main.c -lm 
11512099test : src/mainTest.o src/Image.o src/Pixel.o

	gcc src/mainTest.o Image.o Pixel.o -o 11512099test.out -lm

mainTest.o : src/mainTest.c src/Image.h src/Pixel.h

	gcc -c -Wall -ansi -pedantic src/mainTest.c -lm

Image.o : src/Image.c src/Image.h src/Pixel.h
	gcc -c -Wall -ansi -pedantic src/Image.c


Pixel.o : src/Pixel.c src/Pixel.h
	gcc -c -Wall -ansi -pedantic src/Pixel.c


clean :
	-rm *.o *~


veryclean : clean
	-rm *.ex
