#include <iostream>

class divisione_per_zero : public std::invalid_argument
{
public:
    // costruttore per le stringhe come array di char (C like)
    divisione_per_zero(const char *messaggio) : invalid_argument{messaggio} {}

    // costruttore per stringhe C++
    divisione_per_zero(std::string messaggio) : invalid_argument{messaggio} {}

    // distruttore virtual per eventuali sottoclassi
    virtual ~divisione_per_zero() {}

    // override del metodo what(), virtual per poterlo ridefinire in eventuali classi figlie
    virtual const char *what()
    {
        return ("User Defined Exception: " + std::string(invalid_argument::what())).c_str();
    }
};

double calcolo(double x)
{
    int n = rand();
    
    if(x == 0)
        throw divisione_per_zero("divisione per zero");
    
    return n / x;
}

int main()
{
    try
    {
        std::cout << calcolo(0) << std::endl;
    }
    catch (const char* messaggio)
    {
        std::cout << "Eccezione: " << messaggio << std::endl;
    }

    return 0;
}