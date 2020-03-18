// Recovers a JPEG dump memory

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s raw_file_name\n", argv[0]);
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    FILE *out_f_prt = NULL;
    const unsigned BLOCK_SIZE = 512;
    BYTE dataframe[BLOCK_SIZE];
    char filename[15] = "";

    unsigned jpeg_counter = 0;
    while (1)  
    { 
        /* display contents of file on screen */ 
        size_t bytesRead = fread(&dataframe, sizeof(BYTE), BLOCK_SIZE, inptr);
        
        if (bytesRead == 0 && feof(inptr))
            break;

        int containsJpegHeader = (dataframe[0] == 0xff && dataframe[1] == 0xd8 && dataframe[2] == 0xff && (dataframe[3] & 0xf0) == 0xe0);

        if(containsJpegHeader)
        {
            if (out_f_prt != NULL)
                fclose(out_f_prt);

            sprintf(filename, "%03i.jpg", jpeg_counter);
            out_f_prt = fopen(filename, "w");
            if (out_f_prt == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not open %s.\n", infile);
                return 2;
            } 
            printf("Got: %u!\n", jpeg_counter);
            jpeg_counter++;
        }

        if(out_f_prt != NULL)
            fwrite(&dataframe, sizeof(BYTE), BLOCK_SIZE, out_f_prt);
    }

    // close infile
    fclose(inptr);

    // success
    return 0;
}
