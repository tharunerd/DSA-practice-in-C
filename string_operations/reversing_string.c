#include <stdio.h>
#include <string.h>

// void reverse(char str[])
// {
//     int start = 0, end = strlen(str) - 1;
//     char temp;
//     while (start < end)
//     {
//         temp = str[start];
//         str[start] = str[end];
//         str[end] = temp;
//         start++;
//         end--;
//     }
//     printf("Reversed string: %s\n", str);
// }
void reverse(char str[])
{
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        // Swap characters at positions i and j
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        printf("Reversed string: %s\n", str);
    }
}
int main()
{
    char str[100]; // Declare a character array to hold the string
    printf("Enter a string: ");
    scanf("%[^\n]s", str); // Read a line of text from standard input
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0; // Find and replace newline with null terminator
    reverse(str);                // Call the function to reverse the string
    return 0;
}
