	.file	"StaticVarOutsideOfMain.c"
	.text
	.data
	.align 4
	.type	globalStaticVariable, @object
	.size	globalStaticVariable, 4
globalStaticVariable:
	.long	10
	.align 4
	.type	globalStaticVariable2, @object
	.size	globalStaticVariable2, 4
globalStaticVariable2:
	.long	50
	.globl	globalVariable
	.align 4
	.type	globalVariable, @object
	.size	globalVariable, 4
globalVariable:
	.long	20
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
	subq	$16, %rsp
	movl	$30, -8(%rbp)
	movl	$0, %eax
	call	foo
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.type	foo, @function
foo:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	fooStatic.0(%rip), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	foo, .-foo
	.data
	.align 4
	.type	fooStatic.0, @object
	.size	fooStatic.0, 4
fooStatic.0:
	.long	40
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
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
