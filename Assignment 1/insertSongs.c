#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

//inserts songs from the console into an array of songs for each artist
int insertSongs(char songs[][80], char artist[])
{
    int i, length;

    for(i=0; i<3; i++)
    {
        printf("Enter song %d for %s", i+1, artist);
        fgets(songs[i], 80, stdin);
        if(songs[i][0]=='\n')
            break;
        length = strlen(songs[i]);
        songs[i][length-1] = '\0';
    }
    if(i>0)
        return i;
    else
        return 0;
}

