// REcovers a JPEG dump memory

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

//jpeg

typedef struct
{
    BYTE first;
    BYTE second;
    BYTE third;
    BYTE forth;
} __attribute__((__packed__))
JPEGHEADERKEY;

int is_jpeg_header(JPEGHEADERKEY *header)
{
    if( header->first == 0xff && 
        header->second == 0xd8 && 
        header->third == 0xff && 
        (header->forth & 0xf0) == 0xe0)

        return 1;

    return 0;
}


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
    char *outfile = "image";

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    unsigned jpeg_counter = 0;
    int ch = getc(inptr); 
    while (ch != EOF)  
    { 
        /* display contents of file on screen */ 
        JPEGHEADERKEY data;
        fread(&data, sizeof(JPEGHEADERKEY), 1, inptr);
        if(is_jpeg_header(&data))
        {
            printf("Got: %u!\n", jpeg_counter);
            jpeg_counter++;
        }
        

        ch = getc(inptr); 
    } 

    // skip over padding, if any
    fseek(inptr, sizeof(JPEGHEADERKEY), SEEK_CUR);

    // close infile
    fclose(inptr);

    // success
    return 0;
}
