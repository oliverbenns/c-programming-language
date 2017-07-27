#include <stdio.h>

#define MAX_INPUT_WIDTH 1000
#define TAB_WIDTH 4

void getInput(char body[]);
void detab(char body[]);

int main() {
    char output[MAX_INPUT_WIDTH];

    getInput(output);
    
    detab(output);
    
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

// This doesn't consider new input width.
// E.g. MAX_INPUT_WIDTH + (tabCount * TAB_WIDTH).
// Will learn about dynamic memory allocation later.
void detab(char body[]) {
    char output[MAX_INPUT_WIDTH];
    int c, j, lineStarted;
    j = lineStarted = 0;
    
    for(int i = 0; (c = body[i]) != '\0'; ++i) {

        if (c == '\t' && !lineStarted) {
            for (int k = 0; k < TAB_WIDTH; ++k) {
                output[j] = ' ';
                ++j;
            }
        } else {
            output[j] = c;
            ++j;
            lineStarted = c != '\n';
        }
        
    }
    
    // Assign values back to original array.
    for (int i = 0; (body[i] = output[i]) != '\0'; ++i);
}
