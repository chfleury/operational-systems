#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    for (int i = 1; i < argc; i++)
    {
        for (int j = i + 1; j < argc; j++)
        {
            FILE *ARQUIVO_A = fopen(argv[i], "rb");
            FILE *ARQUIVO_B = fopen(argv[j], "rb");

            fseek(ARQUIVO_A, 0, SEEK_END);
            fseek(ARQUIVO_B, 0, SEEK_END);

            if (ftell(ARQUIVO_A) != ftell(ARQUIVO_B))
            {
                printf("%s %s diferentes\n", argv[i], argv[j]);

                fclose(ARQUIVO_A);
                fclose(ARQUIVO_B);

                continue;
            }

            rewind(ARQUIVO_A);
            rewind(ARQUIVO_B);

            int temp, diferentes;
            diferentes = 0;

            while ((temp = fgetc(ARQUIVO_A)) != EOF)
            {
                if (temp != fgetc(ARQUIVO_B))
                {
                    diferentes = 1;
                    break;
                }
            }

            if (diferentes)
            {

                printf("%s %s diferentes\n", argv[i], argv[j]);
            }
            else
            {

                printf("%s %s iguais\n", argv[i], argv[j]);
            }

            fclose(ARQUIVO_A);
            fclose(ARQUIVO_B);
        }
    }

    return 0;
}