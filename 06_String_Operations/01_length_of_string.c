//finding the length of a string
#include <stdio.h>


#include <string.h>


int main() {
    char str[100]; // Declare a character array to hold the string

    // Prompt user for input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of text from standard input

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0; // Find and replace newline with null terminator
    // Calculate the length of the string using strlen function
    int length = strlen(str);
    printf("Length of the string: %d\n", length);

    return 0; // Return success
}
// This program calculates the length of a string entered by the user.