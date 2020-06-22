compileSend: sender.c 
	gcc sender.c -o send

compileReceive1: receive1.c
	gcc receive1.c -o rec1

compileReceive2: receive2.c
	gcc receive2.c -o rec2

compileReceive3: receive3.c
	gcc receive3.c -o rec3


runSend: send
	./send

runRec1: rec1
	./rec1


runRec2: rec2
	./rec2


runRec3: rec3
	./rec3

clearAll: 
	rm *.o