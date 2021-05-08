from cs50 import get_int

credit_number = -1
while credit_number < 0:
    credit_number = get_int('Number: ')

card_id = 0
counter = 0
hash = 0

while credit_number > 0:

    digit = credit_number % 10

    if counter % 2 == 0:
        hash += digit % 10
    else:
        hash += (2 * digit) % 10
        if 2 * digit >= 10:
            hash += 1

    if counter >= 13:
        card_id += pow(10, counter - 13) * digit
    
    credit_number //= 10
    counter += 1

if hash % 10 != 0:
    print("INVALID")
elif card_id // 10 >= 40 and card_id // 10 <= 49:
    print("VISA")
elif card_id // 10 >= 51 and card_id // 10 <= 55:
    print("MASTERCARD")
elif card_id == 34 or card_id == 37:
    print("AMEX")
else:
    print("Invalid")
    

"""
int main(void)
{
    int hash = 0;

    long int credit_number = -1;
    
    while(credit_number <= 0)
        credit_number = get_long("Number: ");
    
    int card_id = 0;
    int counter = 0;
    while(credit_number > 0)
    {
        int digit = credit_number % 10;
        if(counter % 2 == 0)
            hash += digit % 10;
        else 
        {
            hash += (2*digit) % 10;
            if (2*digit >= 10)
                hash++;
        }
                
        if(counter >= 13)
            card_id += pow(10, counter - 13)*digit;

        credit_number /= 10;
        counter++;
    }

    if(hash % 10 != 0)
        printf("INVALID\n");
    else 
    {
        if(card_id/10 >= 40 && card_id/10 <= 49)
            printf("VISA\n");
        else if(card_id/10 >= 51 && card_id/10 <= 55)
            printf("MASTERCARD\n");
        else if(card_id == 34 || card_id == 37)
            printf("AMEX\n");
        else 
            printf("INVALID\n");
    }
    
    return 0;
}
"""