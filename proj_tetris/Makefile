.pyhone:teris clean

ret : tetris2.o libkeyboard.a
	gcc -o ret  tetris2.o -lkeyboard -L.
%.o : %.c %.a
	gcc -c $< -o $@ 
clean:
	rm *.o tetirs
