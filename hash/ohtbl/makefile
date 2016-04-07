objects = main.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): ohtbl.h

run:
	make
	make test

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
