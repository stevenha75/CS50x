#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipher_char(char c, string key);

int main(int argc, string argv[])
{
    // Checking for preconditions
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // Alphabet check
        string key = argv[1];
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        // Unique check
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Prompt
    string input = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(input); i++)
    {
        printf("%c", cipher_char(input[i], argv[1]));
    }
    printf("\n");

    return 0;
}

char cipher_char(char c, string key)
{
    if (isalpha(c))
    {
        // Case 1: Lower
        if (islower(c))
        {
            return tolower(key[(int) c - 97]);
        }
        // Case 2: Upper
        else
        {
            return toupper(key[(int) c - 65]);
        }
    }
    // If it's not apart of the alphabet -> don't modify
    else
    {
        return c;
    }
}