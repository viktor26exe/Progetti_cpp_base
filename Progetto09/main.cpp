#include <iostream>

int f(int n)
{
    return 3 * n;
}

bool minoreAlfabetico(std::string s1, std::string s2)
{
    return s1 < s2;
}

bool minoreLunghezza(std::string s1, std::string s2)
{
    return s1.length() < s2.length();
}

bool minoreValore(std::string s1, std::string s2)
{
    return std::stoi(s1) < std::stoi(s2);
}

void ordinamentoGenerico(std::string v[], int numeroElementi, bool (*fminoreDi)(std::string, std::string))
{
    for (int i = 0; i < numeroElementi - 1; i++)
        for (int j = i + 1; j < numeroElementi; j++)
            if (fminoreDi(v[j], v[i]))
                std::swap(v[i], v[j]);
}

void stampaVettore(std::string v[], int numeroElementi)
{
    for (int i = 0; i < numeroElementi; i++)
        std::cout << v[i] << " ";

    std::cout << std::endl;
}

int main()
{
    int (*pf)(int); // f è un puntatore a una funzione che restituisce
                    // un int e che riceve un int come parametro

    pf = &f; // metto nel puntatore l'indirizzo di f
    std::cout << (*pf)(5) << std::endl;

    // altra sintassi dei puntatori a funzione
    // pf = f;
    // std::cout << pf(5);

    std::string v1[]{"caso", "casalasco", "abate", "birillo"};
    ordinamentoGenerico(v1, 4, minoreAlfabetico);
    stampaVettore(v1, 4);

    std::string v2[]{"caso", "casalasco", "abate", "birillo"};
    ordinamentoGenerico(v2, 4, minoreLunghezza);
    stampaVettore(v2, 4);

    std::string v3[]{"100", "67", "2", "123"};
    ordinamentoGenerico(v3, 4, minoreValore);
    stampaVettore(v3, 4);

    return 0;
}