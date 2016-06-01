listsObjects = ../list/list_init.o \
							 ../list/list_insert_next.o \
							 ../list/list_push.o \
							 ../list/list_insert_prev.o \
							 ../list/list_remove.o \
							 ../list/list_destory.o \
							 ../list/list_pop.o \
							 ../list/list_shift.o 

setObjects = ../set/set_init.o \
						 ../set/set_destory.o \
						 ../set/set_difference.o \
						 ../set/set_insert.o \
						 ../set/set_intersection.o \
						 ../set/set_is_equal.o \
						 ../set/set_is_member.o \
						 ../set/set_is_subset.o \
						 ../set/set_remove.o \
						 ../set/set_union.o

graphObjects = main.o graph_init.o graph_destory.o graph_insert_vertex.o graph_insert_edge.o graph_remove_vertex.o graph_remove_edge.o

objects =  $(listsObjects) $(setObjects) $(graphObjects)

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
