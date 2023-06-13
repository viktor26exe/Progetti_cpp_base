#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>

template <typename T, int _MAX>
class elencoOrdinato
{
public:
    elencoOrdinato() {}

    bool aggiungi(T nuovo)
    {
        if (inseriti == MAX)
        {
            return false;
        }
        else
        {
            // inserimento mantenendo l'ordine
            int posizioneInserimento = 0;

            while (posizioneInserimento < inseriti && nuovo > valori[posizioneInserimento])
            {
                posizioneInserimento++;
            }

            // shift a destra per far posto al nuovo
            // si parte dal fondo per evitare di sovrascrivere
            for (int i = inseriti; i > posizioneInserimento; i--)
            {
                valori[i] = valori[i - 1];
            }

            valori[posizioneInserimento] = nuovo;
            inseriti++;
            return true;
        }
    }

    void stampa()
    {
        std::cout << "Inizio ----------------------\n";
        for (int i = 0; i < inseriti; i++)
        {
            std::cout << valori[i] << std::endl;
        }

        std::cout << "Fine -----------------------\n";
    }

private:
    const static int MAX = _MAX;
    int inseriti = 0;
    T valori[MAX];
};

class Giocatore
{
public:
    friend std::ostream &operator<<(std::ostream &stream, const Giocatore &);

    // Genera valori casuali per simulare la 'carriera' del giocatore
    Giocatore() : nick{nick + std::to_string(rand() % 100000)},
                  kd{rand() % 3 + (rand() % 1000) / 1000},
                  numeroPartite{100 + rand() % 500},
                  ELO{500 + rand() % 2000}
    {
    }

    double livello() const
    {
        // formula casuale e senza alcun senso...
        return kd + numeroPartite + ELO;
    }

    bool operator>(Giocatore altro)
    {
        return this->livello() > altro.livello();
    }

private:
    std::string nick = "";
    double kd = 0; // rapporto kill death
    int numeroPartite = 0;
    int ELO = 0;
};

std::ostream &operator<<(std::ostream &stream, const Giocatore &g)
{
    stream << std::setw(20) << ("Giocatore: " + g.nick) << " | "
           << "Livello: " << g.livello();
    return stream;
}

template <typename T>
void sort(T v[], int numeroElementi)
{
    for (int i = 0; i < numeroElementi - 1; i++)
        for (int j = i + 1; j < numeroElementi; j++)
            if (v[j] < v[i])
                std::swap(v[i], v[j]);
}

template <typename T>
void stampa(T v[], int numeroElementi)
{
    for (int i = 0; i < numeroElementi; i++)
        std::cout << v[i] << std::endl;
}

class Cliente
{
public:
    Cliente(double _fatturato) : fatturato{_fatturato} {}

    double getFatturato() const { return fatturato; }

    bool operator<(const Cliente &altro) const
    {
        return this->fatturato < altro.fatturato;
    }

private:
    double fatturato = 0;
};

template <typename T>
void sort2(T v[], int numeroElementi, bool (*minoreDi)(const Cliente &, const Cliente &))
{
    for (int i = 0; i < numeroElementi - 1; i++)
        for (int j = i + 1; j < numeroElementi; j++)
            if (minoreDi(v[j] < v[i]))
                std::swap(v[i], v[j]);
}

template <typename T, typename C>
void sort3(T v[], int numeroElementi)
{
    // oggetto su cui usare il funtore per confronto
    C confronta;

    for (int i = 0; i < numeroElementi - 1; i++)
        for (int j = i + 1; j < numeroElementi; j++)
            if (confronta(v[j] < v[i])) // functor -> funtori
                std::swap(v[i], v[j]);
}

class Confronto
{
public:
    bool operator() (const Cliente& c1, const Cliente& c2) const
    {
        return trunc(c1.getFatturato()) < trunc(c2.getFatturato()); 
    }
};

int main()
{
    srand(time(0));
    elencoOrdinato<int, 1000> interi{};
    interi.aggiungi(rand());
    interi.aggiungi(rand());
    interi.aggiungi(rand());
    interi.aggiungi(rand());
    interi.aggiungi(rand());
    interi.stampa();

    return 0;
}