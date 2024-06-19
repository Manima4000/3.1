#include <bits/stdc++.h>

using namespace std;

class SabreDeLuz
{
    int tamanho;
    string cor;
    int energia;
    string dono;

public:
    SabreDeLuz(int tam, string c, string j) : tamanho(tam), cor(c), dono(j)
    {
        if (j == "jedi")
            energia = 105;
        if (j == "sith")
            energia = 100;
    }

    ~SabreDeLuz() {}

    SabreDeLuz(SabreDeLuz &sabre) : tamanho(sabre.tamanho), cor(sabre.cor), energia(sabre.energia), dono(sabre.dono) {}

    SabreDeLuz() {}

    void setEnergia(int k) { energia = k; }
    void setTamanho(int k) { tamanho = k; }

    SabreDeLuz operator+(SabreDeLuz &ld)
    {
        int tamanho3 = tamanho + ld.tamanho;
        int energia3 = energia + ld.energia;
        string cor3;
        if (cor.find(ld.cor) == string::npos)
            cor3 = cor + "," + ld.cor;
        else
        {
            cor3 = cor;
        }
        string dono3;
        if (dono == ld.dono && dono == "sith")
        {
            dono3 = "sith";
        }
        else
        {
            dono3 = "jedi";
        }
        SabreDeLuz *sabre3 = new SabreDeLuz(tamanho3, cor3, dono3);
        sabre3->setEnergia(energia3);

        return *sabre3;
    }

    SabreDeLuz operator*(SabreDeLuz &ld)
    {
        int sabre1 = energia * tamanho;
        int sabre2 = (ld.energia) * (ld.tamanho);
        if (sabre1 >= sabre2)
        {
            int novaenergia = 0.9 * energia;
            int novotamanho;
            if (dono == "sith")
                novotamanho = 0.9 * tamanho;
            if (dono == "jedi")
            {
                novotamanho = 0.95 * tamanho;
            }
            SabreDeLuz *sabre3 = new SabreDeLuz(*this);
            sabre3->setEnergia(novaenergia);
            sabre3->setTamanho(novotamanho);
            return *sabre3;
        }
        else
        {
            int novaenergia = 0.9 * ld.energia;
            int novotamanho;
            if (ld.dono == "sith")
                novotamanho = 0.9 * ld.tamanho;
            if (ld.dono == "jedi")
            {
                novotamanho = 0.95 * ld.tamanho;
            }
            SabreDeLuz *sabre3 = new SabreDeLuz(ld);
            sabre3->setEnergia(novaenergia);
            sabre3->setTamanho(novotamanho);
            return *sabre3;
        }
    }

    friend ostream &operator<<(ostream &os, const SabreDeLuz &s)
    {
        os << "Tamanho: " << s.tamanho << "\nCor: " << s.cor << "\nEnergia: " << s.energia << "\nDono: " << s.dono << endl;
        return os;
    }

    friend istream &operator>>(istream &is, SabreDeLuz &s)
    {
        is >> s.tamanho >> s.cor >> s.dono;
    }

    operator int()
    {
        return energia;
    }

    operator string()
    {
        return cor;
    }
};

int main()
{
    SabreDeLuz sabre(150, "vermelho", "jedi");
    SabreDeLuz sabre2(120, "verde", "sith");
    SabreDeLuz sabre3;
    sabre3 = sabre + sabre2 + sabre;
    cout << sabre3;
    cout << endl;
    SabreDeLuz sabre4;
    sabre4 = sabre * sabre2;
    cout << sabre4 << endl;
    cout << (int)sabre4 << " " << (string)sabre4 << endl;
    SabreDeLuz sabre5;
    sabre5 = sabre2 * sabre3;
    cout << sabre5 << endl;
    return 0;
}