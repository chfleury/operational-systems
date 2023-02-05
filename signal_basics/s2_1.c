#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int N;

int cmp(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

void * srt (void *arg) {
	int *arr = (int *)(arg);

    qsort(arg, N, sizeof(int), cmp);
}

int main() {

    scanf("%d", &N);

    int v1[N];
    int v2[N];
    int i;
    
    for(i = 0; i < N; i++){ 
        scanf("%d", &v1[i]);
    }

    for(i = 0; i < N; i++){ 
        scanf("%d", &v2[i]);
    }

	pthread_t t1, t2;
    pthread_create(&t1, NULL, srt, (void *)&v1);
	pthread_create(&t2, NULL, srt, (void *)&v2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    for(i = 0; i < N; i++)  {
        if (v1[i] != v2[i]) { 
            printf("Diferentes\n");
            return 0;
        }
    }
    
    printf("Mesmos elementos\n");

    return 0;
}
