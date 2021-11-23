#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include "TVector.h"

template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
    explicit TMatrix(int s = 10);
    TMatrix(const TMatrix &mt);                    // копирование
    TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
    bool operator==(const TMatrix &mt) const;      // сравнение
    bool operator!=(const TMatrix &mt) const;      // сравнение
    TMatrix& operator= (const TMatrix &mt);        // присваивание
    TMatrix  operator+ (const TMatrix &mt);        // сложение
    TMatrix  operator- (const TMatrix &mt);        // вычитание

    // ввод / вывод
    friend std::istream& operator>>(std::istream &in, TMatrix &mt)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TMatrix &mt)
    {
        for (int i = 0; i < mt.Size; i++)
            out << mt.pVector[i] << std::endl;
        return out;
    }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
    if(s < 0)
    {
        throw std::logic_error("INCORRECT SIZE");
    }
    for (int i = 0; i < s; i++)
    {
        this->pVector[i] = TVector<ValType>(s - i, i);
    }
}

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
        TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
        TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
    return TVector<TVector<ValType>>::operator==(mt);
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
    return !(*this == mt);
}

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
    TVector<TVector<ValType>>::operator=(mt);
    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
    return TVector<TVector<ValType>>::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
    return TVector<TVector<ValType>>::operator-(mt);
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif