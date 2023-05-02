#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    int letters = 0, words = 1, sentences = 0;

    // Read input from user
    printf("Text: ");
    while ((c = getchar()) != '\n')
    {
        // Count letters
        if (isalpha(c))
        {
            letters++;
        }
        // Count words
        else if (isspace(c))
        {
            words++;
        }
        // Count sentences
        else if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Calculate average letters and sentences per 100 words
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    // Calculate Coleman-Liau index
    int index = (int) (0.0588 * L - 0.296 * S - 15.8 + 0.5);

    // Output grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

