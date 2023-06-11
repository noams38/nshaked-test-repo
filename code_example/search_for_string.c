#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

int main() {
    char words[MAX_WORDS][WORD_LENGTH];
    int i, j, k, len, count, max_count = 0;
    
    // קליטת המילים מהמשתמש ואחסון במערך
    printf("Enter words (up to %d, each up to %d characters):\n", MAX_WORDS, WORD_LENGTH-1);
    i = 0;
    do {
        scanf("%s", words[i]);
        len = strlen(words[i]);
        if (len > WORD_LENGTH-1) {
            printf("Error: word too long (maximum length is %d)\n", WORD_LENGTH-1);
            return 1;
        }
        i++;
    } while (i < MAX_WORDS && strcmp(words[i-1], "end") != 0);
    
    // חיפוש לקבוצת המילים שרק אות אחת שונה ביניהם
    for (i = 0; i < MAX_WORDS && strcmp(words[i], "end") != 0; i++) {
        for (j = i+1; j < MAX_WORDS && strcmp(words[j], "end") != 0; j++) {
            count = 0;
            for (k = 0; k < WORD_LENGTH && words[i][k] != '\0' && words[j][k] != '\0'; k++) {
                if (words[i][k] != words[j][k]) {
                    count++;
                }
            }
            if (count == 1) {
                printf("%s %s\n", words[i], words[j]);
                max_count += count;
                
            }
        }
    }
    
    // הדפסת מספר המילים בקבוצה הכי גדולה שנמצאה
    printf("Maximum number of words with one different letter: %d\n", max_count);
    
    return 0;
}
