#include <iostream>

struct StatoPannello
{
    unsigned int codicePannello; // max 16 pannelli codificati da 0 a 15

    unsigned int valoreSonda[7]; // valore codificati come un livello da 0 a 15
};

struct StatoPannelloBitfiled
{
    unsigned short int codicePannello : 4; // 4 rappresenta il numero dei bit

    unsigned short int valoreSonda1 : 4;
    unsigned short int valoreSonda2 : 4;
    unsigned short int valoreSonda3 : 4;
    unsigned short int valoreSonda4 : 4;
    unsigned short int valoreSonda5 : 4;
    unsigned short int valoreSonda6 : 4;
    unsigned short int valoreSonda7 : 4;
};

/*
union Riferimento
{
    char sigla[3]; // usato solo se UE == true
    int codiceNazione; // usato solo se UE == false
};
*/

struct Cliente
{
    bool UE;
    // Riferimento riferimento;

    // Union anonima
    union
    {
        char sigla[3];     // usato solo se UE == true
        int codiceNazione; // usato solo se UE == false
    };
};

int main()
{
    // Le enumerazioni sono un tipo
    // Enumerazione pre C++ 11
    // Punto debole 1: visibilità degli enumeratori allo stesso livello della enum stessa
    // Punto debole 2: controllo insufficiente da parte del compilatore
    enum giornoSettimana
    {
        Lun,
        Mar,
        Mer,
        Gio,
        Ven,
        Sab,
        Dom
    };

    // Standard C++ 11
    // Risolve i due problemi sopra citati
    // Più efficente nel utilizzo della RAM
    // Accetata la dicharazione anticipata
    enum class colori: char
    {
        giallo,
        rosso,
        verde,
        blu
    };

    enum class spettro
    {
        rosso,
        rosa,
        giallo,
        verde,
        nero
    };

    return 0;
}
