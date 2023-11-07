#include <stdio.h>
#include <string.h>

int main(void)
{
    int w, h;
    float grid[3][3];
    scanf("%d %d", &w, &h);
    int kernel[w][h];
    long long answer[w - 2][h - 2];
    memset(answer, 0, sizeof(answer));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &grid[i][j]);
        }
    }

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            scanf("%d", &kernel[i][j]);
        }
    }

    for (int i = 0; i < w - 2; i++)
    {
        for (int j = 0; j < h - 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    answer[i][j] += (long long)kernel[i + k][j + l] * grid[k][l];
                    //printf("%d,%f\n", kernel[i + k][j + l], grid[k][l]);
                }
                //printf("answer[%d][%d]:%.3f\n", i, j, answer[i][j]);
            }
        }
    }
    for (int i = 0; i < w - 2; i++)
    {
        for (int j = 0; j < h - 2; j++)
        {
            printf("%4lld ", answer[i][j]);
        }
        printf("\n");
    }
}