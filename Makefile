all: run

final: main.o base.o add.o encode.o decode.o filescnt.o get.o ls.o 
	gcc main.o base.o add.o encode.o decode.o filescnt.o get.o ls.o -lm -o final

main.o: main.c 
	gcc -c main.c -o main.o

add.o: add.c 
	gcc -c add.c -o add.o 

encode.o: encode.c 
	gcc -c encode.c -o encode.o 

decode.o: decode.c 
	gcc -c decode.c -o decode.o 

filescnt.o: filescnt.c 
	gcc -c filescnt.c -o filescnt.o 

get.o: get.c 
	gcc -c get.c -o get.o 

ls.o: ls.c 
	gcc -c ls.c -o ls.o 

delete.o: delete.c 
	gcc -c delete.c -o delete.o
base.o: base.c 
	gcc -c base.c -o base.o
header: vdisk_header.h 
	gcc vdisk_header.h

run: final 
	./final

clean: final 
	rm *.o final
