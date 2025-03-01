#include <stdio.h>


int main (void)
{
    int a; // first number
    int b; // second number
    int r; // rest
   
    // get input
    printf("First number: ");
    scanf("%i", &a);

    printf("Second number: ");
    scanf("%i", &b);


    // calculate result
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    } 


    // ouput
    printf("Result: %i\n", a);
}
