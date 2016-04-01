objects =  main.o set_init.o set_destory.o set_remove.o set_insert.o set_is_member.o set_union.o set_is_equal.o set_intersection.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): set.h

test:
	./test.out

run:
	make
	make test
.PHONY : clean
clean :
	-rm $(objects)
