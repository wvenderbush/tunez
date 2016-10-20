#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "music_lib.h"
#include "list.h"

//Winston Venderbush

song_node * table[26];

int main() {

	//initialize the library to NULL values, for ease of use
	init_lib(table);

	//adding some songs to the library
	char title[30] = "Closer";
	char artist[30] = "The Chainsmokers";
	add_song(table, title, artist);

	strcpy(title, "Heathens");
	strcpy(artist, "twenty one pilots");
	add_song(table, title, artist);

	strcpy(title, "starboy");
	strcpy(artist, "the weeknd");
	add_song(table, title, artist);

	strcpy(title, "broccoli");
	strcpy(artist, "d.r.a.m.");
	add_song(table, title, artist);

	strcpy(title, "cold water");
	strcpy(artist, "major lazer");
	add_song(table, title, artist);

	strcpy(title, "treat you better");
	strcpy(artist, "sean mendez");
	add_song(table, title, artist);

	strcpy(title, "cheap thrills");
	strcpy(artist, "sia");
	add_song(table, title, artist);

	strcpy(title, "i hate you i love you");
	strcpy(artist, "gnash");
	add_song(table, title, artist);

	strcpy(title, "don't let me down");
	strcpy(artist, "the chainsmokers");
	add_song(table, title, artist);

	strcpy(title, "ride");
	strcpy(artist, "twenty one pilots");
	add_song(table, title, artist);

	strcpy(title, "one dance");
	strcpy(artist, "drake");
	add_song(table, title, artist);

	strcpy(title, "Sucker for Pain");
	strcpy(artist, "Lil Wayne");
	add_song(table, title, artist);

	strcpy(title, "we don't talk anymore");
	strcpy(artist, "charlie puth");
	add_song(table, title, artist);

	strcpy(title, "hymn for the weekend");
	strcpy(artist, "coldplay");
	add_song(table, title, artist);

	strcpy(title, "panda");
	strcpy(artist, "desiigner");
	add_song(table, title, artist);

	//printing the whole library, to show it off
	printf("\n\nMy Library:\n");
	print_library(table);

	printf("\n");

	//Searching by song:
	printf("Searching for 'i hate you i love you' by gnash:\n");
	strcpy(title, "i hate you i love you");
	search_song(table, title);

	printf("\n");

	//Searching by artist:
	printf("Searching for a song by D.R.A.M. :\n");
	strcpy(artist, "D.R.A.M.");
	search_artist(table, artist);

	printf("\n");

	//Printing by letter:
	printf("Printing all songs that begin with the letter 'h' :\n");
	char letter = 'h';
	print_letter(table, letter);

	printf("\n");

	//Printing by artist:
	printf("Printing all songs by The Chainsmokers :\n");
	strcpy(artist, "The Chainsmokers");
	print_artist(table, artist);

	printf("\n");

	//Shuffling playlist (creating shuffle playlist of 5 random songs):
	printf("Shuffled playlist of 5 random songs :\n");
	shuffle(table, 5);

	printf("\n");

	//Deleting songs from the library:
	printf("### Deleting Songs from from the library ### :\n");
	printf("-----------------------------------------------------------------\n");
	printf("Original Full Library:\n");
	print_library(table);

	printf("\n");

	printf("'Closer' removed from Library\n");
	strcpy(title, "closer");
	delete_song(table, title);
	print_library(table);

	printf("\n");

	printf("'Starboy' removed from Library\n");
	strcpy(title, "starboy");
	delete_song(table, title);
	print_library(table);

	printf("\n");

	printf("'Cold Water' removed from Library\n");
	strcpy(title, "cold water");
	delete_song(table, title);
	print_library(table);

	printf("\n");

	printf("### Deleting/Free Entire Library ### :\n");
	printf("--------------------------------------\n");

	printf("Original Full Library:\n");
	print_library(table);

	printf("\n");

	printf("Cleared Library\n");
	delete_all(table);
	print_library(table); //nothing left to print, prints nothing!

	printf("\n");

	printf("Attempting print...\n");
	print_library(table); //nothing left to print, prints nothing!

	printf("\n");

	printf("Library clear, nothing left to print!\n");





}