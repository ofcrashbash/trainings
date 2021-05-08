from cs50 import get_float

dollars = -1

while dollars < 0:
    dollars = get_float("Change owed: ")

coins = round(dollars * 100)
coins_and_money = [25, 10, 5, 1]

counter = 0
while coins > 0:
    for coin_and_money in coins_and_money:
        if coin_and_money <= coins:
            coins -= coin_and_money
            break
    counter += 1

print(counter)