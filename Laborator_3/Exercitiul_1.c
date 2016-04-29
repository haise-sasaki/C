#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nume[50];
    int varsta;
    double salariu;
}
Angajat;

// CREAREA UNUI FISIER CARE SA CONTINA INFORMATII DESPRE ANGAJATII UNEI FIRME

void CreareFisier(char *nf)
{
        Angajat aux;
        int i, n;
        FILE *f;
        f=fopen(nf, "wb");
        printf("Numarul de angajati ai firmei: ");
        scanf("%d", &n);
            for(i=0; i<n;i++)
            {
                 getchar ();
                 printf("(%d) ANGAJAT\n", i+1);
                 printf("Nume: ");
                 fgets(aux.nume, 50, stdin);
                 aux.nume[strlen(aux.nume-1)]='\n';
                 printf("Varsta: ");
                 scanf("%d", &aux.varsta);
                 printf("Salariu: ");
                 scanf("%lf", &aux.salariu);
                 fwrite(&aux, sizeof(Angajat), 1, f);
            }
        fclose(n);
}

//AFISAREA PE ECRAN A INFORMATIILOR DIN FISIERUL BINAR

void AfisareFisier(char *f, char *fb)
{
    Angajat aux;
    FILE *fin, *fout;
    if(strlen(f)==0) fout=stdout;
    else fout=fopen(f, "w");
    fin=fopen(fb,"rb");
    while(fread(&aux, sizeof(Angajat), 1, f)==1)
        fprintf(fout, "NUME: %s VARSTA: %d SALARIU: %lf\n", aux.nume, aux.varsta, aux.salariu);
    fclose(fin);
    fclose(fout);
}

//CALCULAREA NUMARULUI DE ANGAJATI DIN FIRMA

int NumarAngajati(char *fis)
{
    FILE *f=fopen(fis, "rb");
    int p, n;
    p=ftell(f);
    fseek(f, 0, SEEK_END);
    n=ftell(f),sizeof(Angajat);
    fseek(f, p, SEEK_END);
    return n;
}

//MODIFICAREA INFORMATIILOR DESPRE UN ANGAJAT AVAND NUMARUL DE ORDINE DAT

void ModificareAngajat (char *nf, int p)
{
    Angajat aux;
    FILE *f;
    int n;
    f=fopen(nf, "rb+");
    n=NumarAngajati(f);
    p--;
    if(p<0||p>n-1)
    {
        printf("Nu exista angajati cu numarul de ordine %d.", p+1);
        return;
    }
    fseek(f, p*sizeof(Angajat), SEEK_SET);
    fread(&aux, sizeof(Angajat), 1, nf);
    printf("(%d) ANGAJAT", p+1);
    fprintf("NUME: %s VARSTA: %d SALARIU: %lf\n", aux.nume, aux.varsta, aux.salariu);
    printf("NOILE INFORMATII\n");
    printf("Nume: ");
    fgets(aux.nume, 50, stdin);
    aux.nume[strlen(aux.nume)-1]='\0';
    printf("Varsta: ");
    scanf("%d", &aux.varsta);
    printf("Salariu: ");
    scanf("%lf", &aux.salariu);
    fseek(f, sizeof(Angajat), SEEK_CUR);
    fread(&aux, sizeof(Angajat),1, f);
    fclose(f);
}

//SORTAREA ALFABETICA A TUTUROR ANGAJATILOR

void SortareAlfabetica (char *nf)
{
    Angajat auxi, auxj;
    int i, j, n;
    FILE *f;
    f=fopen(nf, "rb+");
    for(i=0; i<n; i++)
    {
        fseek(f, i*sizeof(Angajat), SEEK_SET);
        fread(&auxi, sizeof(Angajat), 1, f);
        for(j=i+1; j<n; j++)
        {
            fseek(f, j*sizeof(Angajat), SEEK_SET);
            fread(&auxj, sizeof(Angajat), 1, f);
            if(strcmp(auxi.nume, auxj.nume)>0)
            {
                fseek(f, i*sizeof(Angajat), SEEK_SET);
                fwrite(&auxj, sizeof(Angajat), 1, f);
                fseek(f, j*sizeof(Angajat), SEEK_SET);
                fwrite(&auxi, sizeof(Angajat), 1, f);
                auxi=auxj;
            }
        }
    }
    fclose(f);
}

int main()
{
        FILE *nfis;
        FILE *bfis;
        int p;
        CreareFisier(&nfis);
        AfisareFisier(&nfis, &bfis);
        ModificareAngajat(&nfis, p);
        SortareAlfabetica(&nfis);
        printf("Numarul de angajati: %d", NumarAngajati("angajati.bin"));
        return 0;
}
