#include "iostream"
template <class T>
MatriceT<T>::MatriceT() : m_mat(new T* [1]), m_nbLigne(1), m_nbColonne(1)
{
    this->m_mat[0] = new T[1];
    this->m_mat[0][0] = T();
}

template <class T>
MatriceT<T>::MatriceT(const MatriceT& mat) : m_nbLigne(mat.m_nbLigne), m_nbColonne(mat.m_nbColonne)
{
    this->m_mat = new T * [this->m_nbLigne];
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        this->m_mat[i] = new T[this->m_nbColonne];
    }
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            this->m_mat[i][j] = mat.m_mat[i][j];
        }
    }
}

template <class T>
MatriceT<T>::MatriceT(const int& nbLigne, const int& nbColonne) : m_nbLigne(nbLigne), m_nbColonne(nbColonne)
{
    this->m_mat = new T * [nbLigne];
    for (int i = 0; i < nbLigne; ++i)
    {
        this->m_mat[i] = new T[nbColonne];
    }
    for (int i = 0; i < nbLigne; ++i)
    {
        for (int j = 0; j < nbColonne; ++j)
        {
            m_mat[i][j] = T();
        }
    }
}

template <class T>
MatriceT<T>::MatriceT(const int& nbLigne, const int& nbColonne, const T tab[]) : m_nbLigne(nbLigne), m_nbColonne(nbColonne)
{
    this->m_mat = new T * [nbLigne];
    int cpt = 0;
    for (int i = 0; i < nbLigne; ++i)
    {
        this->m_mat[i] = new T[nbColonne];
    }
    for (int i = 0; i < nbLigne; ++i)
    {
        for (int j = 0; j < nbColonne; ++j)
        {
            this->m_mat[i][j] = tab[cpt++];
        }
    }
}

template <class T>
void MatriceT<T>::affiche()
{
    std::cout << "Matrice:" << std::endl;
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            std::cout << this->m_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <class T>
const int& MatriceT<T>::getValue(const int& ligne, const int& colonne)
{
    return this->m_mat[ligne][colonne];
}

template <class T>
void MatriceT<T>::setValue(const int& ligne, const int& colonne, const T& value)
{
    this->m_mat[ligne][colonne] = value;
}

template <class T>
const int& MatriceT<T>::getNbColonne() const
{
    return this->m_nbColonne;
}

template <class T>
const int& MatriceT<T>::getNbLigne() const
{
    return this->m_nbLigne;
}

template <class T>
void MatriceT<T>::affectation(const MatriceT& mat)
{
    this->m_nbColonne = mat.m_nbColonne;
    this->m_nbLigne = mat.m_nbLigne;
    this->m_mat = new T * [this->m_nbLigne];
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        this->m_mat[i] = new T[this->m_nbColonne];
    }
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            this->m_mat[i][j] = mat.m_mat[i][j];
        }
    }
}

template <class T>
bool MatriceT<T>::egal(const MatriceT& mat) const
{
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            if ((this->m_mat[i][j] - mat.m_mat[i][j] != 0) && (mat.m_mat[i][j] - this->m_mat[i][j] != 0))
                return false;
        }
    }
    return true;
}

template <class T>
T& MatriceT<T>::value(const int& ligne, const int& colonne)
{
    return this->m_mat[ligne][colonne];
}

template <class T>
bool MatriceT<T>::different(const MatriceT& mat) const
{
    return !egal(mat);
}

template <class T>
void MatriceT<T>::multiplication(const T& facteur)
{
    MatriceT<T> result = Matrice(this->m_nbLigne, this->m_nbColonne);
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            result.setValue(i, j, this->m_mat[i][j] * facteur);
        }
    }
    this->affectation(result);
}

template <class T>
void MatriceT<T>::addition(const MatriceT& m, const MatriceT& m2)
{
    MatriceT<T> result = Matrice(m.m_nbLigne, m.m_nbColonne);
    for (int i = 0; i < m.m_nbLigne; ++i)
    {
        for (int j = 0; j < m.m_nbColonne; ++j)
        {
            result.setValue(i, j, m.m_mat[i][j] + m2.m_mat[i][j]);
        }
    }
    this->affectation(result);
}

