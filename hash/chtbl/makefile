listsObjects = ../../list/list_init.o \
							 ../../list/list_insert_next.o \
							 ../../list/list_push.o \
							 ../../list/list_insert_prev.o \
							 ../../list/list_remove.o \
							 ../../list/list_destory.o \
							 ../../list/list_pop.o \
							 ../../list/list_shift.o 
chtblObjects = main.o chtbl_init.o chtbl_destory.o chtbl_insert.o chtbl_lookup.o chtbl_remove.o
hashObjcts = ../hash.o
objects = $(listsObjects) $(hashObjcts) $(chtblObjects)
build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): chtbl.h

test:
	./test.out

run:
	make
	make test
.PHONY : clean
clean :
	-rm $(objects)
