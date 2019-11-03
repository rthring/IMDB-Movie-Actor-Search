all: a3.o

a3.o: common.o binary.o title.o name.o principals.o a3.c
	gcc -Wall -ansi -pedantic a3.c common.o binary.o name.o title.o principals.o -o a3.o
	
common.o: common.c
	gcc -Wall -ansi -pedantic common.c -o common.o -c
	
binary.o: common.h binary.c
	gcc -Wall -ansi -pedantic binary.c common.o -o binary.o -c

name.o: binary.h common.h name.c
	gcc -Wall -ansi -pedantic name.c binary.o common.o -o name.o -c

title.o: binary.h common.h title.c
	gcc -Wall -ansi -pedantic title.c binary.o common.o -o title.o -c

principals.o: binary.h common.h principals.c
	gcc -Wall -ansi -pedantic principals.c binary.o common.o -o principals.o -c
	
clean:
	rm *.o