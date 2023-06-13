#include <string>
#include <iostream>
#include <vector>

class Figura
{
public:
    Figura(std::string coloreTratto,
           std::string coloreFill = "bianco",
           int spessoreTratto = 1,
           bool filled = false) : coloreTratto{coloreTratto},
                                  coloreFill{coloreFill},
                                  spessoreTratto{spessoreTratto},
                                  filled{filled}
    {
    }

    Figura() : Figura("nero")
    {
    }

    virtual ~Figura() {} // serve per sicurezza ed evitare leek di memoria nella chiamata ai distruttori

    // la keyword virtual attiva il meccanismo di dynamic binding
    // è obbligatoria
    virtual double perimetro() { return 10; }

protected:
private:
    std::string coloreTratto = "";
    std::string coloreFill = "";
    bool filled = false;
    int spessoreTratto = 0;
};

class Triangolo : public Figura
{
public:
    Triangolo() : Figura(), lato1{1}, lato2{1}, lato3{1}
    {
    }

    Triangolo(int _lato1, int _lato2, int _lato3)
        : Figura("rosso", "", 1, false), lato1{_lato1}, lato2{_lato2}, lato3{_lato3}
    {
    }

    ~Triangolo() override {}

    // override -> meccanismo di dynamic bindig
    // non è obbligatoria ma consigliabile metterle per evitare errori
    double perimetro() override
    {
        return lato1 + lato2 + lato3;
    }

private:
    int lato1 = 0, lato2 = 0, lato3 = 0;
};

class Rettangolo : public Figura
{
public:
    Rettangolo() : Figura(), l1{1}, l2{1}
    {
    }

    Rettangolo(int _lato1, int _lato2)
        : Figura("rosso", "", 1, false), l1{_lato1}, l2{_lato2}
    {
    }

    double perimetro() override
    {
        return (l1 + l2) * 2;
    }

protected:
    int l1 = 0, l2 = 0;
};

class Quadrato : public Rettangolo
{
public:
    Quadrato() : Rettangolo() {}
    Quadrato(int lato) : Rettangolo(lato, lato) {}

    double perimetro() override
    {
        return l1 * 4; // migliori prestazioni!
    }

private:
};

class Cerchio : public Figura
{
public:
    Cerchio(int raggio) : Figura("nero"), raggio{raggio}
    {
    }

    double perimetro() override
    {
        return 2 * 3.14 * raggio;
    }

protected:
    int raggio = 0;
};

class RettangoloAureo : public Rettangolo
{
    using Rettangolo::Rettangolo; // la direttiva using permette l'utilizzo del costruttore della classe madre
};