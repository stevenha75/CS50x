// Included libraries
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Checking for preconditions (single/no argument)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
        // returning 1 in main signifies error (a non zero digit)
    }

    // Checking the key
    if (only_digits(argv[1]) != true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Storing key if it passes checks
    int k = atoi(argv[1]);

    // Prompt the user
    string input = get_string("plaintext: ");

    // Printing the cipher text:
    printf("ciphertext: ");
    for (int i = 0; i < strlen(input); i++)
    {
        printf("%c", rotate(input[i], k));
    }
    printf("\n");

    return 0;
    // C normally does this automatically
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        // Case 1: Lowercase
        if (islower(c))
        {
            return ((char)(((((int) c - 97) + n) % 26) + 97));
        }
        // Case 2: Uppercase
        else
        {
            return ((char)(((((int) c - 65) + n) % 26) + 65));
        }
    }
    else
    {
        return c;
    }
}
