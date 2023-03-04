// Libraries:
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Prototypes:
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt for input
    string input = get_string("Text: ");

    // Storing necessary variables
    int words = count_words(input);
    int sentences = count_sentences(input);
    int letters = count_letters(input);

    // The average number of letters per 100 words in the text
    double L = (letters / (double) words) * 100;

    // Average number of sentences per 100 words in the text
    double S = (sentences / (double) words) * 100;

    // Calculate CL_index
    int CL_index = round((0.0588 * L) - (0.296 * S) - 15.8);

    // Print the grade level
    if (CL_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (CL_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", CL_index);
    }
}

int count_letters(string text)
{
    int counter = 0;
    // Iterates through the string
    for (int i = 0; i < strlen(text); i++)
    {
        // if the letter @ index i of the text array is an alpha -> increase counter
        if (isalpha(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text)
{
    int counter = 1;
    // Iterates through the string
    for (int i = 0; i < strlen(text); i++)
    {
        // If char is a space -> increase counter
        if (text[i] == ' ')
        {
            counter++;
        }
    }
    return counter;
}

int count_sentences(string text)
{
    int counter = 0;
    // iterates through the string
    for (int i = 0; i < strlen(text);  i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
    }
    return counter;
}