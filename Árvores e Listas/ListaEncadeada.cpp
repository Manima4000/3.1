#include <iostream>
using namespace std;

struct NO
{
    int chave;
    NO *prox;
};

class ListaEncadeada
{
public:
    NO *root;
    ListaEncadeada() { root = NULL; }

    NO *busca(int valor)
    {
        if (root == NULL)
            return NULL;
        else
        {
            NO *aux = root;
            while (aux != NULL)
            {
                if (aux->chave == valor)
                    return aux;
                aux = aux->prox;
            }
            return NULL;
        }
    }

    bool inserir(int valor)
    {
        if (root == NULL)
        {
            NO *aux = new NO;
            aux->chave = valor;
            aux->prox = NULL;
            root = aux;
            return true;
        }
        else
        {
            if (busca(valor) != NULL)
                return false;

            NO *aux = root;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            NO *aux2 = new NO;
            aux2->chave = valor;
            aux2->prox = NULL;
            aux->prox = aux2;
            return true;
        }
    }

    bool remover(int valor)
    {
        NO *nodeToRemove = busca(valor);
        if (nodeToRemove == NULL)
            return false;

        if (root->chave == valor)
        {
            NO *temp = root;
            root = root->prox;
            delete temp;
            return true;
        }

        NO *ant = root;
        NO *aux = root->prox;
        while (aux != NULL && aux->chave != valor)
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux == NULL)
        {
            return false;
        }
    
        ant->prox = aux->prox;
        delete aux;
        return true;
    }

    void imprimir()
    {
        if (root == NULL)
            cout << "Lista vazia" << endl;
        else
        {
            NO *aux = root;
            while (aux != NULL)
            {
                cout << aux->chave << " ";
                aux = aux->prox;
            }
            cout << endl;
        }
    }
};

int main()
{
    ListaEncadeada lista;
    lista.inserir(30);
    lista.inserir(35);
    lista.inserir(32);
    lista.imprimir();
    lista.remover(30);
    lista.imprimir();
}