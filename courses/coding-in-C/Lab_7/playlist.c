#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Song {
    char* title;
    char* artist;
    struct Song* p_next;
};

struct Playlist {
    struct Song* p_head;
};

struct Playlist *init_playlist() {
    struct Playlist *p_new_playlist = (struct Playlist*)malloc(sizeof(struct Playlist));
    if (!p_new_playlist) {
        return NULL;
    }
    p_new_playlist->p_head = NULL;
    return p_new_playlist;
}

struct Song *add_song(struct Playlist *p_playlist, char title[], char artist[]) {
    if (!p_playlist) return NULL;

    struct Song *p_new_song = (struct Song*)malloc(sizeof(struct Song));
    if (!p_new_song) return NULL;

    p_new_song->title = stdup(title);
    p_new_song->artist = stdup(artist);
    p_new_song->p_next = NULL;

    if (p_playlist->p_head == NULL) {
        p_playlist->p_head = p_new_song;
    } else {
        struct Song *current = p_playlist->p_head;
        while (current->p_next != NULL) {
            current = current->p_next;
        }
        current->p_next = p_new_song;
    }
    return p_new_song;
}

int print_playlist(struct Playlist *p_playlist) {
    if (p_playlist == NULL || p_playlist->p_head == 0) {
        printf("Playlist is empty.");
        return 0;
    }
    int i = 1;
    struct Song *p_song = p_playlist->p_head;
    while (p_song != NULL) {
        printf("| %2d. | Title: %-10s | Artist: %-15s |\n", i, p_song->title, p_song->artist);
        i++;
        p_song = p_song->p_next;
    };
    return 0;
}

int delete_first_song(struct Playlist *p_playlist) {
    if (p_playlist == NULL) {return 1;}
    if (p_playlist->p_head == NULL) {return 0;}
    struct Song *p_next_song = p_playlist->p_head->p_next;
    free(p_playlist->p_head->artist);
    free(p_playlist->p_head->title);
    free(p_playlist->p_head);
    p_playlist->p_head = p_next_song;
    return 0;
}

int delete_playlist(struct Playlist *p_playlist) {
    while (p_playlist->p_head != 0) {
        delete_first_song(p_playlist);
    };
    free(p_playlist);
    return 0;
}

int main() {
    struct Playlist *p_playlist = init_playlist();

    add_song(p_playlist, "Crawling", "Linkin Park");
    add_song(p_playlist, "Layla", "Eric Clapton");
    add_song(p_playlist, "Esperanto", "Max Herre");

    print_playlist(p_playlist);

    printf("\n");

    delete_first_song(p_playlist);

    print_playlist(p_playlist);

    printf("\n");

    delete_playlist(p_playlist);

    return 0;
}