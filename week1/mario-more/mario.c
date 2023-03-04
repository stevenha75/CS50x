#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Does the height prompt until user inputs a number between 1-8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height >= 9);

// Outer loop loops for each row of mario
    for (int i = 0; i < height; i++)
    {
        // Formula for spaces in terms of row:
        for (int spaces = 0; spaces < height - 1 - i; spaces++)
        {
            printf(" ");
        }
        // Prints the first hashes w/ a for loop based off of the rows
        for (int hashes = 0; hashes < i + 1; hashes++)
        {
            printf("#");
        }
        printf("  ");
        // Prints the last hashes based off of the rows
        for (int hashes = 0; hashes < i + 1; hashes++)
        {
            printf("#");
        }
        // Escapes to a new line at the end of the outer loop
        printf("\n");
    }
}