#include <iostream>
#include "figura.cpp"

int main()
{
    Figura *vF[1000];
    int numeroFigure = 5000;
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        switch (rand() % 4)
        {
        case 0:
            vF[i] = new Cerchio(rand() % 10 + 1); // conformità di tipo -> permette alla classe madre di memorizzare oggetti di classe figlia
            break;

        case 1:
            vF[i] = new Rettangolo(rand() % 10 + 1, rand() % 10 + 1);
            break;

        case 2:
            vF[i] = new Quadrato(rand() % 10 + 1);
            break;

        case 3:
            vF[i] = new Triangolo(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
            break;
        }
    }

    numeroFigure= 100;
    double tracciaTotale = 0;
    for (int i = 0; i<numeroFigure; i++)
    {
        tracciaTotale += vF[i] -> perimetro();
    }

    std::cout << tracciaTotale << std::endl;



    return 0;
}