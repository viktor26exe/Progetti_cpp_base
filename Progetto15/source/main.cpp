#include <iostream>
#include "data.h"

int main()
{
    Data d1 = Data (5,6,2023);
    Data d2 (5,6,2023);
    Data d3 {5,6,2023}; // liste di inizializzazione sempre da preferire

    Data d4; // Ci deve essere almeno un costruttore vuoto Data()

    Data d5 = d3; // copia di default
    Data d6 {d3}; // copia di default

    Data *d7 = new Data {d3}; // alocazione dinamica e con copia di default

    std::cout << "Oggi e' il " << d1.formatoBreve() << std::endl;
    std::cout << "Paperino" << std::endl;

    delete d7;

    return 0;
}