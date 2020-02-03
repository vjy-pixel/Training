	.file	"Stack.c"
	.section	.rodata
.LC0:
	.string	"Enter Number of Elements:"
.LC1:
	.string	"%d"
.LC2:
	.string	"\n1.Push\n2.Pop\n3.View\n4.Exit"
.LC3:
	.string	"Enter element to insert:"
.LC4:
	.string	"Stack Overflow!!!!"
.LC5:
	.string	"Stack Underflow!!!!"
.LC6:
	.string	"%d\n"
.LC7:
	.string	"_"
.LC8:
	.string	"Please make valid choice!!!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$-1, -24(%rbp)
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-36(%rbp), %eax
	cltq
	movl	$4, %esi
	movq	%rax, %rdi
	call	calloc
	movq	%rax, -16(%rbp)
.L18:
	movl	$.LC2, %edi
	call	puts
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$10, %edi
	call	putchar
	movl	-32(%rbp), %eax
	cmpl	$2, %eax
	je	.L3
	cmpl	$2, %eax
	jg	.L4
	cmpl	$1, %eax
	je	.L5
	jmp	.L2
.L4:
	cmpl	$3, %eax
	je	.L6
	cmpl	$4, %eax
	je	.L7
	jmp	.L2
.L5:
	movl	-36(%rbp), %eax
	subl	$1, %eax
	cmpl	-24(%rbp), %eax
	jle	.L8
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, -24(%rbp)
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movl	-28(%rbp), %eax
	movl	%eax, (%rdx)
	jmp	.L10
.L8:
	movl	$.LC4, %edi
	call	puts
	jmp	.L10
.L3:
	cmpl	$-1, -24(%rbp)
	jne	.L11
	movl	$.LC5, %edi
	call	puts
	jmp	.L10
.L11:
	cmpl	$0, -24(%rbp)
	jne	.L13
	movl	$-1, -24(%rbp)
	jmp	.L10
.L13:
	subl	$1, -24(%rbp)
	jmp	.L10
.L6:
	movl	-36(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	.L14
.L17:
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jg	.L15
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	jmp	.L16
.L15:
	movl	$.LC7, %edi
	call	puts
.L16:
	subl	$1, -20(%rbp)
.L14:
	cmpl	$0, -20(%rbp)
	jns	.L17
	jmp	.L10
.L7:
	movl	$0, %edi
	call	exit
.L2:
	movl	$.LC8, %edi
	call	puts
.L10:
	jmp	.L18
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
