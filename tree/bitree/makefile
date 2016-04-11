objects = main.o bitree_init.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): bitree.h

run:
	make
	make test

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
