#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

int main(void)
{
	//The array containing artists names
	char artists[4][80];
	//The array containing the sorted artists
	char sortedArtists[4][80];
	//Songs for Artist 1
	char songsArtist1[3][80];
	//Songs for Artist 2
	char songsArtist2[3][80];
	//Songs for Artist 3
	char songsArtist3[3][80];
	//Songs for Artist 4
	char songsArtist4[3][80];
    //all inputted songs
	char allSongs[12][80];
    //songs that have been shuffled
	char shuffledSongs[24][80];
    //the size
	int sizeShuffledPlaylist = 0;
    //number of inputted songs
	int totalNumSongs = 0;
	//The total number of artists
	int numOfArtists=0;
	//The total number of songs for each artist
	int numSongsPerArtist[4];
	//counters
	int i, j, count=0;
	int length;

    //The artists and songs are taken in from the console using the function insertSongs
    for(i=0; i<4; i++)
    {
        printf("\nInsert an artist/group name:\n");
        fgets(artists[i], 80, stdin);
        //If the return command is pressed it exits
        if(artists[i][0]=='\n')
            break;
        else
        {
            printf("\n");
            numOfArtists++;
            if(i+1==1)
                numSongsPerArtist[i] = insertSongs(songsArtist1, artists[i]);
            if(i+1==2)
                numSongsPerArtist[i] = insertSongs(songsArtist2, artists[i]);
            if(i+1==3)
                numSongsPerArtist[i] = insertSongs(songsArtist3, artists[i]);
            if(i+1==4)
                numSongsPerArtist[i] = insertSongs(songsArtist4, artists[i]);
        }
        length = strlen(artists[i]);
        artists[i][length-1] = '\0';
    }
    //counts number of songs
    for(i=0; i<numOfArtists; i++)
    {
        totalNumSongs += numSongsPerArtist[i];
    }
    //copies elements of artists into sortedArtists
	for(i=0; i<numOfArtists; i++)
	{
		strcpy(sortedArtists[i], artists[i]);
	}
	//copies all inputted songs into allSongs
    for(i=0; i<numOfArtists; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i==0)
            {
                strcpy(allSongs[count], songsArtist1[j]);
                count++;
            }
            if(i==1)
            {
                strcpy(allSongs[count], songsArtist2[j]);
                count++;
            }
            if(i==2)
            {
                strcpy(allSongs[count], songsArtist3[j]);
                count++;
            }
            if(i==3)
            {
                strcpy(allSongs[count], songsArtist4[j]);
                count++;
            }
        }
    }

	//The function sortArtists sorts the array of the artists and the function sortSongs sorts the songs of each artist
	//Each artist is printed alphabetically and for each of them the list of songs is sorted and printed alphabetically
	sortArtists(sortedArtists, numOfArtists);
	if(numOfArtists>=1)
        sortSongs(songsArtist1, numSongsPerArtist[0]);
    if(numOfArtists>=2)
        sortSongs(songsArtist2, numSongsPerArtist[1]);
	if(numOfArtists>=3)
        sortSongs(songsArtist3, numSongsPerArtist[2]);
	if(numOfArtists>=4)
        sortSongs(songsArtist4, numSongsPerArtist[3]);

    printf("Sorted list of songs:\n");
    for(i=0; i<numOfArtists; i++)
    {
        printf("%s\n", sortedArtists[i]);
        for(j=0; j<numSongsPerArtist[i]; j++)
        {
            if(strcmp(sortedArtists[i], artists[0])==0)
                printf(" - %s\n", songsArtist1[j]);
            else if(strcmp(sortedArtists[i], artists[1])==0)
                printf(" - %s\n", songsArtist2[j]);
            else if(strcmp(sortedArtists[i], artists[2])==0)
                printf(" - %s\n", songsArtist3[j]);
            else if(strcmp(sortedArtists[i], artists[3])==0)
                printf(" - %s\n", songsArtist4[j]);
        }
    }

	//The function shuffleSongs shuffles all the songs
    //The list of shuffled songs is printed

    printf("Shuffled Playlist:\n");
    shuffleSongs(allSongs, totalNumSongs);
    for(i=0; i<totalNumSongs; i++)
    {
        strcpy(shuffledSongs[i], allSongs[i]);
        sizeShuffledPlaylist++;
    }
    for(i=0; i<totalNumSongs; i++)
    {
        printf("%s\n", shuffledSongs[i]);
    }

    shuffleSongs(allSongs, totalNumSongs);
    for(i=0; i<totalNumSongs; i++)
    {
        strcpy(shuffledSongs[i], allSongs[i]);
        sizeShuffledPlaylist++;
    }
    for(i=0; i<totalNumSongs; i++)
    {
        printf("%s\n", shuffledSongs[i]);
    }

	return 0;
}


