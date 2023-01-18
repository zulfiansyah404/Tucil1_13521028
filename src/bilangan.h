#include <bits/stdc++.h>

#ifndef _BILANGAN_H
#define _BILANGAN_H

typedef struct
{
    int pembilang;
    int penyebut;
} bil;

int lcm(int x, int y)
{
    return (x * y) / __gcd(x, y);
}

void simpleFraction(bil *a)
{
    int fpb = __gcd((*a).pembilang, (*a).penyebut);
    (*a).pembilang /= fpb;
    (*a).penyebut /= fpb;
}

bil operasi(char opr, bil angka1, bil angka2)
{
    bil ans;

    if (opr == '*')
    {
        ans.pembilang = angka1.pembilang * angka2.pembilang;
        ans.penyebut = angka1.penyebut * angka2.penyebut;
    }
    else if (opr == '/')
    {
        ans.pembilang = angka1.pembilang * angka2.penyebut;
        ans.penyebut = angka1.penyebut * angka2.pembilang;
    }
    else
    {
        if (angka1.penyebut != angka2.penyebut)
        {
            int kpk = lcm(angka1.penyebut, angka2.penyebut);
            angka1.pembilang = angka1.pembilang * kpk / angka1.penyebut;
            angka2.pembilang = angka2.pembilang * kpk / angka2.penyebut;
            angka1.penyebut = kpk;
            angka2.penyebut = kpk;
        }

        if (opr == '+')
            ans.pembilang = angka1.pembilang + angka2.pembilang;
        else
            ans.pembilang = angka1.pembilang - angka2.pembilang;
        ans.penyebut = angka1.penyebut;
    }
    return ans;
}

#endif