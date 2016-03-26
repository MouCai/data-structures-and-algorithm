objects = Main.o NewList.o Prepend.o Append.o DeleteHead.o DeleteTail.o InsertAfter.o DeleteNode.o Push.o

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): List.h

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
