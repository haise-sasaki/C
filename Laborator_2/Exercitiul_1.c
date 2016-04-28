#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citire (char *a, char *b)
{
    printf("(a) Scrieti primul cuvant: ");
    scanf("%s", a);
    fflush(stdin);
    printf("(b) Scrieti al doilea cuvant: ");
    scanf("%s", b);
}

void verificare (char *a, char *b)
{
    int i;
        if(strcmp(a, b)==0)
        {
            printf("Cuvintele sunt anagrame.");
            return;
        }
            for (i=0; i<strlen(a); i++)
                if(strchr((b), a[i])==NULL)
                {
                    printf("Cuvintele nu sunt anagrame#@#.");
                    return;
                }
                else
                {
                    //memcpy(strchr((b), a[i]), strchr((b), a[i])+1, sizeof(strchr((b), a[i]))); ERORI CIUDATE LA UNELE CUVINTE
                    strcpy(strchr((b), a[i]), strchr((b), a[i])+1); // NU E SAFE, DAR FUNCTIONEAZA (RISC DE UNDEFINED BEHAVIOR)
                }
            if (strlen(b)==0)
                printf("Cuvintele sunt anagrame.");
            else
                printf("Cuvintele nu sunt anagrame.");
}

int main ()
{
    char a[100], b[100];
    citire(a, b);
    verificare(a, b);
    return 0;
}
