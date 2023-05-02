#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_VOTERS 100

typedef struct
{
    char name[20];
    int votes;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int candidate_count;

int get_valid_vote(char *name);
void print_winner();

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s candidate1 candidate2 ... \n", argv[0]);
        return 1;
    }

    if (argc - 1 > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 2;
    }

    // initialize candidates
    candidate_count = argc - 1;
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }

    // get number of voters
    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // get votes from user
    for (int i = 0; i < voter_count; i++)
    {
        char name[20];
        int index = get_valid_vote(name);

        if (index != -1)
        {
            candidates[index].votes++;
        }
        else
        {
            printf("Invalid vote.\n");
        }
    }

    // print winner(s) of election
    print_winner();
}

// prompt the user for a valid vote and return the index of the candidate in the candidates array
int get_valid_vote(char *name)
{
    printf("Vote: ");
    scanf("%s", name);

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

// print the winner(s) of the election
void print_winner()
{
    int max_votes = 0;

    // find maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // print candidate(s) with maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

