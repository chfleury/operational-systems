
#define VERDADEIRO 1
#define FALSO 0
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

struct parametro_thread
{
    int numero;
    int resultado;
};

int e_quase_primo_maluco(int numero)
{
    double raiz = sqrt(numero);
    int qnt = 0;

    for (int i = 2; i < 11; i++)
    {
        if (numero % i == 0)
            return FALSO;
    }

    for (int i = 11; i < raiz; i += 2)
    {
        if (numero % i == 0)
            qnt++;

        if (qnt > 10)
            return VERDADEIRO;
    }

    return FALSO;
}

void *calcula_quase_primo(void *arg)
{
    struct parametro_thread *parametro = (struct parametro_thread *)(arg);

    if (parametro->numero < 508079)
    {
        parametro->resultado = 508079;
    }
    else
    {
        while (1)
        {
            parametro->numero = parametro->numero + 1;

            if (e_quase_primo_maluco(parametro->numero))
            {
                parametro->resultado = parametro->numero;
                break;
            }
        }
    }
}

int main(void)
{
    int _;
    int temp;
    pthread_t t1, t2;

    scanf("%d", &_);

    while (1)
    {
        if (scanf("%d", &temp) == EOF)
            break;

        struct parametro_thread PARAMETRO_A;
        PARAMETRO_A.numero = temp;
        pthread_create(&t1, NULL, calcula_quase_primo, (void *)&PARAMETRO_A);

        if (scanf("%d", &temp) == EOF)
        {
            pthread_join(t1, NULL);
            printf("%d\n", PARAMETRO_A.resultado);
            break;
        };

        struct parametro_thread PARAMETRO_B;
        PARAMETRO_B.numero = temp;

        pthread_create(&t2, NULL, calcula_quase_primo, (void *)&PARAMETRO_B);

        if (scanf("%d", &temp) == EOF)
        {
            pthread_join(t1, NULL);
            pthread_join(t2, NULL);
            printf("%d\n%d\n", PARAMETRO_A.resultado, PARAMETRO_B.resultado);
            break;
        };

        struct parametro_thread PARAMETRO_C;
        PARAMETRO_C.numero = temp;
        calcula_quase_primo((void *)&PARAMETRO_C);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        printf("%d\n%d\n%d\n", PARAMETRO_A.resultado, PARAMETRO_B.resultado, PARAMETRO_C.resultado);
    }

    return 0;
}