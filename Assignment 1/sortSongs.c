#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

//songs of a specific artist alphabetically
void sortSongs(char songsOfAnArtist[][80], int numOfSongs)
{
    int i=0;
    int j=0;
    int minIndex=0;
    int minIndexChanged=0;

    char swap[80];

    for(i=0; i<(numOfSongs-1); i++)
    {
        minIndex = i;
        for(j=i+1; j<numOfSongs; j++)
        {
            if(strcmp(songsOfAnArtist[j], songsOfAnArtist[minIndex]) < 0)
            {
                minIndex = j;
                minIndexChanged = 1;
            }
        }
        if(minIndexChanged==1)
        {
            memset(swap, '$', 80-2);
            swap[80-1] = '\0';
            strcpy(swap, songsOfAnArtist[i]);
            strcpy(songsOfAnArtist[i], songsOfAnArtist[minIndex]);
            strcpy(songsOfAnArtist[minIndex], swap);
            minIndexChanged = 0;
        }
    }
}
