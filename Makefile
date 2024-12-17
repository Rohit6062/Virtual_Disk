all: run

comp = gcc

final: main.o base.o add.o encode.o decode.o filescnt.o get.o ls.o user_command.o
	$(comp) main.o base.o add.o encode.o decode.o filescnt.o get.o ls.o user_command.o -lm -o final

main.o: main.c 
	$(comp) -c main.c -o main.o

add.o: add.c 
	$(comp) -c add.c -o add.o 

encode.o: encode.c 
	$(comp) -c encode.c -o encode.o 

decode.o: decode.c 
	$(comp) -c decode.c -o decode.o 

filescnt.o: filescnt.c 
	$(comp) -c filescnt.c -o filescnt.o 

get.o: get.c 
	$(comp) -c get.c -o get.o 

ls.o: ls.c 
	$(comp) -c ls.c -o ls.o 

delete.o: delete.c 
	$(comp) -c delete.c -o delete.o

base.o: base.c 
	$(comp) -c base.c -o base.o

user_command.o: user_command.c 
	$(comp) -c user_command.c -o user_command.o

header: vdisk_header.h 
	$(comp) vdisk_header.h

run: final 
	./final

clean: final 
	rm *.o final
