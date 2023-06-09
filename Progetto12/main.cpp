#include <iostream>

const int MAX = 500;

struct RigaScontrino
{
    int codiceProdotto;
    double quantita;
    double prezzo;
    RigaScontrino *next; // indirizzo della riga successiva, nel caso che è l'ultima della lista il vallore sarà nullptr
};

struct Scontrino
{
    std::string data;
    int codicePuntoVendita;
    std::string codiceCassa;
    RigaScontrino *head; // indirizzo primo nodo lista righe scontrino
};

void inserimentoInTesta(RigaScontrino *&head, RigaScontrino *nuovo)
{
    nuovo->next = head; // aggancio al vecchio primo nodo
    head = nuovo;       // aggancio la head al nuovo primo nodo
}

void inserimentoInCoda(RigaScontrino *&head, RigaScontrino *nuovo)
{
    RigaScontrino *cercaFineLista = head;

    // ricerco la fine della lista
    // obbiettivo: fermarsi quando cercaFineLista è sull'ultimo nodo cioè sul nodo che ha
    //             nullptr come next
    if (head == nullptr)
    {
        // caso lista vuota
        inserimentoInTesta(head, nuovo);
    }
    else
    {
        // caso lista almeno con un elemento
        while (cercaFineLista->next != nullptr)
        {
            cercaFineLista = cercaFineLista->next;
        }
        cercaFineLista->next = nuovo;
        nuovo->next = nullptr;
    }
}

RigaScontrino *cercaLista(RigaScontrino *head, RigaScontrino *&precedente, int codiceProdottoCercato)
{
    precedente = nullptr;
    RigaScontrino *corrente = head;

    while (corrente != nullptr && corrente->codiceProdotto != codiceProdottoCercato)
    {
        precedente = corrente;
        corrente = corrente->next;
    }

    return corrente; // se lista vuota o non trova nulla sarà nullptr
}

bool eliminaDaLista(RigaScontrino *&head, int codiceProdotto)
{
    RigaScontrino *precedente = nullptr;
    RigaScontrino *trovato = cercaLista(head, precedente, codiceProdotto);

    if (trovato == nullptr)
    {
        return false;
    }

    // caso primo della lista
    if (precedente == nullptr)
    {
        head = head->next; // bypassato il primo nodo
    }
    else
    {
        precedente->next = trovato->next; // bypassato il nodo da cancellare
    }

    // elimino il nodo
    delete trovato;

    return true;
}

void distruggiLista(RigaScontrino *&head)
{
    RigaScontrino *temp = head;

    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    
}

void stampaRigheScontrino(RigaScontrino *head)
{
    RigaScontrino *scorri = head;

    while (scorri != nullptr)
    {
        std::cout << "----------\n";
        std::cout << "Prodotto: " << scorri->codiceProdotto << std::endl;
        std::cout << "Quantita': " << scorri->quantita << std::endl;
        std::cout << "Prezzo: " << scorri->prezzo << std::endl;

        scorri = scorri->next;
    }
}

int main()
{
    Scontrino *scontrino = new Scontrino{"01-06-2023", 123, "Cassa23", nullptr}; // puntatore a struct

    // test ricerca con lista vuota
    RigaScontrino *precedente = nullptr;
    RigaScontrino *trovato = cercaLista(scontrino->head, precedente, 8);
    if (trovato == nullptr)
    {
        std::cout << "Non trovato in lista vuota\n";
    }

    // test ricerca con un solo nodo in lista
    RigaScontrino *nuovo = new RigaScontrino{18, 10, 100};
    inserimentoInCoda(scontrino->head, nuovo);
    precedente = nullptr;
    trovato = cercaLista(scontrino->head, precedente, 18);
    if (trovato == nullptr)
    {
        std::cout << "18 non trovato\n";
    }
    else
    {
        std::cout << "Codice 18 trovato ";
        if (precedente != nullptr)
        {
            std::cout << "e ha trovato altri nodi prima di lui\n";
        }
        else
        {
            std::cout << "ed è il primo della lista\n";
        }
    }

    precedente = nullptr;
    trovato = cercaLista(scontrino->head, precedente, 88);
    if (trovato == nullptr)
    {
        std::cout << "88 non trovato\n";
    }
    else
    {
        std::cout << "Codice 88 trovato ";
        if (precedente != nullptr)
        {
            std::cout << "e ha trovato altri nodi prima di lui\n";
        }
        else
        {
            std::cout << "ed è il primo della lista\n";
        }
    }

    for (int i = 0; i < 10; i++)
    {
        // std::cout << i << std::endl;
        RigaScontrino *nuovo = new RigaScontrino{i, 10.0 * i, 100.0 * 1};
        inserimentoInCoda(scontrino->head, nuovo);
    }

    precedente = nullptr;
    trovato = cercaLista(scontrino->head, precedente, 9);
    if (trovato == nullptr)
    {
        std::cout << "9 non trovato\n";
    }
    else
    {
        std::cout << "Codice 9 trovato ";
        if (precedente != nullptr)
        {
            std::cout << "e ha trovato altri nodi prima di lui\n";
        }
        else
        {
            std::cout << "ed è il primo della lista\n";
        }
    }

    precedente = nullptr;
    trovato = cercaLista(scontrino->head, precedente, 99);
    if (trovato == nullptr)
    {
        std::cout << "99 non trovato\n";
    }
    else
    {
        std::cout << "Codice 99 trovato ";
        if (precedente != nullptr)
        {
            std::cout << "e ha trovato altri nodi prima di lui\n";
        }
        else
        {
            std::cout << "ed è il primo della lista\n";
        }
    }

    std::cout << "--------------------------------------------------\n";
    std::cout << "TEST ELIMINAZIONE\n";
    stampaRigheScontrino(scontrino->head);

    // elimino codice 18 (primo della lista)
    if(eliminaDaLista(scontrino->head, 18))
        std::cout << "Nodo con codice 18 eliminato\n";
    stampaRigheScontrino(scontrino->head); 

    // elimino codice 9 (ultimo della lista)
    if(eliminaDaLista(scontrino->head, 9))
        std::cout << "Nodo con codice 9 eliminato\n";
    stampaRigheScontrino(scontrino->head);

    // elimino codice 4 (nodo intermedio)
    if(eliminaDaLista(scontrino->head, 4))
        std::cout << "Nodo con codice 4 eliminato\n";
    stampaRigheScontrino(scontrino->head);

    std::cout << "Distruzione lista\n";
    // distruggo tutta la lista
    distruggiLista(scontrino->head);
    stampaRigheScontrino(scontrino->head);

    return 0;
}