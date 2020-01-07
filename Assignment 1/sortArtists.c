#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

//sorts the artists alphabetically
void sortArtists(char sortedArtists[][80] , int numOfArtists)
{
    int i=0;
    int j=0;
    int minIndex=0;
    int minIndexChanged=0;

    char swap[80];

    for(i=0; i<(numOfArtists-1); i++)
    {
        minIndex = i;
        for(j=i+1; j<numOfArtists; j++)
        {
            if(strcmp(sortedArtists[j], sortedArtists[minIndex]) < 0)
            {
                minIndex = j;
                minIndexChanged = 1;
            }
        }
        if(minIndexChanged==1)
        {
            memset(swap, '$', 80-2);
            swap[80-1] = '\0';
            strcpy(swap, sortedArtists[i]);
            strcpy(sortedArtists[i], sortedArtists[minIndex]);
            strcpy(sortedArtists[minIndex], swap);
            minIndexChanged = 0;
        }
    }
}
