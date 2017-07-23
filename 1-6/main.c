#include <stdio.h>

int main() {
    printf("Please type some characters...\n");
    
    int c = getchar();
    
    // Should return 0 or 1.
    // For Mac: https://stackoverflow.com/questions/21364313/signal-eof-in-mac-osx-terminal
    int test = c == EOF;
    
    printf("%d\n", test);
}

