OBJ:= $(patsubst *c,*o, $(wildcard *c))

is.exe: $(OBJ)
	gcc -o $@ $^

$(OBJ):

clean:
	rm *.exe
