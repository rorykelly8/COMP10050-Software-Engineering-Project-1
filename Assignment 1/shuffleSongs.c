#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include<time.h>
//shuffles a set of songs

void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs)
{
    char swap[80];
    int i, j;
    srand(time(NULL));

    for(i=1; i<numOfSongs; i++)
    {
        j = rand()%(i+1);
        if(j!=i)
        {
            strcpy(swap, songsToBeShuffled[j]);
            strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
            strcpy(songsToBeShuffled[i], swap);
        }
    }
}