template <class T>
void MatriceT<T>::soustraction(const MatriceT& m, const MatriceT& m2)
{
    MatriceT<T> result = Matrice(m.m_nbLigne, m.m_nbColonne);
    for (int i = 0; i < m.m_nbLigne; ++i)
    {
        for (int j = 0; j < m.m_nbColonne; ++j)
        {
            result.setValue(i, j, m.m_mat[i][j] - m2.m_mat[i][j]);
        }
    }
    this->affectation(result);
}

template <class T>
void MatriceT<T>::multiplication(const MatriceT& m, const MatriceT& m2)
{
    // First multiple
    MatriceT<T> result = Matrice(m.m_nbLigne, m2.m_nbColonne);
    for (int i = 0; i < m.m_nbLigne; ++i)
    {
        for (int j = 0; j < m2.m_nbColonne; ++j)
        {
            for (int k = 0; k < m.m_nbColonne; ++k)
            {
                result.m_mat[i][j] += m.m_mat[i][k] * m2.m_mat[k][j];
            }
        }
    }
    this->affectation(result);
}

template <class T>
T* MatriceT<T>::operator[](const int& nb) const
{
    return this->m_mat[nb];
}

template <class T>
std::ostream& operator<<(std::ostream& os, const MatriceT<T>& m)
{
    os << "MatriceT<T>:" << std::endl;
    for (int i = 0; i < m.getNbLigne(); ++i)
    {
        for (int j = 0; j < m.getNbColonne(); ++j)
        {
            os << m[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

template <class T>
bool MatriceT<T>::operator==(const MatriceT& mat) const
{
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            if ((this->m_mat[i][j] != mat.m_mat[i][j]))
                return false;
        }
    }
    return true;
}

template <class T>
bool MatriceT<T>::operator!=(const MatriceT& mat) const
{
    return !(*this == mat);
}

template <class T>
MatriceT<T>& MatriceT<T>::operator=(const MatriceT& mat)
{
    this->m_nbColonne = mat.m_nbColonne;
    this->m_nbLigne = mat.m_nbLigne;
    this->m_mat = new T * [this->m_nbLigne];
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        this->m_mat[i] = new T[this->m_nbColonne];
    }
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            this->m_mat[i][j] = mat.m_mat[i][j];
        }
    }
    return *this;
}

template <class T>
MatriceT<T> MatriceT<T>::operator*(const T& facteur)
{
    MatriceT<T> result = MatriceT(this->m_nbLigne, this->m_nbColonne);
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            result.setValue(i, j, this->m_mat[i][j] * facteur);
        }
    }
    return result;
}

template <class T>
MatriceT<T> MatriceT<T>::operator+(const MatriceT& m)
{
    MatriceT<T> result = MatriceT(this->m_nbLigne, this->m_nbColonne);
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            result.setValue(i, j, this->m_mat[i][j] + m.m_mat[i][j]);
        }
    }
    return result;
}

template <class T>
MatriceT<T> MatriceT<T>::operator-(const MatriceT& m)
{
    MatriceT<T> result = MatriceT(this->m_nbLigne, this->m_nbColonne);
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < this->m_nbColonne; ++j)
        {
            result.setValue(i, j, this->m_mat[i][j] - m.m_mat[i][j]);
        }
    }
    return result;
}

template <class T>
MatriceT<T> MatriceT<T>::operator*(const MatriceT& m)
{
    // First multiple
    MatriceT<T> result = MatriceT(this->m_nbLigne, m.m_nbColonne);
    for (int i = 0; i < this->m_nbLigne; ++i)
    {
        for (int j = 0; j < m.m_nbColonne; ++j)
        {
            for (int k = 0; k < this->m_nbColonne; ++k)
            {
                result.m_mat[i][j] += this->m_mat[i][k] * m.m_mat[k][j];
            }
        }
    }
    return result;
}

template <class T>
MatriceT<T>::~MatriceT()
{

    for (int i = 0; i < this->m_nbLigne; i++)
    {
        delete[] m_mat[i];
    }
    delete[] m_mat;
    this->m_mat = NULL;
}