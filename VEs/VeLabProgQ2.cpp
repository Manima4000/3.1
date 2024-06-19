#include <bits/stdc++.h>

using namespace std;

class Forca
{
    int const numero_tentativas;
    int tentativas_atual;
    vector<string> palavras;
    string palavra_atual;
    vector<char> letras_usadas;
    string palavra_em_contrucao;

public:
    Forca(vector<string> palavras1) : palavras(palavras1), numero_tentativas(10), tentativas_atual(10) {}

    ~Forca() {}

    void show()
    {
        for (auto it = palavras.begin(); it != palavras.end(); it++)
            cout << *it << endl;
    }

    void iniciar()
    {
        if (palavras.size() == 0)
            cout << "Não há mais palavras" << endl;
        else
        {
            tentativas_atual = numero_tentativas;
            int i = rand();
            i = i % palavras.size();
            palavra_atual = palavras[i];
            palavra_em_contrucao = "";
            for (int i = 0; i < palavra_atual.size(); i++)
            {
                palavra_em_contrucao.append("_");
            }
            letras_usadas.clear();
            palavras.erase(palavras.begin() + i);
        }
    }

    void mostrar()
    {
        for (int i = 0; i < palavra_atual.size(); i++)
        {
            auto it = find(letras_usadas.begin(), letras_usadas.end(), palavra_atual[i]);
            if (it != letras_usadas.end())
                cout << palavra_atual[i] << " ";
            else
                cout << "_ ";
        }
        cout << "\nVidas restantes: " << tentativas_atual << endl;
    }

    bool jogar()
    {
        char k;
        cout << "Escolha uma letra: ";
        cin >> k;
        auto it = find(letras_usadas.begin(), letras_usadas.end(), k);
        if (it != letras_usadas.end())
        {
            cout << "Letra ja utilizada" << endl;
            return false;
        }
        auto it1 = find(palavra_atual.begin(), palavra_atual.end(), k);
        if (it1 == palavra_atual.end())
        {
            tentativas_atual--;
        }
        for (int i = 0; i < palavra_atual.size(); i++)
        {
            if (palavra_atual[i] == k)
                palavra_em_contrucao[i] = k;
        }
        letras_usadas.push_back(k);
        return true;
    }

    bool fimDeJogo()
    {
        if ((palavra_em_contrucao == palavra_atual) && tentativas_atual > 0)
        {
            cout << "VITORIA" << endl;
            return true;
        }
        if (tentativas_atual <= 0)
        {
            cout << "DERROTA" << endl;
            return true;
        }
        return false;
    }
};

int main()
{
    srand(time(NULL));
    Forca f1({"macaco", "arara", "quati", "leao", "vaca"});
    f1.iniciar();
    f1.mostrar();
    while (!f1.fimDeJogo())
    {
        f1.jogar();
        f1.mostrar();
    }
    return 0;
}