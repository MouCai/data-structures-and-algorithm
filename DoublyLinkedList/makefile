objects = Main.o NewList.o GetTail.o IsEmpty.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): DoublyLinkedList.h

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
