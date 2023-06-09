#include <iostream>
#include <cmath>

/**
 * PIANO TARIFFARIO
 * - operatore
 * - nome
 * - costo sms
 * - costo mms
 * - costo alla rispsosta
 * - costo al minuto
 * - GB traffico mese Internet
 */
struct pianoTariffario
{
    std::string operatore;
    std::string nome;
    double costoSMS;
    double costoMMS;
    double costoRisposta;
    double costoAlMinuto;
    int smsGratis;
    int gigaMese;
};

template <typename T>
struct Punto
{
    T x;
    T y;
};

template <typename T>
struct Poligono
{
    int numeroLati;
    Punto<T> vertici[100];
};


template <typename T>
double distanzaTraPunti(T a, T b = {0, 0})
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}


template <typename T>
T puntoMedio(T a, T b = {0, 0})
{
    return T{(a.x + b.x) / 2, (a.y + b.y) / 2};
}


template <typename T>
double perimetro(T p)
{
    double risultato = 0;

    for (int i = 0; i < p.numeroLati; i++)
    {
        risultato += distanzaTraPunti(p.vertici[i], p.vertici[i + 1]);
    }

    return risultato;
}

// argc -> indica il numero di parametri passati
// argv[0] -> c'è il nome del programma
int main(int argc, char *argv[])
{
    /*
    std::cout << "Sono il programma " << argv[0] << std::endl;
    std::cout << "E sono stato invocato con questi parametri: " << std::endl;
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
    */

    Punto<double> p1{3, 4}, p2{7, 8};
    std::cout << distanzaTraPunti(p1) << std::endl;
    Punto<double> medio = puntoMedio(p1, p2);
    std::cout << "Punto medio: (" << medio.x << "," << medio.y << ")\n";

    return 0;
}