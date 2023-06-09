#include <iostream>

struct Punto3D
{
    long double x, y, z;
};

Punto3D *puntoMedio3D(const Punto3D *a, const Punto3D *b)
{
    long double x = (a->x + b->x) / 2;
    long double y = (a->y + b->y) / 2;
    long double z = (a->z + b->z) / 2;

    return new Punto3D{x, y, z};
}

int main()
{
    std::cout << sizeof(Punto3D) << std::endl;
    std::cout << sizeof(Punto3D *) << std::endl;

    Punto3D *a = new Punto3D{-4, 2, 8},
            *b = new Punto3D{6, 12, 56};

    Punto3D *medio = puntoMedio3D(a, b);

    std::cout << "x: " << medio->x << " y: " << medio->y << " z: " << medio->z << std::endl;

    return 0;
}