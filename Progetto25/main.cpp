# define NDEBUG // disattiva le asserzioni

#include <iostream>
#include <stdint.h>
#include <bitset>
#include <cassert>
#include <exception>

static_assert (sizeof(int) >= 4, "Interi non abbastanza capienti"); // interviene a compailer time

struct Punto
{
    double x;
    double y;
};

// Nelle struct l'ordine delle variabili è importante per minimizzare lo spazio occupato nella RAM
struct DettagliAtleta
{
    bool italiano;
    char sesso;
    int anniCarriera;
};

// struct bit filed
// utile soltanto se lo spazio della RAM è veramente importante
struct LedStatus
{
    bool led0 : 1;
    bool led1 : 1;
    bool led2 : 1;
    bool led3 : 1;
    bool led4 : 1;
    bool led5 : 1;
    bool led6 : 1;
    bool led7 : 1;
};

class ipv4
{
public:
    ipv4(uint8_t A, uint8_t B, uint8_t C, uint8_t D)
    {
        uint32_t A32bit = A;
        // A32bit = A32bit << 24;
        A32bit <<= 24; // faccio scivolare al posto giusto questi primi 8 bit

        uint32_t B32bit = B;
        B32bit <<= 16;

        uint32_t C32bit = C;
        C32bit <<= 8;

        indirizzo = A32bit + B32bit + C32bit + D;
    }

    uint32_t Dec()
    {
        return indirizzo;
    }

    std::string Bin_bitset()
    {
        std::bitset<32> bs(indirizzo);
        return bs.to_string();
    }

    std::string Bin()
    {
        std::string res = "";
        uint32_t mask = 1;

        for (int i = 0; i < 32; i++, mask <<= 1)
        {
            res = ((indirizzo & mask) > 0 ? "1" : "0") + res;

            if ((i + 1) % 8 == 0 && i < 31)
            {
                res = ":" + res;
            }
            else
            {
                if ((i + 1) % 4 == 0 && i < 31)
                {
                    res = "." + res;
                }
            }
        }

        return res;
    }

    void complemento()
    {
        indirizzo = ~indirizzo;
    }

    void orBitwise(uint32_t v)
    {
        indirizzo |= v;
    }

    void xorBitwise(uint32_t v)
    {
        indirizzo ^= v;
    }

private:
    uint32_t indirizzo;
    uint32_t subnetMask;
};

constexpr int fattorialeConstexpr(int n)
{
    return n > 1 ? n * fattorialeConstexpr(n - 1) : 1;
}

// precondizioni
//      numeroElementi > 0
//      interi a 32 bit 
double sommaArray (int v[], int numeroElementi)
{
    assert (sizeof(int) >= 8);
    assert (numeroElementi > 0);

    double result = 0;
    // calcoli ...
    // ...
    return result;
}

int main()
{
    Punto p1{}; // equivalente a { {} {} } => 0.0, 0.0
    Punto p2{-6, 5};

    std::cout << sizeof(DettagliAtleta) << std::endl;

    ipv4 indirizzo{192, 168, 35, 97};
    std::cout << indirizzo.Bin() << std::endl;

    const double PI_GRECO_CONST = 3.14;
    constexpr double PI_GRECO_CONSTEXPR = 3.14;

    int var = 0;
    std::cin >> var;

    const int COSTANTE = var;
    std::cout << COSTANTE << std::endl;



    return 0;
}