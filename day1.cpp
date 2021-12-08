#include <stdio.h>

void one()
{
    int inc  = 0;
    int prev = 0;
    int next = 0;
    scanf("%i", &prev);
    while(scanf("%i", &next) == 1)
    {
        inc += next > prev;
        prev = next;
    }
    printf("Out: %i\n", inc);
}

void two()
{
    const int N = 3;
    int inc = 0;
    int window[N];
    for(int i = 0; i < 3; i++) scanf("%i", window + i);
    int next = 0;
    while(scanf("%i", &next) == 1)
    {
        int sum = 0;
        for(int i = 1; i < N; i++) sum += window[i];
        inc += sum + next > sum + window[0];
        for(int i = 1; i < N; i++) window[i - 1] = window[i];
        window[N - 1] = next;
    }
    printf("Out: %i\n", inc);
}

int main()
{
    if(!freopen("day1.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day1.txt", "r", stdin)) return -1;
    two();
    return 0;
}