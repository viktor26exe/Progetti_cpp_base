#include "data.h"

void Data::initialization(int gg, int mm, int aa)
{
    if (valida(gg, mm, aa))
    {
        giorno == gg;
        mese == mm;
        anno == aa;
    }
    else // impostiamo la data corrente
    {
        tm *oggi = dataCorrente();
        giorno = oggi->tm_mday;
        mese = oggi->tm_mon;
        anno = oggi->tm_year + 1900;
    }
}

Data::Data() {}

Data::Data(int gg, int mm, int aa)
{
    initialization(gg, mm, aa);
}

Data::Data(int gg, int mm) // anno == anno corrente
{
    tm *oggi = dataCorrente();
    int aa = oggi->tm_year + 1900;
    initialization(gg, mm, aa);
}

Data::Data(int gg)
{
    tm *oggi = dataCorrente();
    int aa = oggi->tm_year + 1900;
    int mm = oggi->tm_mon;
    initialization(gg, mm, aa);
}

Data::Data(const std::string d)
{
    int gg = std::stoi(d.substr(0, 2));
    int mm = std::stoi(d.substr(3, 2));
    int aa = std::stoi(d.substr(6, 4));
    initialization(gg,mm,aa);
}

std::string Data::formatoBreve()
{
    return std::to_string(giorno) + "/" + std::to_string(mese) + "/" + std::to_string(anno);
}

tm *Data::dataCorrente()
{
    time_t tempoSecondi = time(nullptr);
    return localtime(&tempoSecondi);
}

bool Data::valida(int gg, int mm, int aa)
{
    return gg >= 1 && gg <= 31 && mm >= 1 && mm <= 12 && aa >= 1970;
}
