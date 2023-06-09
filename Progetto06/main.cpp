/*
Simulato la situazione in cui caricando dati in un array si esaurisce 
lo spazio. Con un array statico dovrebbe intervenire il programmatore
con un aggiornamento (ridicolo); con un array dinamico aumenteremo lo 
spazio a run time.
*/

#include <iostream>

int main()
{
    int* pInt = new int[100];

    // simulazione caricamento ed esaurimento
    for(int indice = 0; indice < 100; indice++)
    {
        pInt[indice] = indice;
    }

    // allocazione di un array più grande
    int* temp = new int [200];

    // copiamo i dati dal vecchio array in questo
    for (int indice = 0; indice < 100; indice++)
    {
        temp[indice] = pInt[indice];
    }

    // restituiamo la RAM usata dal primo array
    delete[] pInt; pInt = nullptr;

    pInt = temp; // temp non va dfistrutto se no si perdono i dati 


    return 0;
}