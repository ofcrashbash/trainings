#define _XOPEN_SOURCE
#include <crypt.h>
#include <stdio.h>
#include <unistd.h>

//https://www.quora.com/How-does-the-crypt-function-work-with-some-examples-of-crypt-function-in-C
int main(int argc, char *argv[])
{
    printf("number of inputs - %i\n", argc);
    printf("program name - %s\n", argv[0]);
    
    return 0;
}