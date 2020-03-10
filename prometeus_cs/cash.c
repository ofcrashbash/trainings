#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars = 237648;
    int number_of_coins = round(dollars * 100);
    int coins_quants[] = {1, 5, 10, 25, 5, 10, 50, 100, 1000, 5000, 100000};

    unsigned number_of_coins_used = 0;
    while(number_of_coins > 0)
    {
        for(int i = 10; i >= 0; i--)
            if(coins_quants[i] <= number_of_coins)
            {
                number_of_coins -= coins_quants[i];
                break;
            }

        number_of_coins_used++;
    }

    printf("%i\n", number_of_coins_used);

    return 0;
}