#include <stdio.h>

#define MAX_CANDIDATES 3
#define MAX_VOTERS 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];
int candidates[MAX_CANDIDATES] = {0, 1, 2};
char* candidate_names[MAX_CANDIDATES] = {"Alice", "Bob", "Charlie"};
int num_candidates = MAX_CANDIDATES;

void print_winner(int winner) {
    printf("%s is the winner\n", candidate_names[winner]);
}

int count_first_choices(int num_voters) {
    int counts[MAX_CANDIDATES] = {0};

    for (int i = 0; i < num_voters; i++) {
        counts[preferences[i][0]]++;
    }

    for (int i = 0; i < num_candidates; i++) {
        if (counts[i] > num_voters / 2) {
            return i;
        }
    }

    return -1;
}

void remove_candidate(int candidate) {
    for (int i = 0; i < MAX_VOTERS; i++) {
        for (int j = 0; j < num_candidates; j++) {
            if (preferences[i][j] == candidate) {
                for (int k = j; k < num_candidates - 1; k++) {
                    preferences[i][k] = preferences[i][k + 1];
                }
            }
        }
    }
    num_candidates--;
}

void runoff(int num_voters) {
    while (1) {
        int winner = count_first_choices(num_voters);
        if (winner != -1) {
            print_winner(winner);
            return;
        }

        int min_votes = MAX_VOTERS;
        int least_popular = -1;
        for (int i = 0; i < num_candidates; i++) {
            int count = 0;
            for (int j = 0; j < num_voters; j++) {
                if (preferences[j][0] == i) {
                    count++;
                }
            }
            if (count < min_votes) {
                min_votes = count;
                least_popular = i;
            }
        }

        remove_candidate(least_popular);
    }
}

int main(void) {
    // In this example, there are 3 candidates and 9 voters.
    // The voters' preferences are hardcoded for simplicity.
    int num_voters = 9;
    int votes[MAX_VOTERS][MAX_CANDIDATES] = {
        {0, 1, 2},
        {1, 0, 2},
        {2, 1, 0},
        {2, 0, 1},
        {0, 2, 1},
        {1, 2, 0},
        {1, 0, 2},
        {2, 0, 1},
        {2, 1, 0},
    };

    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            preferences[i][j] = votes[i][j];
        }
    }

    runoff(num_voters);
    return 0;
}

