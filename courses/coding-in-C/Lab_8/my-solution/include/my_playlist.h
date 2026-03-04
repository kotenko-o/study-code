#ifndef MY_PLAYLIST_H
#define MY_PLAYLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 5

struct Song {
    char* title;
    char* artist;
    struct Song* p_next;
};

struct Playlist {
    struct Song* p_head;
};

struct Playlist *init_playlist(void);

struct Song *add_song(struct Playlist *p_playlist, char title[], char artist[]);

int print_playlist(struct Playlist *p_playlist);

int delete_first_song(struct Playlist *p_playlist);

int delete_playlist(struct Playlist *p_playlist);

#endif