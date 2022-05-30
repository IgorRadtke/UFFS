 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Veiculo
{
    int Ano;
    char Modelo[30]; 
} Carros;

void radixsort(Carros *vet, int n) {
    int i, exp = 1, m = 0, bucket[n];
    Carros *temp = (Carros *)malloc(n * sizeof(Carros));

    for(i = 0; i < n; i++) {
        if(vet[i].Ano > m) {
            m = vet[i].Ano;
        }
    }

    while((m/exp) > 0) {
        for (i = 0; i < n; i++) {
            bucket[i] = 0;
        }
        for(i = 0; i < n; i++) {
            bucket[(vet[i].Ano / exp) % 10]++;
        }
        for(i = 1; i < n; i++) {
            bucket[i] += bucket[i-1];
        }
        for(i = (n - 1); i >= 0; i--) {
            temp[--bucket[(vet[i].Ano / exp) % 10]] = vet[i];
        }
        for(i = 0; i < n; i++) {
            vet[i] = temp[i];
        }
        exp *= 10;
    }
}

int main()
{
    Carros carro[] = {
        {1980, "Monza"},{2010, "Gol"},{2005, "Uno"}, {2002, "Jetta"}, {2000, "Celta"},
        {1994, "Corsa"}, {2010, "Fusca"}, {2014, "Clio"}, {2016, "Tucson"}, 
        {2005, "Civic"}, {2018, "Ka"}, {2019, "Porsche Macan"}, {2020, "Ferrari 812"}, {2008, "Sandero"}, {2017, "Creta"}
    };

    int i;

    radixsort(carro, 15);


    // printf("Ano: %d - Modelo: %s\n", carro[0].Ano, carro[0].Modelo);

    for (i = 0; i < 15; i++)
    {
        printf("Ano: %d - Modelo: %s\n", carro[i].Ano, carro[i].Modelo);
    }

    return 0;
}