#include <stdio.h>

void one()
{
    const int N = 9;
    int list[N] = {};
    int timer;
    scanf("%i", &timer);
    list[timer]++;
    while(scanf(",%i", &timer) == 1) list[timer]++;
    for(int day = 0; day < 80; day++)
    {
        int grow = list[0];
        for(int i = 1; i < N; i++) list[i - 1] = list[i];
        list[N - 1] = grow;
        list[6] += grow;
    }
    int out = 0;
    for(int i = 0; i < N; i++) out += list[i];
    printf("Out: %i\n", out);
}

void two()
{
    const int N = 9;
    long long list[N] = {};
    long long timer;
    scanf("%lli", &timer);
    list[timer]++;
    while(scanf(",%lli", &timer) == 1) list[timer]++;
    for(int day = 0; day < 256; day++)
    {
        long long grow = list[0];
        for(int i = 1; i < N; i++) list[i - 1] = list[i];
        list[N - 1] = grow;
        list[6] += grow;
    }
    long long out = 0;
    for(int i = 0; i < N; i++) out += list[i];
    printf("Out: %lli\n", out);
}

int main()
{
    if(!freopen("day6.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day6.txt", "r", stdin)) return -1;
    two();
    return 0;
}