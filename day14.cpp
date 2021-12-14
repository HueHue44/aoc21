#include <stdio.h>

void one()
{
    char *list = new char[1 << 20];
    char *next = new char[1 << 20];
    char rule[1024];
    scanf("%s\n\n", list);
    char *end = rule;
    while(scanf("%c%c -> %c\n", end, end + 1, end + 2) == 3) end += 3;
    for(int step = 0; step < 10; step++)
    {
        char *it = next;
        for(char *c = list; *c; c++)
        {
            *it++ = *c;
            for(char *r = rule; r != end; r += 3)
            {
                if(c[0] == r[0] && c[1] == r[1])
                {
                    *it++ = r[2];
                    break;
                }
            }
        }
        *it++ = 0;
        int size = it - next;
        for(int i = 0; i < size; i++) list[i] = next[i];
    }
    const int N = 128;
    int table[128] = {};
    for(char *c = list; *c; c++) table[*c]++;
    int least = table['C'];
    int most  = table['C'];
    for(int i = 0; i < N; i++)
    {
        if(!table[i]) continue;
        if(table[i] < least) least = table[i];
        if(table[i] > most)  most  = table[i];
    }
    printf("Out: %i\n", most - least);
}

void two()
{
    const int N = 1 << 10;
    long long list[N] = {};
    int rule[N] = {};
    char c0 = getchar();
    char c1;
    for(c1 = getchar(); c1 != '\n'; c1 = getchar())
    {
        int index = ((c0 - 'A') << 5) | (c1 - 'A');
        list[index]++;
        c0 = c1;
    }
    char c2;
    while(scanf("\n%c%c -> %c", &c0, &c1, &c2) == 3)
    {
        int index = ((c0 - 'A') << 5) | (c1 - 'A');
        rule[index] = c2 - 'A';
    }
    for(int step = 0; step < 40; step++)
    {
        long long next[N];
        for(int i = 0; i < N; i++) next[i] = list[i];
        for(int i = 0; i < N; i++)
        {
            if(rule[i] && list[i])
            {
                long long n = list[i];
                next[i] -= n;
                int a = (i & 0b1111100000) | rule[i];
                next[a] += n;
                int b = (i & 0b0000011111) | (rule[i] << 5);
                next[b] += n;
            }
        }
        for(int i = 0; i < N; i++) list[i] = next[i];
    }
    long long least = 100000000000000;
    long long most  = 0;
    for(int i = 0; i < 32; i++)
    {
        long long sum = 0;
        for(int j = 0; j < 32; j++)
        {
            int a = (i << 5) | j;
            int b = (j << 5) | i;
            sum += list[a];
            sum += list[b];
        }
        sum = (sum + 1) / 2;
        if(!sum) continue;
        if(sum < least) least = sum;
        if(sum > most)  most  = sum;
    }
    printf("Out: %lli\n", most - least);
}

int main()
{
    if(!freopen("day14.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day14.txt", "r", stdin)) return -1;
    two();
    return 0;
}