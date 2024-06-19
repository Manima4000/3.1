#include <bits/stdc++.h>

using namespace std;

class FuncionarioBase
{
private:
    int id;
    string name;
    double salary;
    string tipo;

public:
    FuncionarioBase(int id1, string name1, double salary1, string tipo1) : id(id1), name(name1), salary(salary1), tipo(tipo1) {}

    ~FuncionarioBase() {}

    int getID() { return id; }

    string getName() { return name; }

    double getSalary() { return salary; }

    string getTipo() { return tipo; }

    void exibirDetalhes()
    {   
        cout << "Detalhes do Funcionario " << getName() << ": " <<endl;
        cout << "ID: " << getID() << "\nNome: " << getName() << "\nSalario: " << getSalary() << "\nTipo: " << getTipo() << "\n" << endl;
    }
};

class Funcionario : public FuncionarioBase
{
public:
    Funcionario(int id1, string name1, double salary1, string tipo) : FuncionarioBase(id1, name1, salary1, tipo) {}

    ~Funcionario() {}
};

class Gerente : public FuncionarioBase
{
private:
    vector<FuncionarioBase> equipe;

public:
    Gerente(int id1, string name1, double salary1) : FuncionarioBase(id1, name1, salary1, "Gerente") {}

    ~Gerente() {}

    bool adicionarFuncioario(FuncionarioBase &p)
    {
        if (equipe.size() >= 10)
        {
            cout << "Não eh possivel adicionar a equipe" << endl;
            return false;
        }
        if (p.getTipo() == "Gerente")
        {
            cout << "Não eh possivel um Gerente a sua equipe" << endl;
            return false;
        }
        else
        {
            equipe.push_back(p);
        }
    }

    void MostrarTime()
    {
        if (equipe.size() == 0)
        {
            cout << "Não ha ninguem na equipe" << endl;
            return;
        }
        cout << "----EQUIPE----\n"
             << endl;
        for (auto it = equipe.begin(); it != equipe.end(); it++)
        {
            it->exibirDetalhes();
            cout << endl;
        }
        cout << "---------------" << endl;
        return;
    }

    double SalarioTotal()
    {
        double sal = getSalary();
        for (auto it = equipe.begin(); it != equipe.end(); it++)
        {
            sal += it->getSalary();
        }
        return sal;
    }
};

int main()
{
    Gerente g1(1, "Matheus", 2000);
    Gerente g2(2, "Andrade", 3000);
    Funcionario f1(101, "Bruno", 500, "Vendedor");
    Funcionario f2(102, "Wilmer", 700, "RH");
    Funcionario f3(103, "Lobao", 700, "Gerente"); 
    g1.adicionarFuncioario(f1);
    g1.adicionarFuncioario(f2);
    g1.adicionarFuncioario(f3); // Tentando adicionar um Funcionario com tipo Gerente
    cout << g1.SalarioTotal() << endl;
    ;
    g1.MostrarTime();
    g1.exibirDetalhes();
    return 0;
}