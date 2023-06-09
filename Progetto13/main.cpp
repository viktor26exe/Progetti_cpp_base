#include <iostream>
#include <time.h>
#include <cstdlib>

struct Nodo
{
    int info;
    Nodo *sx;
    double costoSx;
    Nodo *dx;
    double costoDx;
};

/**
 * Funzione che crea un albero binario bilanciato
*/
Nodo *creaAlberoBilanciato(int quantiNodi)
{
    if (quantiNodi == 0) // base della ricorsione
    {
        return nullptr;
    }
    else
    {
        // crea il nodo a questo livello
        Nodo *nuovo = new Nodo;
        nuovo->info = rand() % 100;

        int quantiSx = quantiNodi/2;
        int quantiDx = quantiNodi - quantiSx - 1;

        nuovo->sx = creaAlberoBilanciato(quantiSx); // passo ricorsivo
        nuovo->dx = creaAlberoBilanciato(quantiDx); // passo ricorsivo

        return nuovo;
    }
}

void stampaAlberoBinarioPreOrder(Nodo *p)
{
    if (p!=nullptr)
    {
        std::cout << p->info << std::endl;
        stampaAlberoBinarioPreOrder(p->sx);
        stampaAlberoBinarioPreOrder(p->dx);
    }
}

void stampaAlberoBinarioInOrder (Nodo *p)
{
    if (p!=nullptr)
    {
        stampaAlberoBinarioInOrder(p->sx);
        std::cout << p->info << std::endl;
        stampaAlberoBinarioInOrder(p->dx);
        
    }
}

void stampaAlberoBinarioPostOrder (Nodo *p)
{
    if (p!=nullptr)
    {
        stampaAlberoBinarioPostOrder(p->sx);   
        stampaAlberoBinarioPostOrder(p->dx);
         std::cout << p->info << std::endl;
    }
}

int calcolaFattoriale(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n * calcolaFattoriale(n-1);
    }
}


int main()
{
    Nodo *radice = creaAlberoBilanciato(0);
    stampaAlberoBinarioPreOrder(radice);


    
    return 0;
}