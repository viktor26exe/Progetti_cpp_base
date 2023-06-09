#include <iostream>

int main()
{
    char *pChar = new char[100];
    double *pDouble = new double[100];

    for (int i = 0; i < 5; i++)
    {
        pDouble[i] = rand();
        std::cout << pDouble[i] << std::endl;
    }

    std::cout << "----------------------------------------------\n";

    pChar = (char *)pDouble;

    for (int i = 0; i < 5; i++)
    {
        // ^ xor -> or esclusivo bit a bit
        pChar[i * 8 + 7] = pChar[i * 8 + 7] ^ 'A'; // l'ultimo byte di ogni double
        std::cout << pDouble[i] << std::endl;
    }

    std::cout << "----------------------------------------------\n";

    for (int i = 0; i < 5; i++)
    {
        pChar[i * 8 + 7] ^= 'A';
        std::cout << pDouble[i] << std::endl;
    }

    return 0;
}