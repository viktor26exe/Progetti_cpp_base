#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <string>
#include <ctime> 

// classe base, superclasse, antenata, madre
class Data
{
    // INTERFACCIA / INTERFACE
public:
    // costruttori
    Data();
    Data(int gg, int mm, int aa);
    Data(int gg, int mm);      // anno == anno corrente
    Data(int gg);              // anno e mese == quelli correnti
    Data(const std::string d); // "07-05-2024"
    Data(const char v[]) : Data(std::string(v)) {}

    // getter
    int getGiorno() const { return giorno; }
    int getMese() const { return mese; }
    int getAnno() const { return anno; }

    // osservatori
    std::string formatoBreve() const;

    // overload operatori standard
    bool operator==(const Data &);
    bool operator==(std::string);
    bool operator<(const Data &);
    bool operator>(const Data &);
    Data operator++(int);
    Data &operator++(); // preincremento

    // altri
    static tm *dataCorrente();
    bool valida(int gg, int mm, int aa);
    static bool bisestile(int);
    static int giorniMese(int, int);

    friend std::ostream &operator<<(std::ostream &, const Data &);
    explicit operator std::string() const;

protected:


    // IMPLEMENTAZIONE / IMPLEMENTATION
private:
    // int giorno = 1, mese = 1, anno = 1970;
    int giorno{oggi->tm_mday};
    int mese{oggi->tm_mon + 1};
    int anno{oggi->tm_year + 1900};
    static tm *oggi;
};

std::ostream &operator<<(std::ostream &, const Data &);

// classe derivata, sotto classe, discendente, figlia
class DataING : public Data // : meccanismo del ereditarietà
                            // di default il modificatore è private
{
public:
    // costruttori
    DataING() : Data() {}
    DataING(int mese, int giorno, int anno) : Data(giorno, mese, anno) {}

    // osservatori
    std::string formatoBreve() const;

protected:

private:

};

#endif // DATA_H_INCLUDED