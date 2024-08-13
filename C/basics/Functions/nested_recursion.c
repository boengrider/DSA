#include <stdio.h>

int foo(int);

int main() {

    int retval = foo(1000);

    printf("%d\n", retval);
}

int foo(int n) {
    if(n>100) {
        return n-10;
    } else {
        return foo(foo(n+11));
    } 

}


/** 
 * 1st Initial call n = 95 FRAME ACTIVE
 * 2st inner call n = 106. Base hit, returns to the outer caller 96 (OUTER FRAME ACTIVE)
 * 3nd inner call n = 107. Base hit, returns to the outer caller 97 (OUTER FRAME ACTIVE)
 * 4th inner call n = 108. Base hit, returns to the outer caller 98 (OUTER FRAME ACTIVE)
 * 5th inner call n = 109. Base hit, returns to the outer caller 99 (OUTER FRAME ACTIVE)
 * 6th inner call n = 110. Base hit, returns to the outer caller 100 (OUTER FRAME ACTIVE)
 * 7th inner call n = 111. Base hit, returns to the outer caller 101 (OUTER FRAME ACTIVE)
 * 
 * 
 * 
 * 
 *                  foo(95)
 *                  /     \
 *             foo(106)->foo(96)   
 *                        /    \
 *                   foo(107)->foo(97) 
 *                              /    \
 *                         foo(108)->foo(98)  
 *                                    /    \
 *                               foo(109)->foo(99)
 *                                          /    \
 *                                     foo(110)->foo(100)
 *                                                /     \
 *                                           foo(111)->foo(101)
**/
