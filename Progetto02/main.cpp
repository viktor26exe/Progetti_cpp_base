#include <iostream>
#include <fstream>
 
int main()
{
    std::ifstream file("dati.txt");

    if (file) // se file è in uno stato valido
    {
        // utilizzo file
        std::string riga = "";
        while (std::getline(file, riga))
        {
            std::cout << riga << std::endl;
        }
        // chiusura file
        file.close();
        file.clear();
    }
    else
    {
        std::cout << "Problemi di apertura!\n";
    }

    return 0;
}