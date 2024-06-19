#include <bits/stdc++.h>

using namespace std;

vector<string> alunos;
map<string,vector<float>> alunos_e_notas;
map<string,float> alunos_e_medias;

bool leitura_arquivo_alunos(string arquivo)
{
    ifstream file(arquivo);
    if (!file)
    {
        cout << "Não foi possivel abrir o arquivo" << endl;
        return false;
    }
    string linha;
    while (getline(file, linha))
    {
        istringstream iss(linha);
        string nome;
        if (!(iss >> nome))
        {
            cout << "Não foi possivel ler a linha" << endl;
            continue;
        }
        alunos.push_back(nome);
    }
    file.close();
}

bool leitura_notas_aluno()
{
    vector<string> arquivo_notas_alunos;
    for (int i = 0; i < alunos.size(); i++)
    {
        arquivo_notas_alunos.push_back(alunos[i] + ".txt");
    }

    for (int i = 0; i < arquivo_notas_alunos.size(); i++)
    {
        vector<float> *notas_por_aluno = new vector<float>;
        ifstream file(arquivo_notas_alunos[i]);
        if (!file)
        {
            cout << "Não foi possivel abrir o arquivo" << endl;
            return false;
        }
        string linha;
        while(getline(file,linha))
        {
            istringstream iss(linha);
            float nota;
            if (!(iss >> nota))
            {
                cout << "Não foi possivel ler a linha" << endl;
                continue;
            }
            notas_por_aluno->push_back(nota);
        }
        alunos_e_notas[alunos[i]] = *notas_por_aluno;
        delete notas_por_aluno;
    }
    return true;
}

void leitura_map_alunos_notas()
{
    for (map<string, vector<float>>::iterator it = alunos_e_notas.begin(); it != alunos_e_notas.end(); ++it) {
        cout << it->first << ": ";
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }
}

float calculo_media(vector<float> vetor)
{
    float soma = accumulate(vetor.begin(),vetor.end(),0.0f);
    float media = soma/(vetor.size());
    return media;
}

void imprimir_alunos_e_media()
{   
    float Maxmedia = 0;
    string nomeMaiorMedia;
    for (map<string, vector<float>>::iterator it = alunos_e_notas.begin(); it != alunos_e_notas.end(); ++it)
    {
        alunos_e_medias[it->first] = calculo_media(it->second);
        cout << it->first << ": " << alunos_e_medias[it->first] << endl;
        if (calculo_media(it->second) > Maxmedia)
            Maxmedia = calculo_media(it->second);
            nomeMaiorMedia = it->first;
    }
    cout << "O Aluno com maior media eh " << nomeMaiorMedia << " com um valor de " << Maxmedia << endl;
}




int main()
{
    leitura_arquivo_alunos("alunos.txt");
    leitura_notas_aluno();
    leitura_map_alunos_notas();
    imprimir_alunos_e_media();
    return 0;
}