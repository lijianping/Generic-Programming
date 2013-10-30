all: sglist.exe dblist.exe lsglist.exe myset.exe
.PHONY: all

sglist.exe: ../src/single_list/single_list.h
	gcc -g -o sglist.exe sglist.c ../src/single_list/single_list.c
dblist.exe: ../src/double_linked_list/double_linked_list.h
	gcc -g -o dblist.exe dblist.c ../src/double_linked_list/double_linked_list.c
lsglist.exe: ../src/loop_single_list/loop_single_list.h
	gcc -g -o lsglist.exe loopSingleList.c ../src/loop_single_list/loop_single_list.c
myset.exe: ../src/my_set/my_set.h
	gcc -g -o myset.exe myset.c ../src/my_set/my_set.c
clean:
	rm -rf *.o *.exe
