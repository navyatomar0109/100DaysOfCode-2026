#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Helper function to process backspaces in a string
void processString(const char* input, char* output) {
    int k = 0; // Acts as our stack pointer
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '#') {
            output[k++] = input[i];
        } else if (k > 0) {
            k--; // "Pop" the last character by moving the pointer back
        }
    }
    output[k] = '\0'; // Null-terminate the processed string
}

bool backspaceCompare(const char* s, const char* t) {
    // Allocate buffers large enough to hold the processed results
    char processedS[strlen(s) + 1];
    char processedT[strlen(t) + 1];
    
    processString(s, processedS);
    processString(t, processedT);
    
    // Compare the two clean strings
    return strcmp(processedS, processedT) == 0;
}

int main() {
    const char* s = "ab#c";
    const char* t = "ad#c";
    
    if (backspaceCompare(s, t)) {
        printf("Output: true\n");
    } else {
        printf("Output: false\n");
    }
    
    return 0;
}