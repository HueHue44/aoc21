#include <stdio.h>

void one()
{
    const int N = 1 << 20;
    int *table = new int[N * 3];
    int *end = table;
    int out = 0;
    int a, b, c, d;
    while(scanf("%i,%i -> %i,%i", &a, &b, &c, &d) == 4)
    {
        if(a != c && b != d) continue;
        int dx = (a < c) ? 1 : (c < a) ? -1 : 0;
        int dy = (b < d) ? 1 : (d < b) ? -1 : 0;
        while(a != c + dx || b != d + dy)
        {
            int *it = table;
            while(it != end && (it[0] != a || it[1] != b)) it += 3;
            if(it == end)
            {
                *end++ = a;
                *end++ = b;
                *end++ = 0;
            }
            it[2]++;
            out += (it[2] == 2);
            a += dx;
            b += dy;
        }
    }
    delete[] table;
    printf("%i\n", out);
}

void two()
{
    const int N = 1 << 20;
    int *table = new int[N * 3];
    int *end = table;
    int out = 0;
    int a, b, c, d;
    while(scanf("%i,%i -> %i,%i", &a, &b, &c, &d) == 4)
    {
        int dx = (a < c) ? 1 : (c < a) ? -1 : 0;
        int dy = (b < d) ? 1 : (d < b) ? -1 : 0;
        while(a != c + dx || b != d + dy)
        {
            int *it = table;
            while(it != end && (it[0] != a || it[1] != b)) it += 3;
            if(it == end)
            {
                *end++ = a;
                *end++ = b;
                *end++ = 0;
            }
            it[2]++;
            out += (it[2] == 2);
            a += dx;
            b += dy;
        }
    }
    delete[] table;
    printf("%i\n", out);
}

int main()
{
    if(!freopen("day5.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day5.txt", "r", stdin)) return -1;
    two();
    return 0;
}