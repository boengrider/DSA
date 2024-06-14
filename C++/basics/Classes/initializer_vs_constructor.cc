#include <iostream>
#include <vector>

//Parameterless default constructor
//This is initialized like a C structure
class CircleDefaultConstructor {
    public:
     int radius;

};

//Non default constructor provided
//and will be called
class CircleNonDefaultConstructor {
    public:
        int radius;

        CircleNonDefaultConstructor(int r) {
            this->radius = r;
        }

};

int main() {


    /*
    subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$100, -16(%rbp)
    */
    CircleDefaultConstructor c1 = {10};

    /*
    movl	$1000, %esi
	movq	%rax, %rdi
	call	_ZN27CircleNonDefaultConstructorC1Ei
    */
    CircleNonDefaultConstructor c2 = {100};

    CircleNonDefaultConstructor c3 = CircleNonDefaultConstructor(1000);


    /*
    movl	$4, %edi
	call	_Znwm@PLT
	movq	%rax, %rbx
	movl	$1, %esi
	movq	%rbx, %rdi
	call	_ZN27CircleNonDefaultConstructorC1Ei
    */
    CircleNonDefaultConstructor *c4 = new CircleNonDefaultConstructor(1);


    CircleDefaultConstructor c5 = c1;
    

}
