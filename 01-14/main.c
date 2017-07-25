#include <stdio.h>

// # of alphabet letters * 2 (lower and upper)
#define CHARACTER_COUNT 52

// This only counts alphabet characters and
// does not consider digits or special characters.
int main() {
    int c, characters[CHARACTER_COUNT];
    
    for (int i = 0; i < CHARACTER_COUNT; ++i) {
        characters[i] = 0;
    }
    
    printf("Please type some characters...\n");
    
    while((c = getchar()) != EOF) {
        int index;
        
        if ('A' <= c && c <= 'Z') {
            index = c - 'A';
            ++characters[index];
        } else if ('a' <= c && c <= 'z') {
            index = c - 'a' + (CHARACTER_COUNT / 2);
            ++characters[index];
        }
    }
    
    putchar('\n');
    
    // Histogram
    for (int i = 0; i < CHARACTER_COUNT; ++i) {
        int count = characters[i];
        int character;
        
        if (i + 'A' <= 'Z') {
            character = i + 'A';
        } else {
            character = (i - (CHARACTER_COUNT / 2)) + 'a';
        }
        
        putchar(character);
        printf(" |");
        
        for (int j = 0; j < count; ++j) {
            putchar('#');
        }
        putchar('\n');
    }
}
