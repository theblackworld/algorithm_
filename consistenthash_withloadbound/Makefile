CC = g++ -g -c
CO = g++ -g -o

OBJ = cstring.o main.o

main: $(OBJ)
	$(CO) main $(OBJ)
cstring.o: cstring.h
	$(CC)  cstring.h cstring.cpp
main.o: cstring.h 
	$(CC)  cstring.h main.cpp


.PHONY:
  clean:
	rm -rf $(OBJ)
