#include <stdio.h>

int main (void)
{
    int a;
    int b;
    
    printf("First number: ");
    scanf("%i", &a);

    printf("Second number: ");
    scanf("%i", &b);

    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    printf("Result: %i\n", a);
}
