#include <stdio.h>
#include <string.h>

int main ()
{
    char c[100], min[100], max[100];
    int n, i;
    printf("(n) Numarul de cuvinte: ");
    scanf("%d", &n);
    fflush(stdin);
    printf("(1) Tastati primul cuvant: ");
    scanf("%s", &c);
    int lx=strlen(c);
    int ln=strlen(c);
    strcpy(min, c);
    strcpy(max, c);
    for (i=0; i<n-1; i++)
    {
        printf("(%d) Cuvant: ", i+2);
        fflush(stdin);
        scanf("%s", c);
        if(strlen(c)>strlen(max))
        {
            strcpy(max, c);
            lx=strlen(c);
        }
        else
            if(strlen(c)<strlen(min))
            {
                strcpy(min, c);
                ln=strlen(c);
            }
    }
    printf("Cuvantul de lungime maxima: %s\n", max);
    printf("Cuvantul de lungime minima: %s\n", min);
    return 0;
}
