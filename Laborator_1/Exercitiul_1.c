#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citire(char s[100])
{
    printf("(s) Prezentati sirul respectiv.\n");
    fgets(s, 100, stdin);
    s[strlen(s)-1]='\0';
}

void stergere(char s[100])
{
    //DECLARARI, COPIERI & CITIRI
    char ss[100], d[5] ,c;
    int i;
    strcpy(ss, s);
    printf("(c) Caracterul ce trebuie sters: ");
    scanf("%c", &c);
    fflush(stdin);

    //VERIFICARE 'CASE SENSITIVE'
    printf("(d) Doriti si stergeti caracterul indiferent de 'case sensitive'? (DA/NU)\n(Raspuns) ");
    fgets(d, 5, stdin);
    d[strlen(d)-1]='\0';
    if (strcmp(strlwr(d), "da")==0)
    {
        c=tolower(c);
    }

    //STERGERE CARACTER
    for (i=0; i<strlen(s); i++)
            if (strcmp(strlwr(d), "da")==0)
            {
                if (tolower(ss[i])==c)
                {
                    memcpy(ss+i, ss+i+1, sizeof(ss));
                    i--;
                }
            }
            else
                if (ss[i]==c)
                {
                    memcpy(ss+i, ss+i+1, sizeof(ss));
                    i--;
                }
    ss[strlen(ss)]='\0';

    //AFISARE SIR MODIFICAT
    if (strlen(ss)==0)
        printf("Sirul este vid.");
        else
        printf("Sirul modificat:\n%s", ss);
}

int main ()
{
    char s[100];
    citire(s);
    stergere(s);
    return 0;
}
