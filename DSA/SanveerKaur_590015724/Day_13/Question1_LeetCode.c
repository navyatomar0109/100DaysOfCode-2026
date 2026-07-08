#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    char words[1000][20];
    int freq[1000];
    int wordCount = 0;
    int n = strlen(paragraph);
    char temp[20];
    int idx = 0;
    for (int i = 0; i <= n; i++) {
        if (isalpha(paragraph[i])) {
            temp[idx++] = tolower(paragraph[i]);
        }
        else {
            if (idx > 0) {
                temp[idx] = '\0';
                 // Check if banned
                int bannedFlag = 0;
                for (int j = 0; j < bannedSize; j++) {
                    if (strcmp(temp, banned[j]) == 0) {
                        bannedFlag = 1;
                        break;
                    }
                }

                if (!bannedFlag) {
                    int found = 0;
                    for (int j = 0; j < wordCount; j++) {
                        if (strcmp(words[j], temp) == 0) {
                            freq[j]++;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        strcpy(words[wordCount], temp);
                        freq[wordCount] = 1;
                        wordCount++;
                    }
                }
                idx = 0;
            }
        }
    }
    int maxFreq = 0;
    int ansIndex = 0;
    for (int i = 0; i < wordCount; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            ansIndex = i;
        }
    }
    char *result = (char *)malloc(strlen(words[ansIndex]) + 1);
    strcpy(result, words[ansIndex]);
    return result;
}