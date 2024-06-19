#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

enum Resultado_atual {Continua, Vitoria_Jogador_1, Vitoria_Jogador_2, Empate};

class Lig4
{
private:
    const int m; // Travando as dimensões do tabuleiro
    const int n;
    int vez;
    int pontuacao1;
    int pontuacao2;
protected:
    char **tab;
    
    void incrementaPontuacao1() { pontuacao1++; }

    void incrementaPontuacao2() { pontuacao2++; }

    void alternarVez() { vez++; }

    void setPontuacao1(int k) { pontuacao1 = k; }

    void setPontuacao2(int k) { pontuacao2 = k; }

    void contaSeq4Horizontal(char c)
    { // Caso de sequencia na horizontal
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 3; j++)
            {
                if ((tab[i][j] == c) && (tab[i][j + 1] == c) && (tab[i][j + 2] == c) && (tab[i][j + 3] == c))
                {
                    if (c == 'X')
                        incrementaPontuacao1();
                    if (c == 'O')
                        incrementaPontuacao2();
                }
            }
        }
    }

    void contaSeq4Vertical(char c)
    { // Caso de sequencia na vertical
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m - 3; i++)
            {
                if ((tab[i][j] == c) && (tab[i + 1][j] == c) && (tab[i + 2][j] == c) && (tab[i + 3][j] == c))
                {
                    if (c == 'X')
                        incrementaPontuacao1();
                    if (c == 'O')
                        incrementaPontuacao2();
                }
            }
        }
    }

    void contaDiagonal1(char c)
    { // Caso de sequencia numa diagonal descendente
        for (int i = 0; i < m - 3; i++)
        {
            for (int j = 0; j < n - 3; j++)
            {
                if ((tab[i][j] == c) && (tab[i + 1][j + 1] == c) && (tab[i + 2][j + 2] == c) && (tab[i + 3][j + 3] == c))
                {
                    if (c == 'X')
                        incrementaPontuacao1();
                    if (c == 'O')
                        incrementaPontuacao2();
                }
            }
        }
    }

    void contaDiagonal2(char c)
    { // Caso de sequencia numa diagonal ascendente
        for (int i = 3; i < m; i++)
        {
            for (int j = 0; j < n - 3; j++)
            {
                if ((tab[i][j] == c) && (tab[i - 1][j + 1] == c) && (tab[i - 2][j + 2] == c) && (tab[i - 3][j + 3] == c))
                {
                    if (c == 'X')
                        incrementaPontuacao1();
                    if (c == 'O')
                        incrementaPontuacao2();
                }
            }
        }
    }

public:
    int getPontuacao1() { return pontuacao1; }

    int getPontuacao2() { return pontuacao2; }

    Lig4(int m1, int n1) : m(m1), n(n1), vez(1), pontuacao1(0), pontuacao2(0)
    {
        tab = new char *[m]; // Inicializando a matriz
        for (int i = 0; i < m; ++i)
        {
            tab[i] = new char[n];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tab[i][j] = '.'; // Colocando todos os elementos = '.'
            }
        }
    }

    ~Lig4()
    {
        // Liberando a memoria alocada da matriz
        for (int i = 0; i < m; i++)
            delete tab[i];
        delete[] tab;
    }

    void exibir()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << tab[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "\n\n"
             << endl;
    }

    bool jogadaValida(int col)
    {
        if (col < 0 || col >= n)
        { // Caso escolha uma coluna não existente
            cout << "Jogada Invalida" << endl;
            return false;
        }

        if (tab[0][col] != '.')
        { // Caso a coluna esteja cheia
            cout << "Jogada Invalida" << endl;
            return false;
        }
        return true;
    }

    bool jogar()
    {
        int col;
        cout << "Escolha um coluna para realizar a jogada: ";
        cin >> col;
        if (jogadaValida(col))
        {
            int contador = 0; // contador de qual linha está
            for (int i = 0; i < m; i++)
            {
                if (tab[i][col] != '.')
                { // Caso ja tenha acontecido jogadas nessa coluna
                    if (vez % 2 == 1)
                    { // Vez do jogador 1
                        tab[i - 1][col] = 'X';
                        alternarVez();
                        break;
                    }
                    if (vez % 2 == 0)
                    { // Vez do jogador 2
                        tab[i - 1][col] = 'O';
                        alternarVez();
                        break;
                    }
                }
                contador += 1; // Incrementando a linha
            }
            if (contador == m)
            { // Caso seja a primeira jogada nessa coluna
                if (vez % 2 == 1)
                {
                    tab[m - 1][col] = 'X';
                    alternarVez();
                }
                else
                {
                    tab[m - 1][col] = 'O';
                    alternarVez();
                }
            }
            return true;
        }
        return false;
    }

    virtual bool fimDeJogo()
    {
        int contador = 0; // Conta quantas jogadas já foram feitas
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tab[i][j] != '.')
                    contador++;
            }
        }
        if (contador == m * n)
        {
            cout << "O jogo terminou !!" << endl;
            contaSeq4Horizontal('X');
            contaSeq4Horizontal('O');
            contaSeq4Vertical('X');
            contaSeq4Vertical('O');
            contaDiagonal1('X');
            contaDiagonal1('O');
            contaDiagonal2('X');
            contaDiagonal2('O');
            cout << "Pontuacao do Jogador1: " << getPontuacao1() << endl;
            cout << "Pontuacao do Jogador2: " << getPontuacao2() << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void gerenciar()
    {
        exibir();
        while (!fimDeJogo())
        {
            jogar();
            exibir();
        }
        setPontuacao1(0);
        setPontuacao2(0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tab[i][j] = '.'; // Colocando todos os elementos = '.'
            }
        }
    }
};

class Lig4Tradicional : public Lig4
{
public:
    Lig4Tradicional() : Lig4(7, 6) {} // construtor tradicional

    ~Lig4Tradicional()
    {
        // Liberando a memoria alocada da matriz
        for (int i = 0; i < 6; i++)
            delete tab[i];
        delete[] tab;
    }

    bool fimDeJogo () override
    {
        int contador = 0; // Conta quantas jogadas já foram feitas
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (tab[i][j] != '.')
                    contador++;
            }
        }
        contaSeq4Horizontal('X');
        contaSeq4Horizontal('O');
        contaSeq4Vertical('X');
        contaSeq4Vertical('O');
        contaDiagonal1('X');
        contaDiagonal1('O');
        contaDiagonal2('X');
        contaDiagonal2('O');
        if (getPontuacao1() == 1){
            cout << "Jogador 1 venceu !!" << endl;
            return Vitoria_Jogador_1;
        }
        if (getPontuacao2() == 1){
            cout << "Jogador 2 venceu !!" << endl;
            return Vitoria_Jogador_2;
        }
        if (contador == 7*6)
        {
            cout << "Empate" << endl;
            return Empate;
        }

        return Continua;
    }
};

int main()
{
    Lig4Tradicional jogo;
    jogo.gerenciar();
    return 0;
}