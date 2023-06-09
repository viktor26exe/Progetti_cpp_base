#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

const int MAX_ELE = 1000;
const int LETTERE = 500;

std::string v[MAX_ELE];
std::string *vpStringhe[MAX_ELE]; // array di puntatori a stringhe

int main()
{
    time_t start = 0, stop = 0; // time_t è un tipo intero

    srand(10);

    for (int i = 0; i < MAX_ELE; i++)
    {
        int n = rand();

        // faccio in modo che la parte numerica di ogni stringa iniziale si sempre lunga uguale
        std::string ns = std::to_string(n);
        ns = std::string(5 - ns.length(), '0') + ns;

        // aggiungo dopo la parte numerica un numero di caratteri generati in modo casuale
        v[i] = ns + std::string(LETTERE, 'a' + rand() % 26);
    }

    std::cout << "Inizio con gli array\n";
    start = time(0);

    // algoritmo di sort
    for (int i = 0; i < MAX_ELE - 1; i++)
    {
        for (int j = i + 1; j < MAX_ELE; j++)
        {
            if (v[j] < v[i])
            {
                std::string tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }

    stop = time(0);

    std::cout << "Tempo impiegato con gli array: " << difftime(stop, start) << std::endl;
    std::cout << "I primi 10 come verifica: \n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << v[i].substr(0, 10) << std::endl;
    }

    

    srand(10);

    for (int i = 0; i < MAX_ELE; i++)
    {
        int n = rand();

        // faccio in modo che la parte numerica di ogni stringa iniziale si sempre lunga uguale
        std::string ns = std::to_string(n);
        ns = std::string(5 - ns.length(), '0') + ns;

        // aggiungo dopo la parte numerica un numero di caratteri generati in modo casuale
        v[i] = ns + std::string(LETTERE, 'a' + rand() % 26);
        
        vpStringhe[i] = &v[i]; //   & -> indirizzo
    }

    std::cout << "Inizio con i puntatori\n";
    start = time(0);

    // algoritmo di sort scambiando gli indirizzi non le stringhe
    for (int i = 0; i < MAX_ELE - 1; i++)
    {
        for (int j = i + 1; j < MAX_ELE; j++)
        {
            if (*vpStringhe[j] < *vpStringhe[i])
            {
                std::string *tmp = vpStringhe[i];
                vpStringhe[i] = vpStringhe[j];
                vpStringhe[j] = tmp;
            }
        }
    }

    stop = time(0);

    std::cout << "Tempo impiegato con i puntatori: " << difftime(stop, start) << std::endl;
    std::cout << "I primi 10 come verifica: \n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << (*vpStringhe[i]).substr(0, 10) << std::endl;
    }


    return 0;
}