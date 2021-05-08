from cs50 import get_int

height = 0
while height > 8 or height < 1:
    height = get_int('Height: ')

for i in range(height):
    for j in range(2*height + 1):
        if j >= height - i - 1 and j < height:
            print('#', sep='', end='')
        elif j == height:
            print('  ', sep='', end='')
        elif j > height and j <= height + i + 1:
            print('#', sep='', end='')
        elif j > height + i + 1:
            break
        else:
            print(' ', sep='', end='')
    print()