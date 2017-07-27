#include <stdio.h>

#define MAX_INPUT_WIDTH 1000
#define TAB_WIDTH 4

void getInput(char body[]);
void detab(char body[]);

int main() {
    char output[MAX_INPUT_WIDTH];

    getInput(output);
    detab(output); // SIGABRT err when tab used
    
    printf("This is the output: %s\n", output);
    
    return 0;
}

void getInput(char body[]) {
    int c, i;
    
    for (i = 0; i < MAX_INPUT_WIDTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        body[i] = c;
    }
    
    ++i;
    body[i] = '\0';
}

// This doesn't consider new input width.
// E.g. MAX_INPUT_WIDTH + (tabCount * TAB_WIDTH).
// Will learn about dynamic memory allocation later.
void detab(char body[]) {
    char output[MAX_INPUT_WIDTH];
    int j = 0;
    
    for(int i = 0; i < MAX_INPUT_WIDTH - 1; ++i) {
        char c = body[i];
        
        if (c == '\t') {
            for (int k = 0; k < TAB_WIDTH; ++k) {
                output[j] = ' ';
                ++j;
            }
        } else {
            output[j] = c;
            ++j;
        }
    }
    
    // Assign values back to original array.
    for (int i = 0; (body[i] = output[i]) != '\0'; ++i);
}
