#include <stdio.h>
#include <string.h>

#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
string candidates[MAX];

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool cycle(int start, int end);
void print_winner(void);

int main(void)
{
    // Your main function code here
}

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
}

void sort_pairs(void)
{
    // Implement bubble sort
    for (int i = pair_count - 1; i > 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            int winner_diff_j = preferences[pairs[j].winner][pairs[j].loser];
            int winner_diff_j1 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
            
            if (winner_diff_j < winner_diff_j1)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

bool cycle(int start, int end)
{
    if (start == end)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i] && cycle(start, i))
        {
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
           

