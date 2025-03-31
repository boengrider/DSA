#include <stdio.h>

typedef struct action_ { 
   unsigned short actiona: 1;
   unsigned short actionb: 1;
   unsigned short actionc: 1;
   unsigned short actiond: 1;
   unsigned short actione: 1;
   unsigned short actionf: 1;
   unsigned short actiong: 1;
   unsigned short actionh: 1;

   

} action_t;


int main() {

  
  printf("Size of action_t is %d\n", sizeof(action_t));
  



}

