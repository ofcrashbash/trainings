#include <stdio.h>

int main(void)
{
    unsigned height = 10;

    for(int i = 1; i <= height; i++)
    {
        for(int j = 0; j < i; j++)
            printf("#");
                
        printf("\n");
    }

    return 0;
}