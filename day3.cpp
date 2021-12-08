#include <stdio.h>

int next()
{
    int x = 0;
    int c = getchar();
    while(c == '1' || c == '0')
    {
        x <<= 1;
        x |= c - '0';
        c = getchar();
    }
    return c != EOF ? x : -1;
}

void one()
{
    const int N = 12;
    int common[N] = {};
    int size = 0;
    for(int x = next(); x != -1; x = next())
    {
        for(int i = 0; i < N; i++)
        {
            common[i] += ((x >> i) & 1) * 2 - 1;
        }
    }
    int out = 0;
    for(int i = 0; i < N; i++)
    {
        out |= (common[i] > 0) << i;
    }
    int mask = (1 << N) - 1;
    printf("Out: %i\n", out * (~out & mask));
}

template <typename bool(*F)(int)>
int evalfilter(int *list, int size)
{
    const int N = 12;
    for(int i = 0; i < N && size > 1; i++)
    {
        int common = 0;
        for(int j = 0; j < size; j++)
        {
            int x = (list[j] >> (N - 1 - i)) & 1;
            common += x * 2 - 1;
        }
        common = F(common);
        for(int j = 0; j < size; j++)
        {
            int x = (list[j] >> (N - 1 - i)) & 1;
            if(x != common)
            {
                for(int k = j + 1; k < size; k++)
                {
                    list[k - 1] = list[k];
                }
                size--;
                j--;
            }
        }
    }
    return list[0];
}

bool acomp(int x)
{
    return x >= 0;
}

bool bcomp(int x)
{
    return !acomp(x);
}

void two()
{
    int list[1 << 12];
    int size = 0;
    int list2[1 << 12];
    int size2 = 0;
    for(int x = next(); x != -1; x = next())
    {
        list[size++]   = x;
        list2[size2++] = x;
    }
    int a = evalfilter<acomp>(list, size);
    int b = evalfilter<bcomp>(list2, size2);
    printf("Out: %i\n", a * b);
}

int main()
{
    if(!freopen("day3.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day3.txt", "r", stdin)) return -1;
    two();
    return 0;
}