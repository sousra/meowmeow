.PHONY: encode decode
encode: main.c encode.c decode.c
	gcc main.c encode.c decode.c -o encode
decode: encode
	ln -f encode decode
clean:
	rm encode decode 
