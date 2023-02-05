#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main()
{
    char path[256];
    char arg[256];

    struct timeval start_time, end_time;
    struct timeval start_time_absolute, end_time_absolute;

    int flag = 1;
    int child_status = 0;

    while (scanf("%s%s", path, arg) != EOF)
    {
        if (flag)
        {
            gettimeofday(&start_time_absolute, NULL);
            flag = 0;
        }

        gettimeofday(&start_time, NULL);

        fflush(stdout);
        int pid = fork();
        if (pid == 0)
        {
            // parte de código que é executada no processo filho
            int child_result = execl(path, path, arg, NULL);
            if (child_result == -1)
            {

                printf("> Erro: %s\n", strerror(errno));
                fflush(stdout);
                fclose(stdin);
                // retorna o erro do processo filho
                return errno;
            }

            // retorna o resultado da execução do processo filho
            return child_result;
        }
        else
        {
            // parte de código que é executada no processo principal
            int wait_pid = waitpid(pid, &child_status, WUNTRACED);

            gettimeofday(&end_time, NULL);

            double time = (double)(end_time.tv_sec - start_time.tv_sec) + ((double)(end_time.tv_usec - start_time.tv_usec) / 1000000);

            printf("> Demorou %.1lf segundos, retornou %d\n", time, WEXITSTATUS(child_status));
            fflush(stdout);
        }
    }

    gettimeofday(&end_time_absolute, NULL);

    double total_time = (double)(end_time_absolute.tv_sec - start_time_absolute.tv_sec) + ((double)(end_time_absolute.tv_usec - start_time_absolute.tv_usec) / 1000000);

    printf(">> O tempo total foi de %.1lf segundos\n", total_time);
    fflush(stdout);

    return 0;
}
