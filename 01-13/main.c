#include <stdio.h>

#define MAX_CHARACTERS 12

int main() {
    printf("Please type some characters...\n");
    int c, i, characterCount;
    int wordLengths[MAX_CHARACTERS];
    characterCount = 0;
    
    for (i = 0; i < MAX_CHARACTERS; ++i) {
        wordLengths[i] = 0;
    }
    
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (characterCount > 0) {
                if (characterCount <= MAX_CHARACTERS) {
                    ++wordLengths[characterCount - 1];
                }
                
                characterCount = 0;
            }
        } else {
            ++characterCount;
        }
    }
    
    printf("\n\nHorizontal Histogram\n\n");
    
    for (i = 0; i < MAX_CHARACTERS; ++i) {
        int wordCount = wordLengths[i];
        printf("%2d |", i + 1);
        
        for (int j = 0; j < wordCount; ++j) {
            putchar('#');
        }
        putchar('\n');
    }
    
    printf("\n\nVertical Histogram\n\n");
    
    // Rows
    for (i = MAX_CHARACTERS; i > 0 ; --i) {
        // Columns
        for (int j = 0; j < MAX_CHARACTERS; ++j) {
            int wordCount = wordLengths[j];
            
            if (wordCount >= i) {
                printf(" ##");
            } else {
                printf("   ");
            }
        }
        putchar('\n');
    }
    
    for (i = 0; i < MAX_CHARACTERS; ++i) {
        printf("---");
    }
    
    putchar('\n');
    
    for (i = 0; i < MAX_CHARACTERS; ++i) {
        printf("%3d", i + 1);
    }
    
    putchar('\n');
}
