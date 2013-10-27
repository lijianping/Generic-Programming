all: sglist.exe dblist.exe lsglist.exe
.PHONY: all

sglist.exe: ../src/single_list/single_list.h
	gcc -g -o sglist.exe sglist.c ../src/single_list/single_list.c
dblist.exe: ../src/double_linked_list/double_linked_list.h
	gcc -g -o dblist.exe dblist.c ../src/double_linked_list/double_linked_list.c
lsglist.exe: ../src/loop_single_list/loop_single_list.h
	gcc -g -o lsglist.exe loopSingleList.c ../src/loop_single_list/loop_single_list.c
clean:
	rm -rf *.o *.exe
