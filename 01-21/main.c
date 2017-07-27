#include <stdio.h>

#define MAX_INPUT_WIDTH 1000
#define TAB_WIDTH 4

void getInput(char body[]);
void entab(char body[]);

int main() {
    char output[MAX_INPUT_WIDTH];
    
    getInput(output);
    
    entab(output);
    
    printf("\nThis is the output: \n%s\n", output);
    
    return 0;
}

void getInput(char body[]) {
    int c, i;
    
    for (i = 0; i < MAX_INPUT_WIDTH - 1 && (c = getchar()) != EOF; ++i) {
        body[i] = c;
    }
    
    ++i;
    body[i] = '\0';
}

void entab(char body[]) {
    char output[MAX_INPUT_WIDTH];
    int c, j, lineStarted;
    j = lineStarted = 0;
    
    for(int i = 0; (c = body[i]) != '\0'; ++i) {
        
        if (c == ' ' && !lineStarted) {
            int tabStopIndex;
            
            for (tabStopIndex = 0; body[i + tabStopIndex] == ' ' && tabStopIndex < TAB_WIDTH - 1; tabStopIndex++);
            
            output[j] = '\t';
            i += tabStopIndex - 1; // Because the outer 'for' adds one anyway.
            
        } else {
            output[j] = c;
            lineStarted = c != '\n' && (!lineStarted && c != '\t'); // fix this.
        }
        
        ++j;

    }
    
    // Assign values back to original array.
    for (int i = 0; (body[i] = output[i]) != '\0'; ++i);
}
