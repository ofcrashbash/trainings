#include <stdio.h>

int main(void)
{
    unsigned height = 9;
    do
    {}
    while (height>=1&&height<=8);

    for(int i = 1; i <= height; i++)
    {
        for(int j = 0; j <= height + i; j++)
            if (j < height - i)
                printf("*");
            else if (j >= height - i && j < height)
                printf("#");
            else if (j == height)
                printf("**");
            else if (j > height && j <= height + i)
                printf("#");
            else if (j > height + i)
                printf("*");
                
        printf("\n");
    }

    return 0;
}