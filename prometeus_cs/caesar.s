	.file	"caesar_cipher.cpp"
	.text
	.section	.rodata
.LC0:
	.string	"check - %c\n"
	.text
	.globl	_Z9check_keyPKc
	.type	_Z9check_keyPKc, @function
_Z9check_keyPKc:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L2
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$47, %al
	jle	.L3
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$57, %al
	jle	.L4
.L3:
	cmpl	$0, -4(%rbp)
	jne	.L5
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$43, %al
	je	.L4
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	je	.L4
.L5:
	movl	$0, %eax
	jmp	.L6
.L4:
	addl	$1, -4(%rbp)
	jmp	.L7
.L2:
	movl	$1, %eax
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	_Z9check_keyPKc, .-_Z9check_keyPKc
	.section	.rodata
.LC1:
	.string	"Usage: %s key\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -52(%rbp)
	jne	.L9
	movq	-64(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_Z9check_keyPKc
	testb	%al, %al
	je	.L9
	movq	-64(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, -36(%rbp)
	movl	$0, -40(%rbp)
	movabsq	$7020093037282615660, %rax
	movabsq	$7526752397938597996, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movl	$6778473, -16(%rbp)
	movl	-40(%rbp), %eax
	cltq
	movzbl	-32(%rbp,%rax), %eax
	movb	%al, -41(%rbp)
.L12:
	cmpb	$0, -41(%rbp)
	je	.L11
	movsbl	-41(%rbp), %eax
	movl	-36(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_Z6cipherci
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar@PLT
	addl	$1, -40(%rbp)
	movl	-40(%rbp), %eax
	cltq
	movzbl	-32(%rbp,%rax), %eax
	movb	%al, -41(%rbp)
	jmp	.L12
.L11:
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	jmp	.L13
.L9:
	movq	-64(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %eax
.L13:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	main, .-main
	.globl	_Z6cipherci
	.type	_Z6cipherci, @function
_Z6cipherci:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movl	%esi, -24(%rbp)
	movb	%al, -20(%rbp)
	movl	-24(%rbp), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -24(%rbp)
	cmpl	$0, -24(%rbp)
	jns	.L16
	addl	$26, -24(%rbp)
.L16:
	cmpb	$64, -20(%rbp)
	jle	.L17
	cmpb	$90, -20(%rbp)
	jg	.L17
	movsbl	-20(%rbp), %eax
	leal	-65(%rax), %edx
	movl	-24(%rbp), %eax
	leal	(%rdx,%rax), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	addl	$65, %eax
	movb	%al, -1(%rbp)
	jmp	.L18
.L17:
	cmpb	$96, -20(%rbp)
	jle	.L19
	cmpb	$122, -20(%rbp)
	jg	.L19
	movsbl	-20(%rbp), %eax
	leal	-97(%rax), %edx
	movl	-24(%rbp), %eax
	leal	(%rdx,%rax), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	addl	$97, %eax
	movb	%al, -1(%rbp)
	jmp	.L18
.L19:
	movzbl	-20(%rbp), %eax
	movb	%al, -1(%rbp)
.L18:
	movzbl	-1(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	_Z6cipherci, .-_Z6cipherci
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
