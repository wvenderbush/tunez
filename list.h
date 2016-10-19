#ifndef DEFINED
#define DEFINED

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


//auxiliary functions
struct song_node * start_list( char *nname, char *nartist );
char * strlwr(char * str);
struct song_node * start_list( char *nname, char *nartist );

//assigned functions
void print_list( struct song_node * );
struct song_node * insert_front( struct song_node *n, char *nname, char *nartist );
struct song_node * insert_order( struct song_node *n, char *nname, char *nartist );
struct song_node * find_song( struct song_node *n, char *findname );
struct song_node * find_artist( struct song_node *n, char *findartist );
struct song_node * random_node( struct song_node *n );
struct song_node * remove_node( struct song_node *list, char * findname );
struct song_node * free_all( struct song_node *n );

#endif