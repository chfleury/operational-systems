#include <stdio.h>
#include <stdlib.h>

int main()
{
    int FRAME_COUNT, N, flag, pointer, max;
    int ans = 0;

    scanf("%d", &FRAME_COUNT);
    scanf("%d", &N);

    int frames[FRAME_COUNT];
    int pages[N];
    int temp[FRAME_COUNT];

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < FRAME_COUNT; ++i)
    {
        frames[i] = -1;
    }

    for (int i = 0; i < N; ++i)
    {
        flag = 0;

        for (int j = 0; j < FRAME_COUNT; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            for (int j = 0; j < FRAME_COUNT; ++j)
            {
                if (frames[j] == -1)
                {
                    ans++;
                    frames[j] = pages[i];
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
        {

            for (int j = 0; j < FRAME_COUNT; ++j)
            {
                temp[j] = -1;

                for (int k = i + 1; k < N; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (int j = 0; j < FRAME_COUNT; ++j)
            {
                if (temp[j] == -1)
                {
                    pointer = j;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                max = temp[0];
                pointer = 0;

                for (int j = 1; j < FRAME_COUNT; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pointer = j;
                    }
                }
            }
            frames[pointer] = pages[i];
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}