#include <stdio.h>

#define MAX_LENGTH 1000
#define MIN_LENGTH 80

// Signatures / prototypes
int getLine(char line[], int maxLine);

int main() {
    int length;
    int max;
    char line[MAX_LENGTH];
    
    max = 0;
    
    while((length = getLine(line, MAX_LENGTH)) > 0) {
        if (length > max) {
            max = length;
        }
        
        if (length > MIN_LENGTH) {
            printf("Length: %d\n", length - 1);
            printf("Line: %s\n", line);
        }
    }
    
    return 0;
}

int getLine(char s[], int limit) {
    int c, i;
    
    // To remove uninitialised warning.
    c = 0;
    
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    
    return i;
}
