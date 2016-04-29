//Inversa unei matrice folosind metoda Jordan-Gauss double

#include <stdio.h>

void citire(double **a, int n)
{
    int i, j;
    for (i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%lf", &a[i][j]);
}

void gaussjordan(double **a, int n)
{
// CREAREA MATRICEI
    int i, j, k, m= 2*n;
    double **b=(double **) malloc(n * sizeof(double*));
    for (i=0; i<n; i++)
        b[i]=(double *) malloc(m * sizeof(double));
    for (i=0; i<n; i++)
    {
        for (k=0; k<n; k++)
            b[i][k]=a[i][k];
        for (j=n; j<m; j++)
            if (i+n==j)
                b[i][j]=1;
            else
                b[i][j]=0;
    }

    for (i=0; i<n; i++)
        calcul(b, n, i);
    afisare(b, n);
}

void calcul(double **b, int n, int x)
{
    int i, j;

// CREAREA UNEI COPII
    double **a=(double **) malloc(n * sizeof(double*));
    for (i=0; i<n; i++)
        a[i]=(double *) malloc(2 * n * sizeof(double));
    for (i=0; i<n; i++)
        for (j=0; j<2*n; j++)
        a[i][j]=b[i][j];

// CALCULUI MATRICEI
    for (i=0; i<n; i++)
        for (j=0; j<2*n; j++)
            if (i==x);
            else
                if (j==x)
                    b[i][j]=0;
                else
                    b[i][j]=(a[i][j]*a[x][x])-(a[x][j]*a[i][x]);

// AFLAREA INVERSEI
    for (i=0; i<n; i++)
        if (b[i][i]!=1)
            for (j=0; j<2*n; j++)
                b[i][j] = b[i][j]/b[i][i];
}

void afisare(double **a, int n)
{   printf("\n\n");
    int i, j;
    for (i=0; i<n; i++)
    {
        for(j=n; j<2*n; j++)
            printf("%lf ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, i;
    printf("(n) Numarul de linii si coloane: ");
    scanf("%d", &n);
    double **a=(double **) malloc (n * sizeof(double*));
    for (i=0; i<n; i++)
        a[i]=(double *) malloc(n * sizeof(double));
    citire(a, n);
    gaussjordan(a, n);
    return 0;
}
