#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_change(void);

int main(void)
{
    // prompt the user for the amount of change owed
    int cents = get_change();

    // compute the minimum number of coins
    int coins = 0;
    int denominations[] = {25, 10, 5, 1};
    int n = sizeof(denominations) / sizeof(denominations[0]);
    for (int i = 0; i < n; i++)
    {
        while (cents >= denominations[i])
        {
            coins++;
            cents -= denominations[i];
        }
    }

    // print the result
    printf("%d\n", coins);
}

int get_change(void)
{
    int cents;
    char line[100];
    do
    {
        printf("Change owed: ");
        fgets(line, sizeof(line), stdin);
    }
    while (sscanf(line, "%d", &cents) != 1 || cents < 0);
    return cents;
}

