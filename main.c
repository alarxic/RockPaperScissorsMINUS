#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdbool.h>

char* choices[] = {
    "rock",
    "paper",
    "scissors"
};

int wins = 0;
int losses = 0;

int strExistsInArray(const char* target, const char* array[])
{
    int size = sizeof(choices) / sizeof(choices[0]);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(array[i], target) == 0)
        {
            return i;
        }
    }
    return -1;
}
int random(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}

void gameLoop()
{
    char choice[9];
    printf("\n\nWhat'll it be? : ");
    scanf("%s", choice);

    if (strcmp(strlwr(choice), "stop") == 0)
    {
        printf("So soon? Awh.");
        printf("\nYou won %d time(s), and me? I won %d time(s).", wins, losses);
        scanf("%s", choice);
        return;
    }

    int index = strExistsInArray(strlwr(choice), choices);
    
    if (index != -1)
    {
        index++;
        srand(time(NULL));
        int cpuChoice = random(1,3);
        printf("\nAlright, %s. Not bad, but... you know.\n", choice);
        printf("I choose... %s!", choices[cpuChoice - 1]); // arrays don't start at 1
        if (cpuChoice == index){
            printf("\nA tie, yeowch. Another game!");
        }else{
            if (cpuChoice == 1 && index == 2)
            {
                printf("\nHey, what? Rock gets smothered?\nHow lame... more!"); //
                wins++;
            }
            if (cpuChoice == 1 && index == 3)
            {
                printf("\nJust curdled your measly scissors.\nMore, more!");
                losses++;
            }
            if (cpuChoice == 2 && index == 1)
            {
                printf("\nOh, look! Paper covers rock, you lose.\nGo again!");
                losses++;
            }
            if (cpuChoice == 2 && index == 3)
            {
                printf("\nPaper gets cut by...scissors?\nNo fair! Go again..."); //
                wins++;
            }
            if (cpuChoice == 3 && index == 1)
            {
                printf("\nNo! My scissors!..\nThey were nice, too..."); //
                wins++;
            }
            if (cpuChoice == 3 && index == 2)
            {
                printf("\nGlides right through, hah!\nTry harder.");
                losses++;
            }
        }
    }else{
        printf("That's not a move. Come on, man.");
    }
    gameLoop();
}

void main()
{
    printf("Welcome to Rock-Paper-Scissors Minus!\n\nIt's a game of luck...\nA game of patterns...\nOh, and most importantly, a game of pride.\n\nLet's see how you perform on the battlefield.");
    gameLoop();
}