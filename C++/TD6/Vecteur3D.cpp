#include "Vecteur3D.h"
#include <iostream>
Vecteur3D::Vecteur3D() : m_x(0), m_y(0), m_z(0)
{
}
Vecteur3D::Vecteur3D(const int tab[3]) : m_x(tab[0]), m_y(tab[1]), m_z(tab[2])
{
}
Vecteur3D::Vecteur3D(const int x, const int y, const int z) : m_x(x), m_y(y), m_z(z)
{
}
Vecteur3D::Vecteur3D(const Vecteur3D& v) : m_x(v.m_x), m_y(v.m_y), m_z(v.m_z)
{
}
int& Vecteur3D::x()
{
    return m_x;
}
int& Vecteur3D::y()
{
    return m_y;
}
int& Vecteur3D::z()
{
    return m_z;
}
std::ostream& operator<<(std::ostream& os, const Vecteur3D& v)
{
    os << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ")";
    return os;
}
bool Vecteur3D::operator==(const Vecteur3D& v) const
{
    return (m_x == v.m_x && m_y == v.m_y && m_z == v.m_z);
}
bool Vecteur3D::operator!=(const Vecteur3D& v) const
{
    return !(*this == v);
}
Vecteur3D Vecteur3D::operator+(const Vecteur3D& v) const
{
    return Vecteur3D(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);
}
Vecteur3D Vecteur3D::operator-(const Vecteur3D& v) const
{
    return Vecteur3D(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
}
Vecteur3D Vecteur3D::operator*(const int n) const
{
    return Vecteur3D(m_x * n, m_y * n, m_z * n);
}
Vecteur3D Vecteur3D::operator*(const Vecteur3D& v) const
{
    return Vecteur3D(m_x * v.m_x, m_y * v.m_y, m_z * v.m_z);
}
Vecteur3D::~Vecteur3D() {}
