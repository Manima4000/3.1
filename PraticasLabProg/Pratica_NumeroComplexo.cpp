#include <bits/stdc++.h>

using namespace std;

class NumeroComplexo
{
    float a, b;

public:
    NumeroComplexo(float a, float b) : a(a), b(b) {}
    NumeroComplexo() {}
    ~NumeroComplexo() {}

    float getA() { return a; }
    float getB() { return b; }

    void imprimir()
    {
        cout << a << " + " << b << "i" << endl;
    }

    float modulo()
    {
        return sqrt(a * a + b * b);
    }

    NumeroComplexo operator++()
    {
        ++a;
        return *this;
    }

    NumeroComplexo operator+(NumeroComplexo ld)
    {
        return NumeroComplexo(a+ld.a,b+ld.b);
    }

    bool operator!()
    {
        if (a == 0 && b == 0)
            return false;
        return true;
    }

    NumeroComplexo operator=(NumeroComplexo ld)
    {
        a = ld.a;
        b = ld.b;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const NumeroComplexo &c)
    {
        os << c.a << " + " << c.b << "i";
        return os;
    }

    friend istream& operator>>(istream& is, NumeroComplexo &c)
    {
        is >> c.a >> c.b;
        return is;
    }
};

int main()
{
    NumeroComplexo numero1(3, 4);
    NumeroComplexo numero2(4,3);
    cout << numero1 << endl;
    ++numero1;
    NumeroComplexo numero3 = numero1+numero2;
    cout << numero3 << endl;
    NumeroComplexo numero4;
    cin >> numero4;
    cout << numero4;
    return 0;
}