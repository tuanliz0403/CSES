#include <stdio.h>

int main()
{
    double a, b;
    scanf("%lf%lf", &a, &b);
    if (a == 0 && b == 0)
    {
        printf("INFINITE SOLUTIONS");
    }
    else if (a == 0 && b != 0)
    {
        printf("NO SOLUTION");
    }
    else
    {
        printf("x = %.2lf", -b / a);
    }
    return 0;
}