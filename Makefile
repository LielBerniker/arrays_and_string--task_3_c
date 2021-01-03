CC=gcc
AR=ar
FLAGS= -Wall -g
all: isort txtfind mytxt mysort
isort: main_insert_sort.o mysort
	$(CC) $(FLAGS) -o isort main_insert_sort.o mysort
txtfind:main_txt_find.o mytxt
	$(CC) $(FLAGS) -o txtfind main_txt_find.o mytxt
mysort: insert_sort.o
	$(AR) -rcs mysort insert_sort.o
mytxt: txt_find.o
	$(AR) -rcs mytxt txt_find.o
insert_sort.o: insert_sort.c insert_sort.h
	$(CC) $(FLAGS) -c insert_sort.c
txt_find.o: txt_find.c txt_find.h
	$(CC) $(FLAGS) -c txt_find.c
main_txt_find.o: main_txt_find.c txt_find.h
	$(CC) $(FLAGS) -c main_txt_find.c 
main_insert_sort.o: main_insert_sort.c insert_sort.h
	$(CC) $(FLAGS) -c main_insert_sort.c 

.PHONY: clean all

clean:
	rm mytxt mysort isort txtfind *.o