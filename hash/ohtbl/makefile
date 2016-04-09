hashObjcts = ../hash.o
ohtblObjects = main.o ohtbl_init.o ohtbl_insert.o ohtbl_lookup.o ohtbl_remove.o ohtbl_destory.o
objects = $(hashObjcts) $(ohtblObjects)

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
