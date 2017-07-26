#include <stdio.h>

#define MAX_LENGTH 1000

// Signatures / prototypes
int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

int main() {
    int length;
    int max;
    char line[MAX_LENGTH];
    char longest[MAX_LENGTH];
    
    max = 0;
    
    while((length = getLine(line, MAX_LENGTH)) > 0) {
        if (length > max) {
            max = length;
            copy(longest, line);
        }
    }
    
    if (max > 0) {
        printf("Length: %d\n", length);
        printf("Line: %s", longest);
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

void copy(char to[], char from[]) {
    int i = 0;
    
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
