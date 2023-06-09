#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <string>
#include <ctime>

class Data
{

    // INTERFACCIA / INTERFACE
public:
    // costruttori
    void initialization (int gg, int mm, int aa);
    Data();
    Data(int gg, int mm, int aa);
    Data(int gg, int mm);      // anno == anno corrente
    Data(int gg);              // anno e mese == quelli correnti
    Data(const std::string d); // "07-05-2024"

    // osservatori
    std::string formatoBreve();

    // altri
    tm *dataCorrente();
    bool valida(int gg, int mm, int aa);

    // IMPLEMENTAZIONE / IMPLEMENTATION
private:
    int giorno = 1,
        mese = 1, anno = 1970;
};

#endif // DATA_H_INCLUDED