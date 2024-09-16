	.file	"2Darray.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -80(%rbp)
	movl	$20, -64(%rbp)
	movl	$30, -48(%rbp)
	movl	$40, -32(%rbp)
	movl	$0, -88(%rbp)
	jmp	.L2
.L5:
	movl	$0, -84(%rbp)
	jmp	.L3
.L4:
	movl	-84(%rbp), %eax
	leal	1(%rax), %edx
	movl	-88(%rbp), %eax
	addl	$1, %eax
	imull	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	-84(%rbp), %eax
	movslq	%eax, %rcx
	movl	-88(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rcx, %rax
	movl	%edx, -80(%rbp,%rax,4)
	movl	-84(%rbp), %eax
	movslq	%eax, %rdx
	movl	-88(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	-80(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -84(%rbp)
.L3:
	cmpl	$3, -84(%rbp)
	jle	.L4
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -88(%rbp)
.L2:
	cmpl	$3, -88(%rbp)
	jle	.L5
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
