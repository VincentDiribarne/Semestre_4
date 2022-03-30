#ifndef __Vecteur3DT_H_
#define __Vecteur3DT_H_
#include <iostream>
template <class T>
class Vecteur3DT
{
public:
    Vecteur3DT();
    Vecteur3DT(const T tab[3]);
    Vecteur3DT(const T& x, const T& y, const T& z);
    Vecteur3DT(const Vecteur3DT& v);

    T& x();
    T& y();
    T& z();

    template <class T>
    friend std::ostream& operator<<(std::ostream& os, const Vecteur3DT<T>& v);
    bool operator==(const Vecteur3DT& v) const;
    bool operator!=(const Vecteur3DT& v) const;
    Vecteur3DT operator+(const Vecteur3DT& v) const;
    Vecteur3DT& operator+= (const Vecteur3DT& v);
    Vecteur3DT operator-(const Vecteur3DT& v) const;
    Vecteur3DT operator*(const T n) const;
    Vecteur3DT operator*(const Vecteur3DT& v) const;

    ~Vecteur3DT();

private:
    T m_x;
    T m_y;
    T m_z;
};
#include "Vecteur3DT.inl"
#endif