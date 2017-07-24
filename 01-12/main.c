#include <stdio.h>


int main() {
    printf("Please type some characters...\n");
    int character, characterCount;
    characterCount = 0;
    
    while((character = getchar()) != EOF) {
        if (character == ' ' || character == '\n' || character == '\t') {
            if (characterCount > 0) {
                putchar('\n');
                characterCount = 0;
            }
        } else {
            putchar(character);
            ++characterCount;
        }
    }
}
