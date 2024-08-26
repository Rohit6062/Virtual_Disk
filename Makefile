all: create vdAdd vdLs
create: create.o base.o encode.o decode.o
	gcc -o create create.o encode.o decode.o
create.o: create.c encode.o decode.o
	gcc -c create.c
encode.o: encode.c
	gcc -c encode.c
decode.o: decode.c
	gcc -c decode.c
base.o: base.c
	gcc -c base.c
clean:
	rm -rf *.o
