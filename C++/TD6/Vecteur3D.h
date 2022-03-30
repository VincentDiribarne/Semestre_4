#ifndef __Vecteur3D_H_
#define __Vecteur3D_H_
#include <iostream>
class Vecteur3D
{
public:
    Vecteur3D();
    Vecteur3D(const int tab[3]);
    Vecteur3D(const int x, const int y, const int z);
    Vecteur3D(const Vecteur3D& v);

    int& x();
    int& y();
    int& z();

    friend std::ostream& operator<<(std::ostream& os, const Vecteur3D& v);
    bool operator==(const Vecteur3D& v) const;
    bool operator!=(const Vecteur3D& v) const;
    Vecteur3D operator+(const Vecteur3D& v) const;
    Vecteur3D operator-(const Vecteur3D& v) const;
    Vecteur3D operator*(const int n) const;
    Vecteur3D operator*(const Vecteur3D& v) const;

    ~Vecteur3D();

private:
    int m_x;
    int m_y;
    int m_z;
};
#endif