sglist.exe: single_list.o ../src/single_list.h
	gcc -g -o sglist.exe main.c single_list.o
single_list.o: ../src/single_list.h
	gcc -g -c ../src/single_list.c
clean:
	rm -rf *.o *.exe
