#include "list.h"

#ifndef DEFINED2
#define DEFINED2


//Winston Venderbush

//functions
void init_lib(song_node ** table);
void add_song(song_node ** lib, char * name, char * artist);
struct song_node * search_song(song_node ** lib, char * name);
struct song_node * search_artist(song_node ** lib, char * artist);
void print_letter(song_node ** lib, char letter);
void print_artist(song_node ** lib, char * artist);
void print_library(song_node ** lib);
void shuffle(song_node ** lib, int num);
void delete_song(song_node ** lib, char * name);
void delete_all(song_node ** lib);

#endif