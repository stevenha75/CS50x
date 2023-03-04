#include <stdio.h>
#include <cs50.h>
// required for the get_string method which acts like input() in python

int main(void)
{
    //calling the get_string method from <cs50.h>
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
    printf("test\n");
    // using a formatted string. %s places the string name in the print statement.
}
