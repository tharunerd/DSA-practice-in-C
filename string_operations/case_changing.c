#include <stdio.h>
#include <string.h>

// This program converts a string to lowercase and uppercase using ASCII values.

void invert_case(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32; // Convert uppercase to lowercase
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32; // Convert lowercase to uppercase
        }
    }
    printf("Inverted case: %s\n", str);
}

void lowercase(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    printf("Lowercase: %s\n", str);
}

void uppercase(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    printf("Uppercase: %s\n", str);
}

// Function to remove the newline character from a string
void remove_newline(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0'; // Replace newline with null terminator
            break;
        }
    }
}

int main()
{
    char str[100]; // Declare a character array to hold the string

    // Prompt user for input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of text from standard input
    remove_newline(str);            // Remove newline character if present

    // Create copies of the original string for each function
    char str_lower[100], str_upper[100], str_invert[100];
    strcpy(str_lower, str);
    strcpy(str_upper, str);
    strcpy(str_invert, str);

    lowercase(str_lower);    // Convert to lowercase
    printf("\n");            // Print a newline for better readability
    uppercase(str_upper);    // Convert to uppercase
    printf("\n");            // Print a newline for better readability
    invert_case(str_invert); // Invert case of the string
    return 0;                // Return success
}
