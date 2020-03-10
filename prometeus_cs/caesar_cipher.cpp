//use compiler

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

char cipher(const char c, const int key);

bool check_key(const char *key);

int main(const int argc, const char **argv)
{   
    if(argc == 2)
    {
        if(check_key(argv[1]))
        {
            int key = atoi(argv[1]);

            int i = 0;
            string test = get_string("plaintext: ");
            char cur_char = test[i];
            printf("ciphertext: ");
            while(cur_char != (char)NULL)
            {
                printf("%c", cipher(cur_char, key));
                cur_char = test[++i];
            }
            printf("\n");
            return 0;
        }
    }
    
    printf("Usage: %s key\n", argv[0]);
    return 1;
}

char cipher(const char c, int key)
{   
    char c_cipher;

    key = key % 26;
    if (key < 0)
        key += 26;

    //Big letter case
    if(c >= 65 && c <= 90)
    {
        c_cipher = (c - 65 + key) % 26;
        c_cipher += 65;
    }
    else if(c >= 97 && c <=122)
    {
        c_cipher = (c - 97 + key) % 26;
        c_cipher += 97;
    }
    else 
        c_cipher = c;

    return c_cipher;
}

bool check_key(const char *key)
{
    int i = 0;
    while(key[i] != (char)NULL)
    {
        if(((int)key[i] < 48 || (int)key[i] > 57) && !(i == 0 && ((int)key[i] == 43 || (int)key[i] == 45)))
            return false;
        ++i;
    }
    
    return true;
}