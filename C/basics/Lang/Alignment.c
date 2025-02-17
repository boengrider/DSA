#include <stdio.h>

//12 bytes
struct foo
{
    char a; 
    int b;  
    char c; 

}; // D A A A D D D D D A A A 
   // a - - - b b b b c - - -

//8 bytes
struct bar
{
    char a;
    char c;
    int b;
}; // D D A A D D D D
   // a a - - b b b b 

//6 bytes
//#pragma pack(push,1)
struct foobar
{
    char a;
    char c;
    int b;
};
//#pragma pack(pop)


struct DNS_HEADER_B
{
    unsigned short id; // 2 
    unsigned char rd; //  1
    unsigned char tc; //  1
    unsigned char aa; //  1
    unsigned char opcode; // 1
    unsigned char qr; //     1
 
    unsigned char rcode; // 1
    unsigned char cd; //    1
    unsigned char ad; //    1
    unsigned char z; //     1
    unsigned char ra; //    1
 
    unsigned short q_count; //     2
    unsigned short ans_count; //   2
    unsigned short auth_count; //  2
    unsigned short add_count; //   2
};



struct A
{
    char a;
    char b;
    int c;
};

struct B
{
    char a;
    int c;
    char b;
};

int main() {

    struct foo f = { 255, 666, 255};

    unsigned char *chp = &f.a;

    printf("Size of struct foo is %d\n", sizeof(struct foo));
    printf("Size of struct bar is %d\n", sizeof(struct bar));
    printf("Size of foobar is %d\n", sizeof(struct foobar));
    printf("Size of DNS_HEADER_B is %d\n", sizeof(struct DNS_HEADER_B));
    
    printf("Size of A => %d\n", sizeof(struct A));
    printf("Size of B => %d\n", sizeof(struct B));
   


    

}