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

    bool remover_e_arrumar(NO *root2)
    {
        if (max_subarv_esq(root2) != NULL)
        {
            NO *aux = root2->esq;
            if (aux == max_subarv_esq(root2))
            {
                root2->esq = aux->esq;
                root2->chave = max_subarv_esq(root2)->chave;
                return true;
            }
            while (aux->dir != max_subarv_esq(root2))
            {
                aux = aux->dir;
            }
            root2->chave = max_subarv_esq(root2)->chave;
            aux->dir = max_subarv_esq(root2)->esq;
            return true;
        }

        if (min_subarv_dir(root2) != NULL)
        {
            NO *aux = root2->dir;
            if (aux == min_subarv_dir(root2))
            {
                root2->chave = min_subarv_dir(root2)->chave;
                root2->dir = aux->dir;
                return true;
            }
            while (aux->esq != min_subarv_dir(root2))
            {
                aux = aux->esq;
            }
            root2->chave = min_subarv_dir(root2)->chave;
            aux->esq = min_subarv_dir(root2)->dir;
            return true;
        }
    }

public:
    ArvoreBinariaDeBusca() { root = NULL; }

    NO *busca(int valor)
    {
        if (root == NULL)
            return NULL;

        NO *aux = root;
        while (aux->chave != valor && aux != NULL)
        {
            if (aux->chave < valor)
                aux = aux->dir;
            else
                aux = aux->esq;
        }
        if (aux == NULL)
            return NULL;
        else
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
            root == aux;
            return true;
        }

        else
        {
            NO *pai = root;
            while (busca(valor) == NULL)
            {
                if (pai->chave < valor && pai->dir != NULL)
                    pai = pai->dir;
                if (pai->chave > valor && pai->esq != NULL)
                    pai = pai->esq;
                if (pai->chave < valor && pai->dir == NULL)
                {
                    pai->dir = aux;
                    return true;
                }
                if (pai->chave > valor && pai->esq == NULL)
                {
                    pai->esq = aux;
                    return true;
                }
            }
            return false;
        }
    }

    bool remover(int valor)
    {
        NO *NoRemover = busca(valor);
        if (NoRemover == NULL)
            return false;
        if (NoRemover != root)
        {
            remover_e_arrumar(NoRemover);
        }
        // Falta o caso do NoRemover é raiz
    }

    void simetrico(NO *atual)
    {
        if (atual != NULL)
        {
            simetrico(atual->esq);
            cout << atual->chave << " ";
            simetrico(atual->dir);
        }
    }

    void imprimir()
    {
        simetrico(root);
    }
};

int main()
{
    ArvoreBinariaDeBusca tree;
    tree.inserir(30);
    tree.inserir(50);
    tree.imprimir();
}