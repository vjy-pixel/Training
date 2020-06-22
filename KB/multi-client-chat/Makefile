compileServer: server.c
	gcc server.c -o server

compileClient: client.c
	gcc client.c -o client

runServer : server
	./server

runClient : client
	./client 127.0.0.1

remove :
	rm *.o