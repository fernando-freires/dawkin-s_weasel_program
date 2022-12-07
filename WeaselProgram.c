#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define GENERATIONS 100
#define MPROB 0.05

float randomFloatGenerator()
{
    return (float)rand() / RAND_MAX;
}

int randomIntGenerator(int max)
{
    int result = randomFloatGenerator() * (max + 1);
    result %= max + 1;
    return result;
}

char randomCharGenerator()
{
    char caract[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'};

    int c = randomIntGenerator(26);
    if (c == 0)
        return ' ';
    else
        return caract[c];
}

int firstScore(char *current, char *phrase)
{
    int startscore = 0;

    for (int i = 0; i < strlen(phrase); i++)
    {
        if (current[i] == phrase[i])
        {
            startscore++;
        }
    }

    return startscore;
}

void weaselProgram(char *phrase)
{
    char *current;
    char *generations[GENERATIONS];

    int score[GENERATIONS];
    int currentgen;
    int n, i;
    int highestscorer, startscore;

    srand((int)time(NULL));
    current = malloc(strlen(phrase) + 1);
    assert(current != NULL);

    // Inicializa as strings de gerações
    for (n = 0; n < GENERATIONS; n++)
    {
        generations[n] = malloc(strlen(phrase) + 1);
        assert(generations[n] != NULL);
    }

    // Cria primeira string randomicamente
    for (i = 0; i < strlen(phrase); i++)
    {
        current[i] = randomCharGenerator();
    }
    current[i] = '\0';
    startscore = firstScore(current, phrase);

    currentgen = 0;
    printf("Generation %3d: %s", currentgen, current);
    printf(" | Word Score: %d\n", startscore);

    while (1)
    {
        currentgen++;
        // Para cada string
        for (n = 0; n < GENERATIONS; n++)
        {
            score[n] = 0;
            // Para cada palavra
            for (i = 0; i < strlen(phrase); i++)
            {
                // Ou muda ou copia
                if (randomFloatGenerator() < MPROB)
                {
                    generations[n][i] = randomCharGenerator();
                }
                else
                {
                    generations[n][i] = current[i];
                }

                // Salva o score
                if (phrase[i] == generations[n][i])
                {
                    score[n]++;
                }
            }
            generations[n][i] = '\0';
        }

        highestscorer = 0;
        // Encontra o melhor score nas novas strings
        for (n = 1; n < GENERATIONS; n++)
        {
            if (score[n] > score[highestscorer])
            {
                highestscorer = n;
            }
        }
        strcpy(current, generations[highestscorer]);
        printf("Generation %3d: %s", currentgen, current);
        printf(" | Word Score: %d\n", score[highestscorer]);
        if (strcmp(current, phrase) == 0)
            break;
    }
}

int main(void)
{
    //METHINKS IT IS LIKE A WEASEL
    char phrase[28];
    printf("Type a 28 characters string (only uppercase and spaces):\n");
    fgets(phrase, sizeof(phrase), stdin);
    weaselProgram(phrase);

    return 1;
}