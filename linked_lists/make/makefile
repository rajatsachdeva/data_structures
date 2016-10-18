###############################################################
#
#       MAKEFILE FOR SINGLY LINKED LIST
#
#
################################################################

CC=gcc
CFLAGS=-c -Wall -g 
FLAGS=-o
VFLAGS=--tool=memcheck --leak-check=yes --show-reachable=yes -v
INCLUDE=-I../include/
HEADER=../include/
OBJ=../obj/
SRC=../src/
OUTPUT=../bin/

$(OUTPUT)my_list: $(OBJ)s_list_main.o $(OBJ)singly_linked_list.o 
	$(CC) $(FLAGS) my_list $(OBJ)s_list_main.o $(OBJ)singly_linked_list.o
	mv my_list ../bin/

$(OBJ)s_list_main.o: $(SRC)s_list_main.c $(HEADER)linked_list.h
	$(CC)  -DTRACING $(INCLUDE) $(CFLAGS) $(SRC)s_list_main.c
	mv s_list_main.o ../obj/


$(OBJ)singly_linked_list.o: $(SRC)singly_linked_list.c $(HEADER)linked_list.h 
	$(CC) -DTRACING $(INCLUDE) $(CFLAGS) $(SRC)singly_linked_list.c
	mv singly_linked_list.o ../obj/

valgrind: $(OUTPUT)my_list
	valgrind $(VFLAGS) ./$(OUTPUT)my_list 

clean:
	rm $(OBJ)*.o
	rm $(OUTPUT)my_list
