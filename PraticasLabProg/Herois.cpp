#include <bits/stdc++.h>
using namespace std;
// class Aluno{
//     string nome;
//     public:
//         Aluno (string nome1):nome(nome1){}
//         Aluno(){}
//         void SetNome(string nome1){
//             this->nome = nome1;
//         }
//         ~Aluno(){}
// };

// int main(){
//     int **p = new int*[10];
//     for (int i = 0; i<10; i++)
//         p[i] = new int[10];

//     for (int i = 0; i<10; i++)
//         for (int j = 0; j<10; j++)
//             p[i][j] = i+j;

//     for (int i = 0; i<10; i++)
//         for (int j = 0; j<10; j++)
//             cout << p[i][j] << endl;

//     for (int i = 0; i<10; i++)
//         delete[] p[i];
//     delete p;

//     Aluno *vet = new Aluno[10];
//     for (int i =0; i<10; i++){
//         vet[i].SetNome("João");
//     }
//     delete[] vet;
//     return 0;
// }

class SuperPoder
{
    string nome;
    int categoria;

public:
    SuperPoder(string nome1, int categoria1) : nome(nome1), categoria(categoria1) {}
    string getNome()
    {
        return nome;
    }
    int getCategoria()
    {
        return categoria;
    }
};

class Personagem
{
    string nome;
    string nomeVidaReal;
    SuperPoder **poderes;
    int nPoderes;

public:
    Personagem(string nome, string nomeVidaReal)
    {
        this->nome = nome;
        this->nomeVidaReal = nomeVidaReal;
        poderes = new SuperPoder *[4];
        nPoderes = 0;
    }

    Personagem(const Personagem &p)
    { // Construtor por cópia
        nome = p.nome;
        nomeVidaReal = p.nomeVidaReal;
        poderes = new SuperPoder *[4];
        nPoderes = p.nPoderes;
        for (int i = 0; i < nPoderes; i++)
        {
            poderes[i] = p.poderes[i];
        }
    }

    bool adicionaSuperPoder(SuperPoder &sp)
    {
        if (nPoderes >= 4)
            return false;
        poderes[nPoderes] = &sp;
        nPoderes++;
        return true;
    }

    ~Personagem()
    {
        delete[] poderes;
    }

    SuperPoder **getVector()
    {
        return poderes;
    }

    int getNPoderes() { return nPoderes; }

    double getPoderTotal()
    {
        int k = 0;
        for (int i = 0; i < nPoderes; i++)
        {
            k += poderes[i]->getCategoria();
        }
        return k;
    }

    string getNome() { return nome; }
};

class Heroi : public Personagem
{
public:
    Heroi(string nome, string nomeVidaReal) : Personagem(nome, nomeVidaReal)
    {
    }
    double getPoderTotal()
    {
        return 1.1 * Personagem::getPoderTotal();
    }
};

class Vilao : public Personagem
{
private:
    int tempoDePrisao;

public:
    Vilao(string nome, string nomeReal, int tempo) : Personagem(nome, nomeReal)
    {
        tempoDePrisao = tempo;
    }
    double getPoderTotal()
    {
        double b = 1 + ((double)tempoDePrisao) / 100;
        return b * Personagem::getPoderTotal();
    }
};

class Confronto
{
public:
    string enfrentar(Heroi &p1, Vilao &p2)
    {
        if (p1.getPoderTotal() > p2.getPoderTotal())
        {
            return p1.getNome();
        }
        if (p1.getPoderTotal() < p2.getPoderTotal())
        {
            return p2.getNome();
        }
        return "Empate";
    }
};

int main()
{
    SuperPoder s1("soltar teia", 3);
    SuperPoder s2("andar em paredes", 2);
    SuperPoder s3("sentido apurado", 1);
    SuperPoder s4("velocidade", 5);
    SuperPoder s5("Voar", 3);
    SuperPoder s6("força", 5);
    SuperPoder s7("visão de raio X", 4);
    SuperPoder s8("sopro congelante", 4);
    SuperPoder s9("supersoldado", 3);
    SuperPoder s10("escudo", 3);
    SuperPoder s11("anel magico", 5);
    SuperPoder s12("armadura", 4);
    SuperPoder s13("dispositivos eletronicos", 2);
    SuperPoder s14("mente aguçada", 5);
    SuperPoder s15("tentáculos indestrutíveis", 5);
    SuperPoder s16("velocidade", 1);

    Heroi ha("Homem-Aranha", "Peter Park");
    Heroi sh("Super-Homem", "Clark Kent");
    Heroi ca("Capitão América", "Steven Rogers");
    Heroi fl("Flash", "Barry Allen");
    Heroi lv("Lanterna-Verde", "Hal Jordan");
    Heroi hf("Homem de Ferro", "Tony Stark");

    Vilao dv("Duende Verde", "Norman Osbourne", 3);
    Vilao ll("Lex Luthor", "Lex Luthor", 5);
    Vilao bi("Bizarro", "Bizarro", 11);
    Vilao oc("Octopus", "Otto Octavius", 4);

    ha.adicionaSuperPoder(s1);
    ha.adicionaSuperPoder(s2);
    ha.adicionaSuperPoder(s3);

    sh.adicionaSuperPoder(s5);
    sh.adicionaSuperPoder(s6);
    sh.adicionaSuperPoder(s7);
    sh.adicionaSuperPoder(s8);

    ca.adicionaSuperPoder(s9);
    ca.adicionaSuperPoder(s10);

    fl.adicionaSuperPoder(s4);

    lv.adicionaSuperPoder(s11);

    hf.adicionaSuperPoder(s12);
    hf.adicionaSuperPoder(s13);

    dv.adicionaSuperPoder(s6);

    ll.adicionaSuperPoder(s14);

    bi.adicionaSuperPoder(s5);
    bi.adicionaSuperPoder(s6);
    bi.adicionaSuperPoder(s7);
    bi.adicionaSuperPoder(s8);

    oc.adicionaSuperPoder(s15);
    oc.adicionaSuperPoder(s16);

    Vilao viloes[4] = {dv, ll, bi, oc};
    Heroi herois[6] = {ha, sh, ca, fl, lv, hf};

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
        {
            cout << herois[i].getNome();
            cout << " X ";
            cout << viloes[j].getNome();
            cout << " -> ";

            cout << Confronto().enfrentar(herois[i], viloes[j]) << endl;
        }
}
