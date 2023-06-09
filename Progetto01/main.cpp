#include <iostream>
#include <cstdlib> // rand() e srand()
#include <ctime>   // time

int main()
{
    // contiamo quante volte è necessario lanciare un dado
    // simulato perchè esca tre volte il numero 6

    std::cout << "Max numero generabile -> " << RAND_MAX << std::endl;

    int numero_estratto = 0, conta_sei = 0, numero_lanci = 0;
    //bool n1, n2, n3, n4, n5, n6;
    //n1 = n2 = n3 = n4 = n5 = n6 = false;

    while (conta_sei < 3)
    {
        numero_estratto = rand() % 6 + 1;
        numero_lanci++;
        if (numero_estratto == 6){
            conta_sei++;
        }
        std::cout << numero_estratto << std::endl;
       
        /* 
        switch (numero_estratto)
        {
        case 1:
            n1 = true;
            break;

        case 2:
            n2 = true;
            break;

        case 3:
            n3 = true;
            break;

        case 4:
            n4 = true;
            break;
        case 5:
            n5 = true;
            break;
        case 6:
            n6 = true;
            break;

        default:
            break;
        }

        if (numero_estratto < 1 || numero_estratto > 6)
        {
            break; // interrompe il ciclo
        }

        if (n1 && n2 && n3 && n4 && n5 && n6)
        {
            break;
        }
        */
    }
    
    /*
    if (n1 && n2 && n3 && n4 && n5 && n6)
    {
        std::cout << "Estratti almeno una volta tutti i numeri previsti\n";
    }
    else
    {
        std::cout << "Se siamo usciti siamo nei guai!\n ESTRATTO -> " << numero_estratto;
    }
    */

   std::cout << "Ci sono voluti " << numero_lanci << " lanci per estrarre 3 volte il 6\n";
    
    return 0;
}