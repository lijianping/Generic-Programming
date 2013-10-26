all: sglist.exe dblist.exe
.PHONY: all

sglist.exe: ../src/single_list/single_list.h
	gcc -g -o sglist.exe main.c ../src/single_list/single_list.c
dblist.exe: ../src/double_linked_list/double_linked_list.h
	gcc -g -o dblist.exe dblist.c ../src/double_linked_list/double_linked_list.c
clean:
	rm -rf *.o *.exe
