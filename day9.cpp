#include <stdio.h>

void one()
{
    int matrix[1 << 14];
    int n = 0;
    int m = 0;
    for(int c = getchar(); c != EOF; c = getchar())
    {
        for(; c >= '0' && c <= '9'; c = getchar())
        {
            matrix[n++] = c - '0';
        }
        m++;
    }
    n = n / m;
    int out = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int index = i * n + j;
            if(i > 0 && matrix[index] >= matrix[index - n]) continue;
            if(i < m - 1 && matrix[index] >= matrix[index + n]) continue;
            if(j > 0 && matrix[index] >= matrix[index - 1]) continue;
            if(j < n - 1 && matrix[index] >= matrix[index + 1]) continue;
            out += matrix[index] + 1;
        }
    }
    printf("Out: %i\n", out);
}

void two()
{
}

int main()
{
    if(!freopen("day9.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day9.txt", "r", stdin)) return -1;
    two();
    return 0;
}