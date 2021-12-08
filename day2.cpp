#include <stdio.h>

void one()
{
    int x = 0;
    int y = 0;
    while(true)
    {
        int d = 0;
        if(scanf("forward %i\n", &d) == 1)   x += d;
        else if(scanf("down %i\n", &d) == 1) y += d;
        else if(scanf("up %i\n", &d) == 1)   y -= d;
        else break;
    }
    printf("Out: %i\n", x * y);
}

void two()
{
    int x = 0;
    int y = 0;
    int a = 0;
    while(true)
    {
        int d = 0;
        if(scanf("forward %i\n", &d) == 1)
        {
            x += d;
            y += a * d;
        }
        else if(scanf("down %i\n", &d) == 1) a += d;
        else if(scanf("up %i\n", &d) == 1)   a -= d;
        else break;
    }
    printf("Out: %i\n", x * y);
}

int main()
{
    if(!freopen("day2.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day2.txt", "r", stdin)) return -1;
    two();
    return 0;
}