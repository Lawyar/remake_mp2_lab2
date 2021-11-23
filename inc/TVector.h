#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>

template <class ValType>
class TVector
{
protected:
    ValType *pVector;
    int Size{};       // размер вектора
    int StartIndex{}; // индекс первого элемента вектора
public:
    explicit TVector(int size = 10, int start_index = 0);
    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    int GetSize() const     { return Size;       } // размер вектора
    int GetStartIndex() const { return StartIndex; } // индекс первого элемента
    ValType& operator[](int pos);             // доступ
    bool operator==(const TVector<ValType> &v) const;  // сравнение
    bool operator!=(const TVector<ValType> &v) const;  // сравнение
    TVector<ValType>& operator=(const TVector &v);     // присваивание

    // скалярные операции
    TVector  operator+(const ValType &val);   // прибавить скаляр
    TVector  operator-(const ValType &val);   // вычесть скаляр
    TVector  operator*(const ValType &val);   // умножить на скаляр

    // векторные операции
    TVector  operator+(const TVector<ValType> &v);     // сложение
    TVector  operator-(const TVector<ValType> &v);     // вычитание
    ValType  operator*(const TVector<ValType> &v);     // скалярное произведение

    // ввод-вывод
    friend std::istream& operator>>(std::istream &in, TVector &v)
    {
        for (int i = 0; i < v.Size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
    {
        for (int i = 0; i < v.Size; i++)
            out << v.pVector[i] << ' ';
        return out;
    }
};

template<class ValType>
TVector<ValType>::TVector(int size, int start_index)
{
    if(size < 0 || start_index < 0)
    {
        throw std::logic_error("INCORRECT SIZE OR START INDEX");
    }
    Size = size;
    StartIndex = start_index;
    pVector = new ValType[Size];
}

template<class ValType>
TVector<ValType>::TVector(const TVector<ValType> &v)
{
    Size = v.GetSize();
    StartIndex = v.GetStartIndex();
    pVector = new ValType[Size];

    for(int i = StartIndex; i < Size; i++)
    {
        pVector[i] = v.pVector[i];
    }
}

template<class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
}

template<class ValType>
ValType &TVector<ValType>::operator[](int pos)
{
    if(pos - StartIndex < 0 || pos - StartIndex >= Size)
    {
        throw std::logic_error("INCORRECT POSITION");
    }
    return pVector[pos - StartIndex];
}

template<class ValType>
bool TVector<ValType>::operator==(const TVector<ValType> &v) const
{
    if(Size != v.GetSize())
    {
        return false;
    }

    for(int i = StartIndex; i < Size; i++)
    {
        if(pVector[i] != v.pVector[i])
        {
            return false;
        }
    }
    return true;
}

template<class ValType>
bool TVector<ValType>::operator!=(const TVector<ValType> &v) const
{
    if(Size != v.GetSize())
    {
        return true;
    }

    for(int i = StartIndex; i < Size; i++)
    {
        if(pVector[i] != v.pVector[i] && pVector[i] && v.pVector[i])
        {
            return true;
        }
    }
    return false;
}

template<class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
    if(this != &v)
    {
        Size = v.GetSize();
        StartIndex = v.GetStartIndex();
        delete[] pVector;
        pVector = new ValType[Size];

        for(int i = StartIndex; i < Size; i++)
        {
            pVector[i] = v.pVector[i];
        }
    }

    return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
    TVector<ValType> res = *this;
    for(int i = StartIndex; i < Size; i++)
    {
        res[i] = pVector[i] + val;
    }
    return res;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
    TVector<ValType> res = *this;
    for(int i = StartIndex; i < Size; i++)
    {
        res[i] = pVector[i] - val;
    }
    return res;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
    TVector<ValType> res = *this;
    for(int i = StartIndex; i < Size; i++)
    {
        res[i] = pVector[i] * val;
    }
    return res;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
    if(Size != v.GetSize())
    {
        throw std::logic_error("SCALAR operations are not possible when vectors have different sizes");
    }

    TVector<ValType> res(v);
    for(int i = StartIndex; i < Size; i++)
    {
        res[i] = res[i] + pVector[i];
    }
    return res;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
    if(Size != v.GetSize())
    {
        throw std::logic_error("SCALAR operations are not possible when vectors have different sizes");
    }

    TVector<ValType> res(*this);
    for(int i = StartIndex; i < Size; i++)
    {
        res[i] = res[i] - v.pVector[i];
    }
    return res;
}

template<class ValType>
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
    ValType res = 0;

    if(Size != v.GetSize())
    {
        throw std::logic_error("SCALAR operations are not possible when vectors have different sizes");
    }

    for(int i = StartIndex; i < Size; i++)
    {
        res = res + pVector[i] * v.pVector[i];
    }
    return res;
}


#endif