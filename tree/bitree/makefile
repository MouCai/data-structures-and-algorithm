objects = main.o bitree_init.o bitree_insert_left.o bitree_insert_right.o bitree_remove_left.o bitree_remove_right.o

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
