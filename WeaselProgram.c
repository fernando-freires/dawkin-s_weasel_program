#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define GENERATIONS 100                    // Number of offspring per generation
#define MUTATEPROB 0.05                  // Probability of mutation per letter per copy

float rnd(void)
{ // Return random number between 0 and 1.
    return (float)rand() / RAND_MAX;
}
int randomIntGenerator(int max)
{
    int result = rnd() * (max + 1);
    result %= max + 1;
    return result;
}

char randomCharGenerator()
{
    int c = randomIntGenerator(26);
    if (c == 0) return ' ';
    else return (char)(c + 64);
}

void weaselProgram(char *phrase)
{
    char *current;
    char *generations[GENERATIONS];
    int score[GENERATIONS];
    int generation;
    int n;
    int i;
    int highestscorer;
    int startscore;
    srand((int)time(NULL)); // Random seed...
    current = malloc(strlen(phrase) + 1); // +1 to hold the terminating null character.
    assert(current != NULL);

    for (n = 0; n < GENERATIONS; n++)
    { // Initialise the offspring strings.
        generations[n] = malloc(strlen(phrase) + 1);
        assert(generations[n] != NULL);
    }

    for (i = 0; i < strlen(phrase); i++)
    { // Randomise the starting string.
        current[i] = randomCharGenerator();
    }
    current[i] = '\0';
    startscore = 0; // Work out the score of generation zero.
    for (i = 0; i < strlen(phrase); i++)
    {
        if (current[i] == phrase[i])
        {
            startscore++;
        }
    }
    generation = 0;
    printf("%3d: %s", generations, current);
    printf(" -- score: %d\n", startscore);

    while (1)
    {
        generation++;
        for (n = 0; n < GENERATIONS; n++)
        { // Do for each new string...
            score[n] = 0;
            for (i = 0; i < strlen(phrase); i++)
            { // Do for each letter...
                if (rnd() < MUTATEPROB)
                { // Mutate or just copy.
                    generations[n][i] = randomchar();
                }
                else
                {
                    generations[n][i] = current[i];
                }
                if (phrase[i] == generation[n][i])
                { // Keep score.
                    score[n]++;
                }
            }
            generations[n][i] = '\0';
        }
        highestscorer = 0;
        for (n = 1; n < GENERATIONS; n++)
        { // Find highest scoring new string.
            if (score[n] > score[highestscorer])
            {
                highestscorer = n;
            }
        }
        strcpy(current, generations[highestscorer]);     // Make best string into "current" string
        printf("%3d: %s", generation, current);          // Print it.
        printf(" -- score: %d\n", score[highestscorer]); // Print its score.
        if (strcmp(current, phrase) == 0) break;

    }

    return 0;
}

int main(void)
{
    
}