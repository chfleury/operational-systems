#include <stdio.h>
#include <stdlib.h>


int main()
{
    int FRAME_COUNT, N;
    int ans = 0;

    scanf("%d", &FRAME_COUNT);
    scanf("%d", &N);

    int frames[FRAME_COUNT];
    int pages[N];
    int counter_array[FRAME_COUNT];

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < FRAME_COUNT; ++i)
    {
        frames[i] = -1;
    }

    int counter = 0;

    for (int i = 0; i < N; ++i)
    {
        int flag = 0;

        for (int j = 0; j < FRAME_COUNT; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                counter_array[j] = counter;
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
                    counter++;
                    ans++;
                    frames[j] = pages[i];
                    counter_array[j] = counter;
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
        {
            int pointer = 0;
            int minimum = counter_array[0];

            for (int i = 1; i < FRAME_COUNT; ++i)
            {
                if (counter_array[i] < minimum)
                {
                    minimum = counter_array[i];
                    pointer = i;
                }
            }

            counter++;
            ans++;

            frames[pointer] = pages[i];
            counter_array[pointer] = counter;
        }
    }

    printf("%d\n", ans);

    return 0;
}