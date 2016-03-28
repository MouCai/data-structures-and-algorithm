objects = 

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): set.h

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
