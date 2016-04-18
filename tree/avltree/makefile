bitreeObjects = ./../bitree/main.o \
								./../bitree/bitree_init.o \
								./../bitree/bitree_insert_left.o \
                ./../bitree/bitree_insert_right.o \
								./../bitree/bitree_remove_left.o \
								./../bitree/bitree_remove_right.o \
								./../bitree/bitree_destory.o \
								./../bitree/bitree_merge.o \
								./../bitree/bitree_traverse_preorder.o \
								./../bitree/bitree_traverse_inorder.o \
								./../bitree/bitree_traverse_postorder.o

avltreeObjects = main.o avltree_destory.o avltree_lookup.o

$(objects) = $(bitreeObjects) $(avltreeObjects)

build: $(objects)
	gcc -o test.out $(objects)
	make clean
$(objects): avltree.h

run:
	make
	make test

test:
	./test.out

.PHONY : clean
clean :
	-rm $(objects)
