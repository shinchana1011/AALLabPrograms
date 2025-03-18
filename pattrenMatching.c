#include <stdio.h>
#include <string.h>

void findPattern(char string[], char pattern[]) {
    int strLen = strlen(string);
    printf("length of string %d\n",strLen);
    int patLen = strlen(pattern);
    printf("length of pattren %d\n",patLen);
    int found = 0;
    for (int i = 0; i <= strLen - patLen; i++) {
        int j;
        for (j = 0; j <patLen; j++) {
            if (string[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patLen) {  
            printf("Pattern found at index: %d\n", i+1);                                                                                                    
            found = 1;
        }
    }
    
    if (!found) {
        printf("Pattern not found\n");
    }
}

int main() {
    char string[] = "Nobody noticed him";
    char pattern[] = "him";
    findPattern(string, pattern);                                                                                                                                                                                                                                                           
    return 0;
}
