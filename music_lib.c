#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>  

#include "music_lib.h"
#include "list.h"

//Winston Venderbush



void init_lib(song_node ** table){
  int i;
  for (i = 0; i < 25; i++){
    table[i] = NULL;
  }
}

void add_song(song_node ** lib, char * name, char * artist){
  char first = *(strlwr(&(name[0])));
  int index = (first - 'a');
  if (lib[index] == NULL){
    lib[index] = start_list(name, artist);
  }
  else{
    lib[index] = insert_order(lib[index], name, artist);
  }
}

struct song_node * search_song(song_node ** lib, char * name){
  char first = *(strlwr(&(name[0])));
  int index = (first - 'a');
  song_node * song = find_song(lib[index], name);
  if (song != NULL){
    printf("%s - %s\n", song->name, song->artist );
  }
  else{
    printf("Song not found!\n");
  }
  return song;
}

struct song_node * search_artist(song_node ** lib, char * artist){
   for (int i = 0; i < 26; i++){
    struct song_node * song = find_artist(lib[i], artist);
    if (song != NULL){
      printf("%s - %s\n", song->name, song->artist );
      return song;
    }
  }
  printf("Artist not found!\n");
  return NULL;
}

void print_letter(song_node ** lib, char letter){
  letter = *(strlwr(&(letter)));
  int index = (letter - 'a');
  print_list(lib[index]);
}

void print_artist(song_node ** lib, char * artist){
  artist = strlwr(artist);
  int f = 0;

  int index;
  printf("[ ");
  for (index = 0; index < 26; index++){
    song_node * curr = lib[index];
    curr = find_artist(curr, artist);

    while (curr != NULL){
      if (f){
        printf(", ");
      }
      printf("%s - %s", curr->name, curr->artist );
      f = 1;
      curr = curr->next;
      curr = find_artist(curr, artist);
      if (f != 1 & curr != 0){
        printf(", ");
      }
    }

  }
  printf(" ]\n");
}

void print_library(song_node ** lib){
  int flag = 0;
  int i;
  for (int i = 0; i < 25; i++){
    if (lib[i] != NULL){
      flag = 1;
      int z = i + 97;
      printf("%c: ", z);
      print_list(lib[i]);
    }
  }
  if (flag == 0){
    printf("Library Empty!\n");
  }
}

void shuffle(song_node ** lib, int num){
  sranddev();
  while (num > 0){
    int len = 25;
    int r = rand() % len;
    if (lib[r] != NULL){
      song_node * song = random_node(lib[r]);
      char * name = song->name;
      char * artist = song->artist;
      printf("%s - %s\n", name, artist);
      num--;
    }
    sranddev();
  } 
}

void delete_song(song_node ** lib, char * name){
  char first = *(strlwr(&(name[0])));
  int index = (first - 'a');
  lib[index] = remove_node(lib[index], name);
}

void delete_all(song_node ** lib){
  int i;
  for (int i = 0; i < 26; i++){
    if (lib[i] != NULL){
      free_all(lib[i]);
      lib[i] = NULL;
    }
  }
}






