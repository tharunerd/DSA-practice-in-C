#include <stdio.h>
#include <string.h>

void countwords(char str[])
{
    int i = 0, word = 0;

    // Traverse the string
    for (i = 0; str[i] != '\0'; i++)
    {
        // If the current character is a space and the previous character is not a space, increment the word count
        if (str[i] == ' ' && str[i - 1] != ' ' && i > 0)
        {
            word++;
        }
    }

    // If the string is not empty, increment the word count for the last word
    if (i > 0 && str[i - 1] != ' ')
    {
        word++;
    }

    printf("Number of words: %d\n", word);
}

void countletters(char str[])
{
    int i = 0, count = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            count++;
        }
        i++;
    }
    printf("Number of letters: %d\n", count);
}

void countdigits(char str[])
{
    int digits = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
    }
    printf("number of digits = %d\n", digits);
}

int main()
{
    char str[100]; // Declare a character array to hold the string
    printf("Enter a string: ");
    scanf("%[^\n]s", str); // Read a line of text from standard input
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0; // Find and replace newline with null terminator
    // Calculate the length of the string using strlen function
    countwords(str);   // Call the function to count words
    countletters(str); // Call the function to count letters
    countdigits(str);
    return 0; // Return success
}