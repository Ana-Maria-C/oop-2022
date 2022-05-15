
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include<stdio.h>
#include<iostream>
#include<string.h>
template<class K, class V>
class Map
{
    struct elem//astea-s publice
    {
        K key;
        V value;
        int index;
    };
    //astea s private
    elem* a = new elem[5];
    int nr = 0;
public:
    elem* begin()
    {
        return &a[0];
    }
    elem* end()
    {
        return &a[nr];
    }
    int Count()
    {
        return nr;
    }
    void Clear()
    {
        nr = 0;
        delete[]a;
    }
    //operatorul []
    V& operator[](K n)
    {
        int i;
        for (i = 0; i < nr; i++)
        {
            if (n == a[i].key)
                return a[i].value;
        }
        a[nr].key = n;
        a[nr].index = nr;
        nr++;
        return a[nr - 1].value;
    }
    void Set(K cheie, V val)
    {
        int ok = 0;
        for (int i = 0; i < nr; i++)
        {
            if (a[i].key == cheie)
            {
                a[i].value = val;
                ok = 1;
            }
        }
        if (ok == 0)
        {
            a[nr].key = cheie;
            a[nr].value = val;
            a[nr].index = nr;
            nr++;
        }
    }
    bool Get(const K& cheie, V& val)
    {
        int ok = 0;
        for (int i = 0; i < nr; i++)
        {
            if (a[i].key == cheie)
            {
                ok = 1;
                val = a[i].value;
            }
            return true;
        }
        return false;
    }
    bool Includes(const Map<K, V>& m)
    {
        int numar = -1;
        for (int i = 0; i < this->nr; i++)
        {
            for (int j = 0; j <= nr; i++)
                if (a[i].key == m.a[i].key)
                    numar++;
        }
        if (numar != nr)
            return true;
        else
            return false;
    }
};
#endif // MAP_H_INCLUDED