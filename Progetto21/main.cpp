#include <iostream>

class Persona
{
public:
    Persona() : Persona("", 0) {}
    Persona(std::string _nome, int _eta) : nome{_nome}, eta{_eta} {}

    ~Persona() {}

    std::string getNome() { return nome; }
    int getEta() { return eta; }

private:
    std::string nome = "";
    int eta = 0;
};

class Impiegato
{
public:
    Impiegato() : Impiegato{"", 0} {}
    Impiegato(std::string _datoreLavoro, int _stipendio) : datoreLavoro{_datoreLavoro}, stipendio{_stipendio} {}

    ~Impiegato() {}

    std::string getDatoreLavoro() { return datoreLavoro; }
    int getStipendio() { return stipendio; }

private:
    std::string datoreLavoro = "";
    int stipendio = 0;
};

class Insegnante : public Persona, public Impiegato
{
public:
    Insegnante() : Insegnante("") {}
    Insegnante(std::string _ordineScuola) : ordineScuola{_ordineScuola} {}

    ~Insegnante() {}

private:
    std::string ordineScuola = "";
};

int main()
{
    
    
    return 0;
}