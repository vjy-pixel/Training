cmd_/home/einfochips/Test/hello.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /home/einfochips/Test/hello.ko /home/einfochips/Test/hello.o /home/einfochips/Test/hello.mod.o ;  true