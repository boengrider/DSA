	.file	"complexNumber.c"
	.text
	.globl	teacherA
	.data
	.align 8
	.type	teacherA, @object
	.size	teacherA, 8
teacherA:
	.string	"Jon Doe"
	.globl	teacherB
	.align 8
	.type	teacherB, @object
	.size	teacherB, 9
teacherB:
	.string	"Jane Doe"
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
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	teacherA(%rip), %rax
	movq	%rax, -48(%rbp)
	movl	$35, -40(%rbp)
	leaq	teacherB(%rip), %rax
	movq	%rax, -32(%rbp)
	movl	$25, -24(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
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
