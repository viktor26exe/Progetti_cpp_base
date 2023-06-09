#include <iostream>
#include <stdio.h>

class ImmagineFullHD
{
public:
    ImmagineFullHD(std::string pathFile)
    {
        std::cout << "Invocato il costurttore NON vuoto \n";

        path = pathFile;

        // creo lo spazio in memoria per leggere i dati di tutti i 1920*1080 pixel in full HD
        // servono 4 byte per i pixel RGB + canale alfa trasparenza
        bitmap = new char[4 * 1920 * 1080];

        // immagina qui istruzioni che leggono i dati del file indicato come parametro ...
        // ...
    }

    ImmagineFullHD()
    {
        std::cout << "Invocato il costurttore VUOTO \n";
        bitmap = new char[4 * 1920 * 1080];
    }

    // copy constructor
    ImmagineFullHD(const ImmagineFullHD &img)
    {
        std::cout << "Invocato il copy constructor == COPIA \n";
        path = img.path;
        bitmap = new char[4 * 1920 * 1080];
        memcpy(bitmap, img.bitmap, 4 * 1920 * 1080);
    }

    // MOVE consturctor
    ImmagineFullHD(ImmagineFullHD &&img)
    {
        std::cout << "Invocato il MOVE constructor == NIENTE COPIA \n";
        path = std::move(img.path);
        bitmap = img.bitmap; // NESSUNA ALLOCAZIONE, NESSUNA COPIA!
        img.bitmap = nullptr;
    }

    // assignment operator
    ImmagineFullHD &operator=(const ImmagineFullHD &img)
    {
        std::cout << "Invocato l'assignment operator == COPIA \n";
        path = img.path;
        memcpy(bitmap, img.bitmap, 4 * 1920 * 1080);
        return *this;
    }

    // MOVE assignment operator
    ImmagineFullHD &operator=(ImmagineFullHD &&img) // && -> Dare in ingresso un r-value
    {
        std::cout << "Invocato il MOVE assignmet operator == NIENTE COPIA \n";
        path = std::move(img.path);
        delete[] bitmap; // rilascio risorsa pre esistente
        bitmap = img.bitmap; // NESSUNA ALLOCAZIONE, NESSUNA COPIA!
        img.bitmap = nullptr;
        return *this;
    }

    // distruttore
    ~ImmagineFullHD()
    {
        delete[] bitmap;
    }

    // altri metodi ...
    // ...

private:
    char *bitmap = nullptr; // la mappa dei pixel
    std::string path = "";  // path e nome file immagine
};

class UsaImmagine
{
public:
    UsaImmagine(ImmagineFullHD img) // NOTA: qui copy constructor
    {
        // NOTA: in questo assegnamento viene richiamato l'assignment operator di
        //       ImmagineFullHD
        this->img = std::move(img);
    }

private:
    ImmagineFullHD img;
};

int main()
{
    UsaImmagine x(ImmagineFullHD("D:\C++ base\Progetto18"));

    return 0;
}