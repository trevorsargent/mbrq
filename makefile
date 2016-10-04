all: hello

hello: 
	gcc mbrq.c -o mbrq lib/fileManagement.c

clean: 
	rm mbrq