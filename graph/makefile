objects =  main.o 

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): graph.h

test:
	./test.out

run:
	make
	make test
.PHONY : clean
clean :
	-rm $(objects)
