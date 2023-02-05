#include <stdlib.h>
#include <stdio.h>

int main () {
    int FRAME_COUNT;
    int N;
    int ans = 0;

    scanf("%d", &FRAME_COUNT);
    scanf("%d", &N);

    int frames[FRAME_COUNT]; 
    // for(int j = 0; j < FRAME_COUNT; j++) {
    //     frames[j] == -1;
    // }

    int temp;
    int pointer = 0;

    for(int i = 0; i < N; i++){
        scanf("%d", &temp);

        if (temp == 0) temp = -2;
        if (pointer == FRAME_COUNT) pointer = 0;
        
        int pageFault = 1;
        for(int j = 0; j < FRAME_COUNT; j++) {
            if (frames[j] == temp) {
                pageFault = 0;
            }
        }
    
        if (pageFault) {
            // printf("\n%d temp \n", temp);

            ans++;
            frames[pointer] = temp;
            pointer++;
        } 

    }

    printf("%d\n", ans);

    return 0;
}


// 7
// 0
// 1
// 2
// 0
// 3
// 0
// 4
// 2
// 3
// 0
// 3
// 2
// 1
// 2
// 0
// 1
// 7
// 0
// 1
// 2 0 1
// 7, 0, 1, 2, 3