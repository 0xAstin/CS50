#include <stdio.h>
#include <stdbool.h>

long get_long(void);
int get_digit_sum(int digit);
bool is_valid_card(long card_number);

int main(void)
{
    // prompt the user for a credit card number
    printf("Number: ");
    long card_number = get_long();

    // check if the card is valid and print the result
    if (is_valid_card(card_number))
    {
        if ((card_number >= 340000000000000 && card_number < 350000000000000) ||
            (card_number >= 370000000000000 && card_number < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (card_number >= 5100000000000000 && card_number < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((card_number >= 4000000000000 && card_number < 5000000000000) ||
                 (card_number >= 4000000000000000 && card_number < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_long(void)
{
    long n;
    char c;
    while (scanf("%ld%c", &n, &c) != 2 || c != '\n')
    {
        printf("Number: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return n;
}

int get_digit_sum(int digit)
{
    int sum = 0;
    while (digit > 0)
    {
        int last_digit = digit % 10;
        sum += last_digit;
        digit /= 10;
    }
    return sum;
}

bool is_valid_card(long card_number)
{
    int sum = 0;
    bool multiply = false;
    while (card_number > 0)
    {
        int last_digit = card_number % 10;
        if (multiply)
        {
            sum += get_digit_sum(last_digit * 2);
        }
        else
        {
            sum += last_digit;
        }
        multiply = !multiply;
        card_number /= 10;
    }
    return sum % 10 == 0;
}

