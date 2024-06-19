#include <iostream>

using namespace std;

struct NO
{
    int chave;
    NO *dir;
    NO *esq;
};

class ArvoreBinariaDeBusca
{
private:
    NO *root;

    NO *max_subarv_esq(NO *root_s)
    {
        NO *aux = root_s->esq;
        if (aux == NULL)
            return NULL;
        while (aux->dir != NULL)
            aux = aux->dir;
        return aux;
    }

    NO *min_subarv_dir(NO *root_s)
    {
        NO *aux = root_s->dir;
        if (aux == NULL)
            return NULL;
        while (aux->esq != NULL)
            aux = aux->esq;
        return aux;
    }

    bool remover(int valor, NO *&no, NO *pai)
    {
        if (no == NULL)
            return false;
        if (valor < no->chave)
            return remover(valor, no->esq, no);
        else if (valor > no->chave)
            return remover(valor, no->dir, no);
        else
        {
            if (no->esq == NULL || no->dir == NULL)
            {
                NO *temp = no->esq ? no->esq : no->dir;
                if (temp == NULL)
                {
                    temp = no;
                    no = NULL;
                }
                else
                    *no = *temp;
                delete temp;
            }
            else
            {
                NO *temp = min_subarv_dir(no);
                no->chave = temp->chave;
                remover(temp->chave, no->dir, no);
            }
            return true;
        }
    }

    void imprimirSimetrico(NO *no)
    {
        if (no == NULL)
            return;
        imprimirSimetrico(no->esq);
        cout << no->chave << " ";
        imprimirSimetrico(no->dir);
    }

    void imprimirPreOrdem(NO *no)
    {
        if (no == NULL)
            return;
        cout << no->chave << " ";
        imprimirPreOrdem(no->esq);
        imprimirPreOrdem(no->dir);
    }

public:
    ArvoreBinariaDeBusca()
    {
        root = NULL;
    }

    NO *busca(int valor)
    {
        NO *aux = root;
        while (aux != NULL && aux->chave != valor)
        {
            if (valor < aux->chave)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        return aux;
    }

    bool inserir(int valor)
    {
        NO *aux = new NO;
        aux->chave = valor;
        aux->dir = NULL;
        aux->esq = NULL;

        if (root == NULL)
        {
            root = aux;
            return true;
        }

        NO *pai = root;
        while (true)
        {
            if (valor < pai->chave)
            {
                if (pai->esq == NULL)
                {
                    pai->esq = aux;
                    return true;
                }
                else
                {
                    pai = pai->esq;
                }
            }
            else if (valor > pai->chave)
            {
                if (pai->dir == NULL)
                {
                    pai->dir = aux;
                    return true;
                }
                else
                {
                    pai = pai->dir;
                }
            }
            else
            {
                delete aux;
                return false; // valor já existe na árvore
            }
        }
    }

    bool remover(int valor)
    {
        return remover(valor, root, NULL);
    }

    void imprimir()
    {
        cout << "Ordem Simetrica: " << endl;
        imprimirSimetrico(root);
        cout << "\nPre Ordem: " << endl;
        imprimirPreOrdem(root);
        cout << endl;
    }
};

int main()
{
    ArvoreBinariaDeBusca arvore;

    arvore.inserir(50);
    arvore.inserir(30);
    arvore.inserir(20);
    arvore.inserir(40);
    arvore.inserir(70);
    arvore.inserir(60);
    arvore.inserir(80);
    arvore.inserir(20);

    arvore.imprimir();

    cout << "\nRemover 20\n";
    arvore.remover(20);
    arvore.imprimir();

    cout << "\nRemover 30\n";
    arvore.remover(30);
    arvore.imprimir();

    cout << "\nRemover 50\n";
    arvore.remover(50);
    arvore.imprimir();

    return 0;
}