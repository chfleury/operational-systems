#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int qnt = 0;

void handle_sigusr1 () {
    printf("SIGUSR1 eh para aproveitar mais um pouco\n");
}

void handle_sigalrm () {
    qnt ++;
    if (qnt == 3) {
        printf("Os incomodados que se mudem, tchau\n");
        exit(0);
    }

    printf("Ai que sono, quero dormir mais um pouco\n");
}

int main () {
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGALRM, handle_sigalrm);

    while (1) {
        pause();
    }
}