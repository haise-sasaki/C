#include <stdio.h>
#include <string.h>

int main()
{
    char c[100], p[100];
    int n, m, i;
    printf("(n) Numarul de cuvinte: ");
    scanf("%d", &n);
    printf("(m) Numarul de litere: ");
    scanf("%d", &m);
    if (p==NULL) exit (1);
    for (i=0; i<n; i++)
    {
        printf("(%d) Cuvant: ", i+1);
        fflush(stdin);
        fgets(c, 100, stdin);
        c[strlen(c)-1]='\0';
        strncat(p, c+strlen(c)-m, m);
    }
    printf("Sirul respectiv: %s",p+7);
    return 0;
}
