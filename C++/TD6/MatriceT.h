#ifndef __MatriceT_H__
#define __MatriceT_H__
#include <iostream>
template <class T>
class MatriceT
{
public:
    MatriceT();
    MatriceT(const MatriceT& mat);
    MatriceT(const int& nb_ligne, const int& nb_colonne, const T tab[]);
    MatriceT(const int& nb_ligne, const int& nb_colonne);

    void affiche();
    const int& getValue(const int& ligne, const int& colonne);
    void setValue(const int& ligne, const int& colonne, const T& value);
    const int& getNbColonne() const;
    const int& getNbLigne() const;
    void affectation(const MatriceT& mat);
    bool egal(const MatriceT& mat) const;
    T& value(const int& ligne, const int& colonne);
    bool different(const MatriceT& mat) const;
    void multiplication(const T& facteur);
    void addition(const MatriceT& m, const MatriceT& m2);
    void soustraction(const MatriceT& m, const MatriceT& m2);
    void multiplication(const MatriceT& m, const MatriceT& m2);

    T* operator[](const int& nb) const;
    template <class T>
    friend std::ostream& operator<<(std::ostream& os, const MatriceT<T>& m);
    bool operator==(const MatriceT& mat) const;
    bool operator!=(const MatriceT& mat) const;
    MatriceT& operator=(const MatriceT& mat);
    MatriceT operator*(const T& facteur);
    MatriceT operator+(const MatriceT& m);
    MatriceT operator-(const MatriceT& m);
    MatriceT operator*(const MatriceT& m);

    ~MatriceT();

private:
    T** m_mat;
    int m_nbLigne;
    int m_nbColonne;
};
#include "MatriceT.inl"
#endif