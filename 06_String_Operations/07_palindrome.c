
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void palindrome(char *str)
{
    int len = 0, i;
    char *start, *end;

    // Calculate the length of the string
    while (str[len] != '\0')
    {
        len++;
    }

    start = str;
    end = str + len - 1;

    // Check if the string is a palindrome
    for (i = 0; i < len / 2; i++)
    {
        if (*start != *end)
        {
            printf("The string is not a palindrome.\n");
            return;
        }
        start++;
        end--;
    }
    printf("The string is a palindrome.\n");
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    palindrome(str);
    return 0;
}