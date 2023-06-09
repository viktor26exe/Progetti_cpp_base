#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

    srand(time(0));
    fstream f("immagine.bmp", ios::out | ios::in | ios::binary);

    // modo per avere la dimensioni di un file
    f.seekg(0, ios::end);
    long dimesione = f.tellg();
    std::cout << "Dimensione -> " << dimesione << endl;

    // riposizionamento al inzio del file
    f.seekg(0, ios::beg);

    char* immagineRAM = nullptr;

    // altre istruzioni ...
    
    immagineRAM = new char [dimesione]; // il new se ha successo restituisce l'indirizzo di memoria del primo byte
    f.read (immagineRAM, dimesione);

    for ( int i = 10000; i < dimesione; i++)
    {
        immagineRAM[i] = rand() % 256;
    }

    f.seekp(0,ios::beg);
    f.write(immagineRAM, dimesione);
    
    f.close(); f.clear();

    // libero la RAM
    delete[] immagineRAM;
    immagineRAM = nullptr;

    // altre istruzioni ... 
    

    return 0;
}