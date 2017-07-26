#include <stdio.h>

#define MAX_LENGTH 1000

// Signatures / prototypes
int getLine(char line[], int maxLine);
void stripBlanks(char to[], char from[]);

int main() {
    int length;
    char line[MAX_LENGTH];
    char formattedLine[MAX_LENGTH];
    
    while((length = getLine(line, MAX_LENGTH)) > 0) {
        stripBlanks(formattedLine, line);
        
        printf("Line: %s\n", formattedLine);
    }
    
    return 0;
}

int getLine(char s[], int limit) {
    int c, i;
    
    // To remove uninitialised warning
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

// Params are arrays which are passed by reference
void stripBlanks(char to[], char from[]) {
    int i, j, k;
    i = j = k = 0;
    
    // Reset chars to null value. Note: Not very efficient
    while(k != MAX_LENGTH) {
        to[k] = '\0';
        ++k;
    }
    
    // Strips
    while (from[i] != '\0') {
        char c = from[i];
        
        if (c != ' ' && c != '\n' && c != '\t') {
            to[j] = c;
            ++j;
        }
        
        ++i;
    }
    
    
}
