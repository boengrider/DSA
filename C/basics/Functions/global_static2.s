	.file	"global_static2.c"
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
	movl	$0, %eax
	#call	foo
	#------------------------
	movl	counter.0(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	#------------------------
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	foo
	.type	foo, @function
#foo:
#.LFB1:
#	.cfi_startproc
#	endbr64
#	pushq	%rbp
#	.cfi_def_cfa_offset 16
#	.cfi_offset 6, -16
#	movq	%rsp, %rbp
#	.cfi_def_cfa_register 6
#	movl	counter.0(%rip), %eax
#	movl	%eax, %esi
#	leaq	.LC0(%rip), %rax
#	movq	%rax, %rdi
#	movl	$0, %eax
#	call	printf@PLT
#	nop
#	popq	%rbp
#	.cfi_def_cfa 7, 8
#	ret
#	.cfi_endproc
#.LFE1:
#	.size	foo, .-foo
	.data
	.align 4
	.type	counter.0, @object
	.size	counter.0, 4
counter.0:
	.long	10
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