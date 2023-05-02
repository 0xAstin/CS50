#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to check if a key is valid
int is_key_valid(char *key);

int main(int argc, char *argv[])
{
    // Check if the user provided a command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Get the key from the command-line argument
    char *key = argv[1];

    // Check if the key is valid
    if (!is_key_valid(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt the user for a plaintext message
    char plaintext[101];
    printf("plaintext: ");
    fgets(plaintext, 101, stdin);

    // Encrypt the plaintext message using the key
    int n = strlen(plaintext);
    char ciphertext[n];
    for (int i = 0; i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            int index = toupper(c) - 'A';
            if (islower(c))
            {
                ciphertext[i] = tolower(key[index]);
            }
            else
            {
                ciphertext[i] = key[index];
            }
        }
        else
        {
            ciphertext[i] = c;
        }
    }

    // Print the ciphertext message
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

int is_key_valid(char *key)
{
    int count[ALPHABET_SIZE] = {0};
    int n = strlen(key);

    if (n != ALPHABET_SIZE)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        char c = toupper(key[i]);
        if (!isalpha(c))
        {
            return 0;
        }
        if (count[c - 'A'] > 0)
        {
            return 0;
        }
        count[c - 'A']++;
    }

    return 1;
}

