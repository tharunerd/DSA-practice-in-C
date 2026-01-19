#include <stdio.h>
#include <string.h>

int main()
{
    // Finding duplicate characters in a string using hash table method

    char str[100];
    int i, len, count[256] = {0};
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    len = strlen(str);
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++)
    {
        count[(unsigned char)str[i]]++;
    }

    printf("Duplicate characters in the string are:\n");
    for (i = 0; i < 256; i++)
    {
        if (count[i] > 1)
        {
            printf("%c ", i);
        }
    }
    return 0;
}
