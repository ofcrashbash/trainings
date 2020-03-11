#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

//https://www.quora.com/How-does-the-crypt-function-work-with-some-examples-of-crypt-function-in-C
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s hash\n  hash: 50cI2vYkF0YU2 gives password: LOL)\n", argv[0]);
        return 1;
    }

    clock_t start, end;
    double cpu_time_used;
    
    char *hash = argv[1];

    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    const char *seedchars = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned num_symbols = 53;

    start = clock();
    char key_candidate[5];
    for(int first_letter = 0; first_letter < num_symbols; ++first_letter)
        for(int second_letter = 0; second_letter < num_symbols; ++second_letter)
            for(int third_letter = 0; third_letter < num_symbols; ++third_letter)
                for(int forth_letter = 0; forth_letter < num_symbols; ++forth_letter)
                {
                    key_candidate[0] = seedchars[first_letter];
                    key_candidate[1] = seedchars[second_letter];
                    key_candidate[2] = seedchars[third_letter];
                    key_candidate[3] = seedchars[forth_letter];

                    char *test_hash = crypt(key_candidate, salt);   
                    if(strcmp(hash, test_hash) == 0)
                    {
                        printf("hash - %s, test pass - %s\n", test_hash, key_candidate);
                        goto done;
                    }
                }
    printf("solution not found: %s\n", key_candidate);
    done:
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("calculation time - %f\n", cpu_time_used);
    return 0;
}