#include <stdio.h>

int main() {
    printf("Please type some characters...\n");
    int spaceCount = 0;
    int character;
    
    while((character = getchar()) != EOF) {
        if (character == ' ') {
            if (!spaceCount) {
                spaceCount = 1;
                putchar(character);
            }
        } else {
            spaceCount = 0;
            putchar(character);
        }
    }
}
