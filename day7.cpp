#include <stdio.h>

void one()
{
    int list[1 << 14];
    int *end = list;
    scanf("%i", end++);
    while(scanf(",%i", end) == 1) end++;
    int best = 1 << 30;
    for(int i = 0; i < 2000; i++)
    {
        int sum = 0;
        for(int *it = list; it != end; it++)
        {
            int x = i - *it;
            if(x < 0) x = -x;
            sum += x;
        }
        if(sum < best) best = sum;
    }
    printf("Out: %i\n", best);
}

void two()
{
    int list[1 << 14];
    int *end = list;
    scanf("%i", end++);
    while(scanf(",%i", end) == 1) end++;
    int best = 1 << 30;
    for(int i = 0; i < 2000; i++)
    {
        int sum = 0;
        for(int *it = list; it != end; it++)
        {
            int x = i - *it;
            if(x < 0) x = -x;
            sum += (x * (x + 1)) / 2;
        }
        if(sum < best) best = sum;
    }
    printf("Out: %i\n", best);
}

int main()
{
    if(!freopen("day7.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day7.txt", "r", stdin)) return -1;
    two();
    return 0;
}