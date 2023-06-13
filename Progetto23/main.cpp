#include <iostream>
#include <vector>
#include <string>

class Contatto
{
public:
    Contatto(std::string _nome, std::string _indirizzo, std::string _telefono)
        : nome{_nome}, indirizzo{_indirizzo}, telefono{_telefono}
    {
    }

    std::string getNome() { return nome; }
    std::string getIndirizzo() { return indirizzo; }
    std::string getTelefono() { return telefono; }

private:
    std::string nome = "";
    std::string indirizzo = "";
    std::string telefono = "";
};

class Rubrica
{
public:
    Rubrica() {}

    template <typename T>
    std::vector<Contatto> cercaPerIndirizzo(T criterio)
    {
        std::vector<Contatto> trovati;
        for (Contatto c : contatti)
            if (criterio(c.getIndirizzo()))
                trovati.push_back(c);

        return trovati;
    }

    template <typename T>
    std::vector<Contatto> cercaPerNome(T funzioneLambda)
    {
        std::vector<Contatto> trovati;
        for (Contatto c : contatti)
            if (funzioneLambda(c.getNome(), c.getTelefono()))
                trovati.push_back(c);

        return trovati;
    }

private:
    std::vector<Contatto> contatti{
        {"Rossi", "Via Monti 23", "37956456"},
        {"Verdi", "Via Roma 17", "35633653"},
        {"Paoli", "Via Po 7", "35454356"},
    };
};

int main()
{
    Rubrica r{};
    // SENZA CLOSURE
    /*
    std::vector<Contatto> trovati =
        r.cercaPerIndirizzo([](std::string indirizzo)
                            { return indirizzo.find("Monti") != std::string::npos; }); // funzione lambda

    for (Contatto c : trovati)
        std::cout << c.getNome() << " - Tel. " << c.getTelefono() << std::endl;
    */

    // CON CLOSURE
    std::string nomeCercato = "";
    std::cout << "Cerca: ";
    std::cin >> nomeCercato;

    int quanteCifre = 0;
    std::cout << "Telefono a quante cifre: ";
    std::cin >> quanteCifre;

    std::vector<Contatto> trovati =
        r.cercaPerNome([&](const std::string &nome, const std::string &telefono)
                       { return nome.find(nomeCercato) != std::string::npos &&
                                telefono.length() == quanteCifre; });

    return 0;
}