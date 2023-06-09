#include <iostream>

const int LETTURE = 240;

int main()
{
    int numeroCentraline = 0;
    double media = 0.0;
    std::cout << "Quante sono le centraline? ";
    std::cin >> numeroCentraline;

    int *pAreaInt = new int[numeroCentraline * LETTURE]; // sintassi a vettore

    for (int c = 0; c < numeroCentraline; c++)
    {
        // simulo lettura dati da questa centralina
        for (int lettura = 0; lettura < LETTURE; lettura++)
        {
            pAreaInt[c * LETTURE + lettura] = rand() % 200 + 1;
            media +=  pAreaInt[c * LETTURE + lettura];
        }
    }

    int lettureTotali = numeroCentraline * LETTURE;
    media = media/lettureTotali;

    std::cout << "Valore medio del pm10: " << media << std::endl;

    int superataMedia = 0;
    for(int c = 0; c < lettureTotali; c++)
    {
        if (pAreaInt[c] > media)
        {
            superataMedia++;
        }
    }

    std::cout << "La media e' stata superata " << superataMedia 
              << " volte \n";

    delete pAreaInt[];
    pAreaInt = nullptr;

    return 0;
}