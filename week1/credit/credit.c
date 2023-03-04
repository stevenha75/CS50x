#include <cs50.h>
#include <stdio.h>

// Creating prototypes for the helper methods
bool checkSum(long cardNum);
string cardType(long cardNum);
long length(long cardNum);
long firstTwo(long cardNum);

int main(void)
{
    long input = get_long("Number: ");

    // Use check sum to make sure numbers follow Luhn's Algorithm
    if (checkSum(input))
    {
        // Calls the cardType method to print the cardType
        printf("%s", cardType(input));
    }
    // If it doesn't follow, print INVALID
    else
    {
        printf("INVALID\n");
    }
}

// Returns true if card pass luhn's algo; else false
bool checkSum(long cardNum)
{
    // Represents the sum of every other digit starting with the last
    int sum1 = 0;
    // Represents the sum of the digits of every other digit*2 starting with the second to last
    int sum2 = 0;
    int timesTwoStore;
    int d1;
    int d2;

    do
    {
        // Adds last digit to sum1
        sum1 += (cardNum % 10);
        cardNum /= 10;

        // Double second last digit and add digits to sum2
        timesTwoStore = (cardNum % 10) * 2;
        d1 = (timesTwoStore % 10);
        d2 = (timesTwoStore / 10);
        sum2 = sum2 + (d1 + d2);
        cardNum /= 10;
    }
    while (cardNum > 0);

    // Checks if the last digit is 0 and returns
    if (((sum1 + sum2) % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Returns a string of the cardType
string cardType(long cardNum)
{
    // AMEX Starting Num Check
    if ((firstTwo(cardNum) == 34) || (firstTwo(cardNum) == 37))
    {
        // Checks if the length matches
        if (length(cardNum) == 15)
        {
            return "AMEX\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    // MasterCard Starting Num Check
    else if ((firstTwo(cardNum) == 51) || (firstTwo(cardNum) == 52) || (firstTwo(cardNum) == 53) ||
             (firstTwo(cardNum) == 54) || (firstTwo(cardNum) == 55))
    {
        // Checks if the length matches
        if (length(cardNum) == 16)
        {
            return "MASTERCARD\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    // Visa Starting Num Check
    else if ((firstTwo(cardNum) / 10) == 4)
    {
        // Checks if the length matches
        if ((length(cardNum) == 13) || (length(cardNum) == 16))
        {
            return "VISA\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    // If it does not have the correct starting num -> invalid
    else
    {
        return "INVALID\n";
    }
}

// Calculates the length of a card number
long length(long cardNum)
{
    int lengthCounter = 0 ;
    do
    {
        cardNum /= 10;
        lengthCounter++;
    }
    while (cardNum >= 1);
    return lengthCounter;
}

// Returns the last two digits
long firstTwo(long cardNum)
{
    do
    {
        cardNum /= 10;
    }
    while (cardNum >= 100);
    return cardNum;
}


