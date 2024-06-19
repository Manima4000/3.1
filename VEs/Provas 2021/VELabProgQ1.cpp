#include <bits/stdc++.h>
#include <random>

using namespace std;

class Soldado
{
private:
    string nome;
    float saude;
    float poder_de_ataque;

public:
    Soldado(string nome, float saude, float poder_de_ataque)
    {
        this->nome = nome;
        this->saude = saude;
        this->poder_de_ataque = poder_de_ataque;
    }
    float getSaude() { return saude; }

    float getPoder() { return poder_de_ataque; }

    string getNome() { return nome; }

    void setPoder(float k) { poder_de_ataque = k; }

    void setSaude(float k) { saude = k; }

    void defender(Soldado &sd, float dano)
    {
        sd.saude = sd.saude - dano;
    }

    virtual bool atacar(Soldado &sd)
    {
        float dano = poder_de_ataque;
        defender(sd, dano);
        return true;
    }
};

class Elfo : public Soldado
{
public:
    Elfo(string nome1, float saude1, float poder_de_ataque1) : Soldado(nome1, saude1, poder_de_ataque1 + 1) {}
};

class Anao : public Soldado
{
public:
    Anao(string nome1, float saude1, float poder_de_ataque1) : Soldado(nome1, saude1, poder_de_ataque1 + 20) {}

    bool atacar(Soldado &sd) override
    {
        int valor_aleatorio = rand();
        bool chance_de_ataque = (valor_aleatorio % 10) < 4;
        if (chance_de_ataque)
            return false;
        else
        {
            float dano = getPoder();
            defender(sd, dano);
            return true;
        }
    }
};

class Humano : public Soldado
{
public:
    Humano(string nome1, float saude1, float poder_de_ataque1) : Soldado(nome1, saude1, poder_de_ataque1) {}

    bool atacar(Soldado &sd) override
    {
        float dano = getPoder();
        int valor_aleatorio = rand();
        bool ataque_critico = (valor_aleatorio % 10) < 1;
        if (ataque_critico)
            dano = dano * 2;
        defender(sd, dano);
        return true;
    }
};

class Sauron : public Soldado
{
public:
    Sauron(string nome1, float saude1, float poder_de_ataque1) : Soldado(nome1, saude1 * 10, poder_de_ataque1) {}
    bool atacar(Soldado &sd) override
    {
        float dano = getPoder();
        int valor_aleatorio = rand();
        bool ataque_critico = (valor_aleatorio % 10) <= 3;
        if (ataque_critico)
            dano = dano * 2;
        defender(sd, dano);
        return true;
    }
};

class Orc : public Soldado
{
    Orc(string nome1, float saude1, float poder_de_ataque1) : Soldado(nome1, saude1 * 10, poder_de_ataque1) {}
    bool atacar(Soldado &sd) override
    {
        float dano = getPoder();
        int valor_aleatorio = rand();
        bool ataque_critico = (valor_aleatorio % 10) <= 2;
        if (ataque_critico)
            dano = dano * 2.2;
        defender(sd, dano);
        return true;
    }
};

vector<Soldado> v;

int main()
{

    srand(time(NULL)); // Inicializando os numeros aleatorios
    Soldado sd1("Soldado", 100, 40);
    v.push_back(sd1);

    Anao an1("Anao", 100, 40);
    v.push_back(an1);

    Elfo el1("Elfo", 100, 40);
    v.push_back(el1);

    Humano hm1("Humano", 100, 40);
    v.push_back(hm1);

    Sauron sauron1("Sauron", 100, 40);
    v.push_back(sauron1);

    while (v.size() != 1)
    {
        int i = rand();
        int j = rand();
        int tamanho = v.size();
        if (tamanho == 1)
        {
            break;
        }
        i = i % tamanho;
        j = j % tamanho;
        if (j == i)
            continue;
        else
        {
            v[i].atacar(v[j]);
            cout << v[i].getNome() << " atacou " << v[j].getNome() << ". Ele ainda possui " << v[j].getSaude() << " pontos de vida" << endl;
            if (v[j].getSaude() <= 0)
            {
                cout << "O " << v[j].getNome() << " morreu !" << endl;
                v.erase(v.begin() + j);
            }
        }
    }
    cout << "O " << v[0].getNome() << " venceu !!!!" << endl;
    return 0;
}