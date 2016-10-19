#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>  

#include "list.h"

//Winston Venderbush

char * strlwr(char *str){ //unassigned auxiliary function
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower(*p);
      p++;
  }

  return str;
}


struct song_node * start_list( char *nname, char *nartist ) { //unassigned auxiliary function

  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  new->next = NULL;
  strcpy(new->name, strlwr(nname));
  strcpy(new->artist, strlwr(nartist));

  return new;
}


void print_list( struct song_node *n ) {

  printf("[ ");
  
  while(n) {
    
    printf("%s - %s", n->name, n->artist );
    n = n->next;
    if (n != 0){
      printf(", ");
    }
  }
  printf(" ]\n");
}


struct song_node * insert_front( struct song_node *n, char *nname, char *nartist ) {

  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  new->next = n;
  strcpy(new->name, strlwr(nname));
  strcpy(new->artist, strlwr(nartist));

  return new;
}

struct song_node * insert_order( struct song_node *n, char *nname, char *nartist ){

  struct song_node *start = n;
  struct song_node *prev = NULL;

  if (strcmp(nname, n->name) < 0){
    struct song_node *first = insert_front(n, nname, nartist);
    return first;
  }

  while ( n ){

    if (strcmp(nname, n->name) < 0){
      struct song_node *insert = insert_front(n, nname, nartist);
      prev->next = insert;
      return start;
    }
      prev = n;
      n = n->next;
  }
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new->name, strlwr(nname));
  strcpy(new->artist, strlwr(nartist));
  prev->next = new;
  return start;
}

struct song_node * find_song( struct song_node *n, char *findname ){

  while ( n ) {

    if (strcmp(strlwr(findname), n->name) == 0){
      return n;
    }
    else {
      n = n->next;
    }
  }
  return 0;
}

struct song_node * find_artist( struct song_node *n, char *findartist ){
  while ( n ) {
    
    if (strcmp(strlwr(findartist), n->artist) == 0){
      return n;
    }
    else {
      n = n->next;
    }  
  }
  return NULL;
}

struct song_node * random_node( struct song_node *list ){
  int len = 0;
  struct song_node *start = list;
  while ( list ){
    len++;
    list = list->next;
  }
  list = start;
  // int seed = time(NULL);
  // srand(seed);
  sranddev();
  int r = rand() % len;
  while (r > 0){
    list = list->next;
    r--;
  }
  return list;
}


struct song_node * remove_node( struct song_node * list, char * findname ){ 
  struct song_node * rem = find_song(list, findname);

  song_node *prev = NULL;
  song_node *start = list;

  if (list == rem){
    song_node *f = list->next;
    free(list);
    list = NULL;
    return f;
  }

  while ( list ){
    if (list == rem){
      prev->next = list->next;
      free(list);
      list = NULL;
      return start;
    }
    else{
      prev = list;
      list = list->next;
    }
  }
  return start;
}

//   song_node *prev = NULL;
//   song_node *start = list;

//   while ( list ) {
    
//     if (strcmp(strlwr(findname), list->name) == 0){ 
//       if (prev == NULL){
//         struct song_node *f = list->next;
//         //free(list);
//         list = NULL;
//         return f;
//       }
//       song_node *temp = list->next;
//       prev->next = temp;
//       free(list);
//       list = NULL;
//       return start;

//     }
//     else {
//       prev = list;
//       list = list->next;
//     }
//   }
//   return list;
// }

struct song_node * free_all( struct song_node *n ) {

  struct song_node *f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}

