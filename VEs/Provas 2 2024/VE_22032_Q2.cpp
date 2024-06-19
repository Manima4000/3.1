#include <bits/stdc++.h>

using namespace std;

class Personagem
{
    string nome;
    string classe;
    string saude;

public:
    string getNome() { return nome; }
    string getClasse() { return classe; }
    string getSaude() { return saude; }

    Personagem() {}
    ~Personagem() {}
    Personagem(string nome, string classe, string saude) : nome(nome), classe(classe), saude(saude) {}

    friend ostream &operator<<(ostream &os, const Personagem &p)
    {
        cout << p.nome << " " << p.classe << " " << p.saude << endl;
    }

    bool operator==(Personagem ld)
    {
        if (nome == ld.nome)
            return true;
        else
            return false;
    }

    bool readFromFile(istream &in)
    {
        if (!in)
        {
            cout << "Erro ao abrir o arquivo" << endl;
            return false;
        }
        string linha;
        if (getline(in, linha))
        {
            istringstream ss(linha);
            getline(ss, nome, ',');
            getline(ss, classe, ',');
            getline(ss, saude);
            return true;
        }
    }

    void writeToFile(ostream &on)
    {
        on << nome << "," << classe << "," << saude << endl;
    }
};

vector<Personagem> personagens;

int main()
{
    ifstream file("entrada.txt");
    if (!file)
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }
    while (file)
    {
        Personagem *p = new Personagem;
        if (p->readFromFile(file))
        {
            int count = 0;
            for (int i = 0; i < personagens.size(); i++)
            {
                if (*p == personagens[i])
                    count++;
            }
            if (count == 0)
            {
                personagens.push_back(*p);
            }
        }
        delete p;
    }
    file.close();

    ofstream arquivoSaida("saida.txt");
    if (!arquivoSaida)
    {
        cout << "Errou ao abrir o arquivo" << endl;
        return 1;
    }
    for (int i = 0; i < personagens.size() - 1; i++)
    {
        personagens[i].writeToFile(arquivoSaida);
    }
    arquivoSaida.close();

    for (int i = 0; i < personagens.size(); i++)
        cout << personagens[i] << endl;
    return 0;
}
