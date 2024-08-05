#include <stdio.h>


int foo(int);

int main() {

    int count = foo(5);

    printf("%d\n", count); //25

}

//value of the static variable x is maintained
//between calls
//x is initialized once in .data section
/** 

foo:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jle	.L4
    **************************
	movl	x.0(%rip), %eax  *  static variable x loaded from data section
	addl	$1, %eax         *  incremented
	movl	%eax, x.0(%rip)  *  and stored back so that it's value is preserved
    **************************
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	foo
	movl	x.0(%rip), %edx
	addl	%edx, %eax
	jmp	.L5
.L4:
	movl	$0, %eax
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	foo, .-foo
	.data
	.align 4
	.type	x.0, @object
	.size	x.0, 4
x.0:


**/
int foo(int n) {

   static int x = 0;

   if(n > 0) {
    x++;
    return foo(n-1) + x;
   } 
    return 0;

}

/**
winding phase:
frame 1; n = 5; x = 1
frame 2; n = 4; x = 2
frame 3; n = 3; x = 3
frame 4; n = 2; x = 4
frame 5; n = 1; x = 5
frame 6; n = 0; x = 5

unwinding phase:
frame 6; base condition; return 0
frame 5; return 0 from previous frame + x        (5)
frame 4; return 5 from previous frame + x        (10)
frame 3; return 10 from previous frame + x       (15)
frame 2; return 15 from previous frame + x       (20)
frame 1; return 20 from previous frame + x       (25)
**/


