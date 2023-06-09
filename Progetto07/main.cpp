
#include <iostream>

/*
- Ricevere un array di interi
- Restituisce un array di interi (creato dinamicamente) contenente solamente gli elementi
  del primo nell'intervallo cin estremi [minAccettabile, maxAccetabile]
*/
int *filtra(int v[], int numeroElementi, int minAccettabile, int maxAccetabile, int &filtrati)
{
    filtrati = 0;

    // primo giro per contare quanti valori soddisfano il criterio
    for (int i = 0; i < numeroElementi; i++)
    {
        if (v[i] >= minAccettabile && v[i] <= maxAccetabile)
        {
            filtrati++;
        }
    }

    // allochiamo un array per conta interi
    int *p = new int[filtrati];

    // copiamo gli elementi
    for (int i = 0, copiati = 0; i < numeroElementi; i++)
    {
        if (v[i] >= minAccettabile && v[i] <= maxAccetabile)
        {
            p[copiati++] = v[i];
        }
    }

    return p;
}

int main()
{
    int vettore[]{6, -78, -59, 11, 73, -26, 77, -92, -12, 7, -31, 77, 84, 15};
    int quantiFiltrati = 0;
    int *filtrati = filtra(vettore, 14, -10, 80, quantiFiltrati);
    
    for (int i = 0; i < quantiFiltrati; i++)
    {
        std::cout << filtrati[i] << " ";
    }

    delete[] filtrati;

    return 0;
}
