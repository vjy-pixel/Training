obj-m += hello.o

#KVERSION := shell uname -r
#KPATH := /lib/modules/$(KVERSION)/build 

all:
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) modules 

clean:
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) clean

