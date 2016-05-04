objects = main.o ../heap_destory.o ../heap_init.o ../heap_insert.o ../heap_extract.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): pqueue.h

run:
	make
	make test

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
