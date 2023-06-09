#include <iostream>
#include "data.h"

class Punto3D
{
public:
    Punto3D(double _x, double _y, double _z) : x{_x}, y{_y}, z{_z}
    {
        // altre isturzionu
    }

private:
    double x = 0, y = 0, z = 0;
};

void riceceData(Data d)
{
    std::cout << "Data ricevuta " << d.formatoBreve() << std::endl;
}

Data restituisceData()
{
    return Data{10, 11, 2023};
}

bool operator== (std::string s, Data d)
{
    return Data{s} == d;
}

int main()
{
    Data d1{5, 6, 2023};
    
    // Casi in cui viene invocato il COPY CONSTRUCTOR
    // in questo caso quello di default mancandone uno esplicito scritto da noi
    /*
    Data d2{d1};
    Data d3 = d2;
    riceceData(d1);
    std::cout << "Data restituita: " << restituisceData().formatoBreve() << std::endl;
    Data feste1[3] = {Data{1, 5, 2023}, Data{25, 12, 2023}, Data{1, 1, 2024}};
    Data feste2[3] = {{1, 5, 2023}, {25, 12, 2023}, {1, 1, 2024}};
    */

    /*
    Data d2(5, 6, 2023);
    Data d3{5, 6, 2023}; // liste di inizializzazione sempre da preferire

    Data d4; // Ci deve essere almeno un costruttore vuoto Data()

    Data d5 = d3; // copia di default
    Data d6{d3};  // copia di default

    Data *d7 = new Data{d3}; // alocazione dinamica e con copia di default

    std::cout << "Oggi e' il " << d1.formatoBreve() << std::endl;
    std::cout << "Paperino" << std::endl;

    delete d7;
    */

    return 0;
}