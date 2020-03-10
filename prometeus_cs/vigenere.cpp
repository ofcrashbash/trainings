//use compiler

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

bool check_key(const char *key_string);
int evaluate_key(const char key);
char cipher(const char c, int key);
bool is_letter(char c);

int main(const int argc, const char *argv[])
{   
    if(argc == 2)
    {
        const char *key_string = argv[1];
        int key_lenght = strlen(key_string);
        if(check_key(key_string) && key_lenght > 0)
        {
            string test = get_string("plaintext: ");
            int i = 0, key_counter = 0;
            const char *input_text = test;
            char c = input_text[i];
            printf("ciphertext: ");
            while(c != (char)NULL)
            {
                int current_key = evaluate_key(key_string[key_counter % key_lenght]);
                printf("%c", cipher(c, current_key));
                c = input_text[++i];
                if( is_letter(c) )
                    key_counter++;
            }
            printf("\n");
            return 0;
        }
    }
    
    printf("Usage: %s key\n", argv[0]);
    return 1;
}

inline bool is_big_letter(char c)
{
    if (c >= 65 && c <= 90)
        return true;

    return false;

}

inline bool is_small_letter(char c)
{
    if (c >= 97 && c <= 122)
        return true;

    return false;
    
}

inline bool is_letter(char c)
{
    if ( is_big_letter(c) || is_small_letter(c))
        return true;

    return false;
}

bool check_key(const char *key_string)
{
    int i = 0;
    while (key_string[i] != (char)NULL)
    {
        int c = (int)key_string[i];
        if(!is_letter(c))
            return false;
        ++i;
    }
    
    return true;
}

int evaluate_key(const char key)
{
    if ( is_big_letter(key) )
        return (int)(key - 'A');
    else if ( is_small_letter(key) )
        return (int)(key - 'a');
    return 0;
}

char cipher(const char c, int key)
{   
    char c_cipher;

    if (is_big_letter(c))
    {
        c_cipher = (c - 65 + key) % 26;
        c_cipher += 65;
    }
    else if (is_small_letter(c))
    {
        c_cipher = (c - 97 + key) % 26;
        c_cipher += 97;
    }
    //non letters symbols
    else 
        c_cipher = c;

    return c_cipher;
}
