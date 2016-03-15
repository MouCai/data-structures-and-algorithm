objects = Find.o Insert.o IsEmpty.o IsLast.o Main.o NewList.o Delete.o DeleteList.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): List.h

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
