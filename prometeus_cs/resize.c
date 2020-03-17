// Resizes a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s infile outfile scale\n", argv[0]);
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    double scale = 1;
    sscanf(argv[3], "%lf", &scale);
    if(scale < 0)
        fprintf(stderr, "scale %lf should be positive and integer", scale);

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);



    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    LONG 
        init_biHeight = abs(bi.biHeight), 
        init_biWidth = bi.biWidth;
    
    RGBTRIPLE *image = malloc(init_biHeight * sizeof(RGBTRIPLE[init_biWidth]));

    // iterate over infile's scanlines
    fread(image, sizeof(RGBTRIPLE), init_biWidth*init_biHeight, inptr);

    //BMP headers modification
    bf.bfSize = (bf.bfSize - sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)) * scale;
    bi.biHeight *= scale;
    bi.biWidth *= scale;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (unsigned i = 0; i < abs(bi.biHeight); i++)
    {
        // iterate over pixels in scanline
        for (unsigned j = 0; j < bi.biWidth; j++)
        {
            unsigned is = i/scale, 
                js = j/scale;

            // write RGB triple to outfile
            fwrite(&image[is * init_biWidth + js], sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR); 

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
            fputc(0x00, outptr);
    }

    free(image);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
