#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citire(char *c)
{
    printf("(c) Prezentati sirul respectiv.\n");
    fgets(c, 100, stdin);
    c[strlen(c)-1]='\0';
}

void verificare(char *c)
{
    char *p=c+strlen(c)-1;
    while (c<p)
        if(*c++ != *p--)
    {
        printf("Cuvantul nu este palindrom.");
        return;
    }
    printf("Cuvantul este palindrom.");
}

int main ()
{
    char c[100];
    citire(c);
    verificare(c);
    return 0;
}
