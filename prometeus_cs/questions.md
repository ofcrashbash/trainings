# Questions

## What's `stdint.h`?

Він в собі містить оголошення різних типів. А такоє їхні обмеження, як от максимальний розмір `int`.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

`unint8_t` - це байт, і він використовуєтсья для кольору. 


## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1 4 4 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM

## What's the difference between `bfSize` and `biSize`?

РОзмір..

## What does it mean if `biHeight` is negative?

Різний спосіб нумерування байтів кольору(знизу до гори).

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Якщо файл не існує, або немає довзолів

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

Зчитує певіну кількість структур, а вони є одні.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

???

## What does `fseek` do?

зміщує вказівник на задану кількість від..

## What is `SEEK_CUR`?

...поточної позиції.
