#include <bits/stdc++.h>
using namespace std;

class Candidato
{
private:
    string nome;
    string partido;
    int numero;
    int votos;

public:
    Candidato(int numero, string nome, string partido) : numero(numero), nome(nome), partido(partido), votos(0) {}

    string getNome() { return nome; }

    string getPartido() { return partido; }

    int getNumero() { return numero; }

    void IncrementaVoto() { votos++; }

    int getVotos() { return votos; }
};

vector<Candidato> candidatos;

void AbreUrna(string nomearquivo)
{
    ifstream file(nomearquivo);
    if (!file)
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    int voto;
    while (file >> voto)
    {
        for (int i = 0; i < candidatos.size(); i++)
        {
            if (voto == candidatos[i].getNumero() && voto >= 1 && voto <= 20)
                candidatos[i].IncrementaVoto();
            else
            {
                continue;
            }
        }
    }
}

int main()
{
    ifstream file("candidatos.txt");
    if (!file)
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    string linha;
    while (getline(file, linha))
    {
        istringstream iss(linha);
        int numero;
        string nome, partido;

        if (!(iss >> numero >> nome >> partido))
        {
            cerr << "Erro ao ler a linha: " << linha << endl;
            continue; // Pula para a próxima linha em caso de erro
        }

        candidatos.emplace_back(numero, nome, partido);
    }

    file.close();

    AbreUrna("urna1.txt");
    AbreUrna("urna2.txt");
    AbreUrna("urna3.txt");
    AbreUrna("urna4.txt");

    int num = -3;
    string nome1 = "";
    int maxVotos = 0;
    int totalvotos = 0;
    for (int i = 0; i < candidatos.size(); i++)
    {
        totalvotos += candidatos[i].getVotos();
        if (candidatos[i].getVotos() >= maxVotos)
        {
            maxVotos = candidatos[i].getVotos();
            num = candidatos[i].getNumero();
            nome1 = candidatos[i].getNome();

        }
    }

    for (int i = 0; i < candidatos.size(); i++)
    {
        cout << candidatos[i].getNome() << ": " << candidatos[i].getVotos() << endl;
    }

    cout << "\n------VENCEDOR------\n" << nome1 << " !! Com um total de: " << maxVotos << " votos" << endl;

    return 0;
}