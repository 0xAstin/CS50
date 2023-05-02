#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET 26

int main(int argc, char *argv[])
{
    // Check if the program was executed with one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the command-line argument to an integer
    int key = atoi(argv[1]);

    // Get the plaintext message from the user
    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext using the key
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // If the character is alphabetic
        if (isalpha(plaintext[i]))
        {
            // Get the ASCII code of the character
            int ascii = plaintext[i];

            // Get the index of the character in the alphabet
            int index = toupper(plaintext[i]) - 'A';

            // Shift the index by the key
            int shifted_index = (index + key) % ALPHABET;

            // Get the ASCII code of the shifted character
            int shifted_ascii = shifted_index + 'A';

            // Print the shifted character
            printf("%c", islower(plaintext[i]) ? tolower(shifted_ascii) : shifted_ascii);
        }
        else
        {
            // Print the character unchanged
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;
}

