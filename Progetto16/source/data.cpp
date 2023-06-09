#include "data.h"

// CLASSE DATA

Data::Data() {}

// costruttore delegato
Data::Data(int gg, int mm, int aa)
{
    if (valida(gg, mm, aa))
    {
        this->giorno == gg;
        this->mese == mm;
        this->anno == aa;
    }
    else // impostiamo la data corrente
    {
        // tm *oggi = dataCorrente();
        this->giorno = oggi->tm_mday;
        this->mese = oggi->tm_mon + 1;
        this->anno = oggi->tm_year + 1900;
    }
}

Data::Data(int gg, int mm) : Data(gg, mm, dataCorrente()->tm_year + 1900)
{
}

Data::Data(int gg) : Data(gg, dataCorrente()->tm_mon, dataCorrente()->tm_year + 1900)
{
}

Data::Data(const std::string d) : Data(std::stoi(d.substr(0, 2)),
                                       std::stoi(d.substr(3, 2)),
                                       std::stoi(d.substr(6, 4)))
{
}

std::string Data::formatoBreve() const
{
    return std::to_string(giorno) + "/" + std::to_string(mese) + "/" + std::to_string(anno);
}

// overload degli operatori standard
bool Data::operator==(const Data &d)
{
    return giorno == d.giorno && mese == d.mese && anno == d.anno;
}

bool Data::operator==(std::string s)
{
    return Data{s} == *this;
}

bool Data::operator<(const Data &d)
{
    if (anno < d.anno)
        return true;
    else if (anno == d.anno)
        if (mese < d.mese)
            return true;
        else if (mese = d.mese)
            if (giorno < d.giorno)
                return true;

    return false;
}

bool Data::operator>(const Data &d)
{
    return !(*this < d || *this == d);
}

Data Data::operator++(int nonUsato)
{
    Data d = *this; // la data prima dell'incremento

    giorno++;

    if (giorno > giorniMese(mese, anno)) // inizio mese successivo
    {
        mese++;
        giorno = 1;
    }

    if (mese > 12) // inizio anno successivo
    {
        anno++;
        giorno = 1;
        mese = 1;
    }

    return d;
}

Data &Data::operator++()
{
    giorno++;

    if (giorno > giorniMese(mese, anno)) // inizio mese successivo
    {
        mese++;
        giorno = 1;
    }

    if (mese > 12) // inizio anno successivo
    {
        anno++;
        giorno = 1;
        mese = 1;
    }

    return *this;
}

// altri
tm *Data::dataCorrente()
{
    time_t tempoSecondi = time(nullptr);
    return localtime(&tempoSecondi);
}

bool Data::valida(int gg, int mm, int aa)
{
    return gg >= 1 && gg <= 31 && mm >= 1 && mm <= 12 && aa >= 1970;
}

bool Data::bisestile(int aa)
{
    return ((aa % 4 == 0 && aa % 100 != 0) || (aa % 400 == 0));
}

int Data::giorniMese(int mm, int aa)
{
    switch (mm)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        return Data::bisestile(aa) ? 29 : 28;
        break;
    default:
        return 0;
        break;
    }
}

Data::operator std::string() const
{
    return formatoBreve();
}

// variabile static
tm *Data::oggi = Data::dataCorrente();

std::ostream &operator<<(std::ostream &stream, const Data &d)
{
    stream << d.formatoBreve();
    return stream;
}

// -----------------------------------------------------------------------------------------------
// CLASSE DATAING

std::string DataING::formatoBreve() const
{
    return std::to_string(getMese()) + "/" +
           std::to_string(getGiorno()) + "/" +
           std::to_string(getAnno());
}