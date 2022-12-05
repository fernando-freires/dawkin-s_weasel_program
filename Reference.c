#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TARGET "METHINKS IT IS LIKE A WEASEL" // Only uppercase letters or spaces allowed
#define OFFSPRING 100                         // Number of offspring per generation
#define MUTATEPROB 0.05                       // Probability of mutation per letter per copy

float rnd(void)
{ // Return random number between 0 and 1.
    return (float)rand() / RAND_MAX;
}
int intrnd(int max)
{ // Return integer between 0 and max inclusive.
    int result;
    result = rnd() * (max + 1);
    result %= max + 1;
    return result;
}
char randomchar(void)
{ // Return random uppercase character or space.
    int x;
    x = intrnd(26);
    if (x == 0)
    {
        return ' ';
    }
    else
    {
        return (char)(x + 64);
    }
}
int main(void)
{
    char *target = TARGET;
    char *current;
    char *offspring[OFFSPRING];
    int score[OFFSPRING];
    int generation;
    int n;
    int i;
    int highestscorer;
    int startscore;
    srand((int)time(NULL));               // Random seed...
    current = malloc(strlen(target) + 1); // +1 to hold the terminating null character.
    assert(current != NULL);
    for (n = 0; n < OFFSPRING; n++)
    { // Initialise the offspring strings.
        offspring[n] = malloc(strlen(target) + 1);
        assert(offspring[n] != NULL);
    }
    for (i = 0; i < strlen(target); i++)
    { // Randomise the starting string.
        current[i] = randomchar();
    }
    current[i] = '\0';
    startscore = 0; // Work out the score of generation zero.
    for (i = 0; i < strlen(target); i++)
    {
        if (current[i] == target[i])
        {
            startscore++;
        }
    }
    generation = 0;
    printf("%3d: %s", generation, current);
    printf(" -- score: %d\n", startscore);
    while (1)
    {
        generation++;
        for (n = 0; n < OFFSPRING; n++)
        { // Do for each new string...
            score[n] = 0;
            for (i = 0; i < strlen(target); i++)
            { // Do for each letter...
                if (rnd() < MUTATEPROB)
                { // Mutate or just copy.
                    offspring[n][i] = randomchar();
                }
                else
                {
                    offspring[n][i] = current[i];
                }
                if (target[i] == offspring[n][i])
                { // Keep score.
                    score[n]++;
                }
            }
            offspring[n][i] = '\0';
        }
        highestscorer = 0;
        for (n = 1; n < OFFSPRING; n++)
        { // Find highest scoring new string.
            if (score[n] > score[highestscorer])
            {
                highestscorer = n;
            }
        }
        strcpy(current, offspring[highestscorer]);       // Make best string into "current" string
        printf("%3d: %s", generation, current);          // Print it.
        printf(" -- score: %d\n", score[highestscorer]); // Print its score.
        if (strcmp(current, target) == 0)
        {
            break;
        }
    }
    return 0;
}