#include <bits/stdc++.h>

using namespace std;

class Cont
{
private:
    static int contado;

public:
    Cont()
    {
        contado++;
    }

    ~Cont()
    {
        contado--;
    }

    static void imprimir()
    {
        cout << "Existem " << contado << " objetos no programa" << endl;
    }
};

int Cont::contado = 0;

class Funcionario
{
    const string nome;
    double salario;
    int ramal;
    static int counter;

public:
    Funcionario(string nome, double salario, int ramal) : nome(nome), salario(salario), ramal(ramal)
    {
        counter++;
        if (counter > 50 || counter < 10)
        {
            cout << "Quantidade de funcionario crítica: " << counter << endl;
        }
    }

    ~Funcionario()
    {
        counter--;
        if (counter > 50 || counter < 10)
        {
            cout << "Quantidade de funcionario crítica: " << counter << endl;
        }
    }

    string getNome() { return nome; }

    double getSalario() { return salario; }

    int getRamal() { return ramal; }

    static int FuncCont() { return counter; }
};

int Funcionario::counter = 0;

int main()
{
    /*Cont m, m2, m3, m6;
    Cont::imprimir();
    delete &m;
    Cont::imprimir();
    delete &m2;
    Cont::imprimir();
    */

    Funcionario *e[100];
    for (int i = 0; i < 20; i++)
    {
        e[i] = new Funcionario("Empregado " + to_string(i), 100 * i, i);
    }
    cout << Funcionario::FuncCont() << endl;
    cout << e[2]->getNome() << endl;
    for (int i = 0; i < 20; i++)
    {
        delete e[i];
    }
}