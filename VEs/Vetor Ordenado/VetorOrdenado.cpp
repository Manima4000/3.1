#include <bits/stdc++.h>

using namespace std;

class vetorOrdenado
{
    int capacidade;
    int tamanho;
    vector<int> vetor;

    public:
    vetorOrdenado(int n): capacidade(n),tamanho(0) {leitura_arquivo();}

    int getTamanho() {return tamanho;}

    bool leitura_arquivo()
    {
        ifstream file("valores.txt");
        if (!file)
        {
            cout << "Erro ao abrir o arquivo" << endl;
            return false;
        }
        string linha;
        if(getline(file,linha));
        {
            stringstream ss(linha);
            string item;
            while(getline(ss,item,','))
            {
                if (vetor.size() < capacidade)
                {
                    vetor.push_back(stoi(item)); //converter string pra inteiro
                    tamanho++;
                }
            }
        }

    }

    friend ostream& operator<<(ostream& os, const vetorOrdenado &vec)
    {
        for (int i = 0; i < vec.tamanho; i++)
            os << vec.vetor[i] << " ";
        os << endl;
        return os;
    }

    int operator+(int numero)
    {
        auto it = find(vetor.begin(),vetor.end(),numero);
        if (it != vetor.end())
            return distance(vetor.begin(),it);
        return -1;
    }

    int operator-(int numero)
    {
        return count_if(vetor.begin(),vetor.end(),[numero](int x) {return x < numero;});
    }

};

int main()
{
    vetorOrdenado caralho(10);
    cout << caralho;
    cout << caralho + 6 << endl;
    cout << caralho - 65;
}