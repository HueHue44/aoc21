#include <stdio.h>

bool winner(int *board, int n)
{
    for(int i = 0; i < n; i++)
    {
        int sumx = 0;
        int sumy = 0;
        for(int j = 0; j < n; j++)
        {
            sumx += board[i * n + j];
            sumy += board[j * n + i];
        }
        if(sumx == -n || sumy == -n) return true;
    }
    return false;
}

void one()
{
    const int N = 5;
    int numbers[1024];
    int nsize = 0;
    int boards[N * N * 1024];
    int bsize = 0;
    scanf("%i", numbers + nsize);
    nsize++;
    while(scanf(",%i", numbers + nsize) == 1) nsize++;
    while(scanf("%i", boards + bsize) == 1) bsize++;
    int i = 0;
    int windex = -1;
    for(; i < nsize; i++)
    {
        for(int j = 0; j < bsize; j++)
        {
            if(boards[j] == numbers[i]) boards[j] = -1;
        }
        for(int j = 0; j < bsize; j += N * N)
        {
            if(winner(boards + j, N)) windex = j;
        }
        if(windex >= 0) break;
    }
    int sum = 0;
    for(int i = 0; i < N * N; i++)
    {
        if(boards[windex + i] >= 0) sum += boards[windex + i];
    }
    printf("Out: %i\n", sum * numbers[i]);
}

void two()
{
    const int N = 5;
    int numbers[1024];
    int nsize = 0;
    int boards[N * N * 1024];
    int bsize = 0;
    scanf("%i", numbers + nsize);
    nsize++;
    while(scanf(",%i", numbers + nsize) == 1) nsize++;
    while(scanf("%i", boards + bsize) == 1) bsize++;
    int i = 0;
    for(; i < nsize; i++)
    {
        for(int j = 0; j < bsize; j++)
        {
            if(boards[j] == numbers[i]) boards[j] = -1;
        }
        for(int j = 0; j < bsize; j += N * N)
        {
            if(winner(boards + j, N))
            {
                for(int k = j + N * N; k < bsize; k++)
                {
                    boards[k - N * N] = boards[k];
                }
                bsize -= N * N;
                j -= N * N;
            }
        }
        if(bsize == 0) break;
    }
    int sum = 0;
    for(int i = 0; i < N * N; i++)
    {
        if(boards[i] >= 0) sum += boards[i];
    }
    printf("Out: %i\n", sum * numbers[i]);
}

int main()
{
    if(!freopen("day4.txt", "r", stdin)) return -1;
    one();
    if(!freopen("day4.txt", "r", stdin)) return -1;
    two();
    return 0;
}