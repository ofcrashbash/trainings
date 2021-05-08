from cs50 import get_int

height = -1
while height <= 0:
    height = get_int('Height: ')



for i in range(height):
    for j in range(height):
        if j >= height - i - 1:
            print('#', sep='', end='')
        else:
            print(' ', sep='', end='')
    print()