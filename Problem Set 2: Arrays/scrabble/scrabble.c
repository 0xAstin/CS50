#include <stdio.h>
#include <ctype.h>

int get_score(char c);
int get_word_score(const char *word);

int main(void)
{
    // prompt for player 1's word
    printf("Player 1: ");
    char word1[50];
    scanf("%s", word1);

    // calculate player 1's score
    int score1 = get_word_score(word1);

    // prompt for player 2's word
    printf("Player 2: ");
    char word2[50];
    scanf("%s", word2);

    // calculate player 2's score
    int score2 = get_word_score(word2);

    // determine the winner or if it's a tie
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(char c)
{
    // assign score based on letter
    switch (toupper(c))
    {
        case 'A': return 1;
        case 'B': return 3;
        case 'C': return 3;
        case 'D': return 2;
        case 'E': return 1;
        case 'F': return 4;
        case 'G': return 2;
        case 'H': return 4;
        case 'I': return 1;
        case 'J': return 8;
        case 'K': return 5;
        case 'L': return 1;
        case 'M': return 3;
        case 'N': return 1;
        case 'O': return 1;
        case 'P': return 3;
        case 'Q': return 10;
        case 'R': return 1;
        case 'S': return 1;
        case 'T': return 1;
        case 'U': return 1;
        case 'V': return 4;
        case 'W': return 4;
        case 'X': return 8;
        case 'Y': return 4;
        case 'Z': return 10;
        default: return 0;
    }
}

int get_word_score(const char *word)
{
    // calculate the score for a word
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        score += get_score(word[i]);
    }
    return score;
}

