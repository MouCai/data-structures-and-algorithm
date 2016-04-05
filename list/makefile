objects = main.o list_init.o list_insert_next.o list_push.o list_insert_prev.o list_remove.o list_destory.o list_pop.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): list.h

run:
	make
	make test

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
