objects = main.o list_init.o

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
