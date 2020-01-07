#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include<time.h>
/*
    This method sorts the artists alphabetically
    Inputs:
    sortedArtists: the array of artists that that should be sorted
    numOfArtists: the total number of artists
*/
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
/*
    This method sorts the songs of a specific artist alphabetically.
    Inputs:
    songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
    numOfArtists: the number of artists provided from the standard input
*/
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
            ///printf("i: %d, j: %d, minIndex: %d\n", i, j, minIndex);
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
            ///printf("%s\n", swap);
            strcpy(swap, songsOfAnArtist[i]);
            strcpy(songsOfAnArtist[i], songsOfAnArtist[minIndex]);
            strcpy(songsOfAnArtist[minIndex], swap);
            minIndexChanged = 0;
        }
    }
}
/*
    This method shuffles a set of songs.
    Inputs:
    songsToBeShuffled: the array of the songs that should be shuffled
    numOfSongs: the number of songs to be shuffled
*/
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
    /*for(i=0; i<numOfSongs; i++)
    {
        printf("%s\n", songsToBeShuffled[i]);
    }*/
}

