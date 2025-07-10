// checking if two strings are anagrams
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areAnagrams(char str1[], char str2[]) {
    int count[256] = {0}; // Assuming ASCII characters

    // If lengths are not equal, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    // Count characters in str1
    for (int i = 0; str1[i]; i++) {
        count[(unsigned char)str1[i]]++;
    }

    // Decrease count for characters in str2
    for (int i = 0; str2[i]; i++) {
        count[(unsigned char)str2[i]]--;
        if (count[(unsigned char)str2[i]] < 0) {
            return 0; // More occurrences in str2 than in str1
        }
    }

    return 1; // They are anagrams
}

int main (){
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    if (areAnagrams(str1, str2)) {
        printf("%s and %s are anagrams.\n", str1, str2);
    } else {
        printf("%s and %s are not anagrams.\n", str1, str2);
    }

    return 0;

}