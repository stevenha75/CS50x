#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declaring variables
    int input;

    // Prompting user & setting preconditions
    do
    {
        input = get_int("Height: ");
    }
    while (input < 1 || input > 8);

    // Outer loop represents the height & moves the cursor
    for (int row = 1; row <= input; row++)
    {
        // Creates white space
        for (int spaces = 0; spaces < input - row; spaces++)
        {
            printf(" ");
        }

        // Loop that creates the hashes
        for (int hashes = 0; hashes < row; hashes++)
        {
            printf("#");
        }


        printf("\n");
    }
}