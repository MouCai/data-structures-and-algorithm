objects = main.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): list.h

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
