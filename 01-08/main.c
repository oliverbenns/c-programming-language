#include <stdio.h>

int main() {
    printf("Please type some characters...\n");
    int blankCount, tabCount, lineCount, character;
    blankCount = tabCount = lineCount = 0;
    
    while((character = getchar()) != EOF) {
        if (character == '\t') {
            ++tabCount;
        } else if (character == '\n') {
            ++lineCount;
        } else if (character == ' ') {
            ++blankCount;
        }
    }
    
    printf("Number of blanks: %d\n", blankCount);
    printf("Number of tabs: %d\n", tabCount);
    printf("Number of new lines: %d\n", lineCount);
    
}
