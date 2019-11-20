all: common.o binary.o name.o title.o principals.o a3.o a3

a3: a3.o common.o binary.o name.o title.o principals.o
	gcc a3.o common.o binary.o name.o title.o principals.o -o a3

a3.o: common.o binary.o title.o name.o principals.o a3.c
	gcc -Wall -ansi -pedantic a3.c -o a3.o -c
	
common.o: common.c
	gcc -Wall -ansi -pedantic common.c -o common.o -c
	
binary.o: common.h binary.c
	gcc -Wall -ansi -pedantic binary.c -o binary.o -c

name.o: binary.h common.h name.c
	gcc -Wall -ansi -pedantic name.c  -o name.o -c

title.o: binary.h common.h title.c
	gcc -Wall -ansi -pedantic title.c -o title.o -c

principals.o: binary.h common.h principals.c
	gcc -Wall -ansi -pedantic principals.c -o principals.o -c
	
clean:
	rm *.o