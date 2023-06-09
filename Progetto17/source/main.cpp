#include <iostream>
#include <memory>

class Contenitore
{
public:
    Contenitore(std::string _id, int valore) : id{_id}
    {
        p = new int[10];
        for (int i = 0; i < 10; i++)
            p[i] = valore;
    }

    // Distruttore della classe
    // I distruttori vengono chiamati aumaticamente per gli oggetti nello
    // stack alla fine del suo blocco
    ~Contenitore()
    {
        delete[] p;
    }

    // Copy constructor esplicito
    // interviene quando viene passato come parametro una variabile dello
    // stesso tipo della classe
    Contenitore(const Contenitore &c) : id{c.id}
    {
        p = new int[10];
        for (int i = 0; i < 10; i++)
            p[i] = c.p[i];
    }

    // Copy assignment esplicito
    // utile avere un tipo di ritorno per il multiassegnamento
    Contenitore &operator=(const Contenitore &daCopiare)
    {
        id = daCopiare.id;
        for (int i = 0; i < 10; i++)
            p[i] = daCopiare.p[i];

        return *this; // reference al oggetto stesso
    }

    void setId(std::string s) { id = s; };

    void setValore(int indice, int valore)
    {
        p[indice] = valore;
    }

    void stampa()
    {
        std::cout << id << ":";
        for (int i = 0; i < 10; i++)
            std::cout << p[i] << " ";

        std::cout << std::endl;
    }

private:
    std::string id{""};
    int *p{nullptr};
};

// tecnica per avere una chiamata a distruttori automaticamente a un
// puntatore a una classe
// Non smart al 100%
class p_Contenitore
{
public:
    p_Contenitore(std::string s, int n) : p{new Contenitore(s, n)}
    {
    }

    ~p_Contenitore() { delete p; }

    Contenitore *get_p() { return p; }

private:
    Contenitore *p = nullptr;
};

struct Alunno
{
    std::string nome;
    int eta;
};

int main()
{
    std::unique_ptr<int> sp{new int};
    *sp = 12;
    std::cout << *sp << std::endl;

    // cout << sp; ERRORE: sp non è un puntatore
    // e << non riconosce cosa sia sp

    std::cout << sp.get() << std::endl;    // puntatore interno
    std::cout << *(sp.get()) << std::endl; // 12

    // delete sp.get() NO! ok si può fare tecnicamente fare ma non dite di
    // averlo fatto incosciamente

    sp.reset(); // OK, modalità "gestita" delete comandato internamente
                // e valorizzato a nullptr!

    if (sp == nullptr)
    {
        std::cout << "Puntatore non utilizzabile! \n";
    }

    sp.reset(new int{18});
    std::cout << *sp << std::endl;

    sp.reset(new int{574});
    std::cout << *sp << std::endl;

    std::unique_ptr<int[]> spVett{new int[3]{5, 10, 15}};
    std::cout << spVett[1] << std::endl;
    std::cout << *(spVett.get() + 2) << std::endl;

    std::unique_ptr<Alunno> unAlunno{new Alunno{"Giorgio", 15}};
    std::cout << unAlunno->nome << std::endl;

    std::unique_ptr<int> sp2;
    // sp2 = new int{13}; NO: usare sp2.reset(new int{13})


    return 0;
}