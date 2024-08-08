#include <stdio.h>
void foo();

int main() {

  foo();

}

void foo() {
  static int counter = 10;

  printf("%d\n", counter);

}