#include "Vecteur3DT.h"
template <class T>
Vecteur3DT<T>::Vecteur3DT()
{
    this->m_x = T();
    this->m_y = T();
    this->m_z = T();
}

template <class T>
Vecteur3DT<T>::Vecteur3DT(const T tab[3])
{
    m_x = tab[0];
    m_y = tab[1];
    m_z = tab[2];
}

template <class T>
Vecteur3DT<T>::Vecteur3DT(const T& x, const T& y, const T& z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

template <class T>
Vecteur3DT<T>::Vecteur3DT(const Vecteur3DT& v)
{
    m_x = v.m_x;
    m_y = v.m_y;
    m_z = v.m_z;
}

template <class T>
T& Vecteur3DT<T>::x()
{
    return m_x;
}

template <class T>
T& Vecteur3DT<T>::y()
{
    return m_y;
}

template <class T>
T& Vecteur3DT<T>::z()
{
    return m_z;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Vecteur3DT<T>& v)
{
    os << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ")";
    return os;
}

template <class T>
bool Vecteur3DT<T>::operator==(const Vecteur3DT& v) const
{
    return (m_x == v.m_x && m_y == v.m_y && m_z == v.m_z);
}

template <class T>
bool Vecteur3DT<T>::operator!=(const Vecteur3DT& v) const
{
    return (m_x != v.m_x || m_y != v.m_y || m_z != v.m_z);
}

template <class T>
Vecteur3DT<T> Vecteur3DT<T>::operator+(const Vecteur3DT& v) const
{
    return Vecteur3DT(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);
}

template <class T>
Vecteur3DT<T>& Vecteur3DT<T>::operator+=(const Vecteur3DT& v) {
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
	return *this;
}

template <class T>
Vecteur3DT<T> Vecteur3DT<T>::operator-(const Vecteur3DT& v) const
{
    return Vecteur3DT(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
}

template <class T>
Vecteur3DT<T> Vecteur3DT<T>::operator*(const T n) const
{
    return Vecteur3DT(m_x * n, m_y * n, m_z * n);
}

template <class T>
Vecteur3DT<T> Vecteur3DT<T>::operator*(const Vecteur3DT& v) const
{
    return Vecteur3DT(m_y * v.m_z - m_z * v.m_y, m_z * v.m_x - m_x * v.m_z, m_x * v.m_y - m_y * v.m_x);
}

template <class T>
Vecteur3DT<T>::~Vecteur3DT()
{
}