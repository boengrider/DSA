#include <stdio.h>

int sum(int);


int main() {

    int result = sum(5);


    printf("%d\n", result);

}

int sum(int n) {
    if(n<1) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}

/**
 * 1 + 2 + 3 = 6
 * n = 3
 * n * (n + 1) / 2
 */