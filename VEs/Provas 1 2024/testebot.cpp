#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

enum Resultado_atual { Continua, Vitoria_Jogador_1, Vitoria_Jogador_2, Empate };

class Lig4 {
private:
    const int m;
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

    void VerificaPontuacao(char c) {
        // Caso de sequencia na horizontal
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 3; j++) {
                if ((tab[i][j] == c) && (tab[i][j + 1] == c) && (tab[i][j + 2] == c) && (tab[i][j + 3] == c)) {
                    if (c == 'X')
                        incrementaPontuacao1();
                    if (c == 'O')
                        incrementaPontuacao2();
                }
            }
        }

        // Caso de sequencia na vertical
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m - 3; i++) {
                if ((tab[i][j] == c) && (tab[i + 1][j] == c) && (tab[i + 2][j] == c) && (tab[i + 3][j] == c)) {
                    if (c == 'X')
                        incrementaPontuacao1();
                    if (c == 'O')
                        incrementaPontuacao2();
                }
            }
        }

        // Caso de sequencia na diagonal descendente
        for (int i = 0; i < m - 3; i++) {
            for (int j = 0; j < n - 3; j++) {
                if ((tab[i][j] == c) && (tab[i + 1][j + 1] == c) && (tab[i + 2][j + 2] == c) && (tab[i + 3][j + 3] == c)) {
                    if (c == 'X')
                        incrementaPontuacao1();
                    if (c == 'O')
                        incrementaPontuacao2();
                }
            }
        }

        // Caso de sequencia na diagonal ascendente
        for (int i = 3; i < m; i++) {
            for (int j = 0; j < n - 3; j++) {
                if ((tab[i][j] == c) && (tab[i - 1][j + 1] == c) && (tab[i - 2][j + 2] == c) && (tab[i - 3][j + 3] == c)) {
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

    Lig4(int m1, int n1) : m(m1), n(n1), vez(1), pontuacao1(0), pontuacao2(0) {
        tab = new char *[m];
        for (int i = 0; i < m; ++i) {
            tab[i] = new char[n];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = '.';
            }
        }
    }

    ~Lig4() {
        for (int i = 0; i < m; i++) {
            delete[] tab[i];
        }
        delete[] tab;
    }

    void exibir() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << tab[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "\n\n" << endl;
    }

    bool jogadaValida(int col) {
        if (col < 0 || col >= n) {
            return false;
        }
        if (tab[0][col] != '.') {
            return false;
        }
        return true;
    }

    bool jogar(int col) {
        if (jogadaValida(col)) {
            for (int i = m - 1; i >= 0; i--) {
                if (tab[i][col] == '.') {
                    tab[i][col] = (vez % 2 == 1) ? 'X' : 'O';
                    alternarVez();
                    return true;
                }
            }
        }
        return false;
    }

    void desfazerJogada(int col) {
        for (int i = 0; i < m; i++) {
            if (tab[i][col] != '.') {
                tab[i][col] = '.';
                alternarVez();
                break;
            }
        }
    }

    Resultado_atual fimDeJogo() {
        VerificaPontuacao('X');
        VerificaPontuacao('O');
        if (getPontuacao1() >= 1) {
            return Vitoria_Jogador_1;
        }
        if (getPontuacao2() >= 1) {
            return Vitoria_Jogador_2;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (tab[i][j] == '.') {
                    return Continua;
                }
            }
        }
        return Empate;
    }

    void gerenciar() {
        srand(time(0));  // Inicializa a semente do gerador de números aleatórios
        exibir();
        while (fimDeJogo() == Continua) {
            if (vez % 2 == 1) {
                int melhorColuna = melhorJogada(5);  // Profundidade 5 para o minimax
                jogar(melhorColuna);
                cout << "Jogador 1 (Bot) jogou na coluna " << melhorColuna + 1 << endl;
            } else {
                int col;
                do {
                    col = rand() % 7;  // Jogada aleatória entre as 7 colunas
                } while (!jogadaValida(col));
                jogar(col);
                cout << "Jogador 2 jogou na coluna " << col + 1 << endl;
            }
            exibir();
        }

        Resultado_atual resultado = fimDeJogo();
        if (resultado == Vitoria_Jogador_1) {
            cout << "Jogador 1 venceu !!" << endl;
        } else if (resultado == Vitoria_Jogador_2) {
            cout << "Jogador 2 venceu !!" << endl;
        } else {
            cout << "Empate" << endl;
        }
        resetarTabuleiro();
    }

    void resetarTabuleiro() {
        vez = 1;
        setPontuacao1(0);
        setPontuacao2(0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = '.';
            }
        }
    }

    int melhorJogada(int profundidade);
    int minimax(int profundidade, bool isMaximizingPlayer);
    int avaliar();
};

class Lig4Tradicional : public Lig4 {
public:
    Lig4Tradicional() : Lig4(6, 7) {}
};

int Lig4::avaliar() {
    VerificaPontuacao('X');
    VerificaPontuacao('O');
    int score = getPontuacao1() - getPontuacao2();
    setPontuacao1(0);
    setPontuacao2(0);
    return score;
}

int Lig4::minimax(int profundidade, bool isMaximizingPlayer) {
    Resultado_atual resultado = fimDeJogo();
    if (resultado != Continua || profundidade == 0) {
        return avaliar();
    }

    if (isMaximizingPlayer) {
        int maxEval = INT_MIN;
        for (int col = 0; col < n; col++) {
            if (jogadaValida(col)) {
                jogar(col);
                int eval = minimax(profundidade - 1, false);
                desfazerJogada(col);
                maxEval = max(maxEval, eval);
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (int col = 0; col < n; col++) {
            if (jogadaValida(col)) {
                jogar(col);
                int eval = minimax(profundidade - 1, true);
                desfazerJogada(col);
                minEval = min(minEval, eval);
            }
        }
        return minEval;
    }
}

int Lig4::melhorJogada(int profundidade) {
    int melhorValor = INT_MIN;
    int melhorColuna = -1;

    for (int col = 0; col < n; col++) {
        if (jogadaValida(col)) {
            jogar(col);
            int moveValue = minimax(profundidade - 1, false);
            desfazerJogada(col);

            if (moveValue > melhorValor) {
                melhorValor = moveValue;
                melhorColuna = col;
            }
        }
    }
    return melhorColuna;
}


int main() {
    int partidas_jogadas = 0;
    Lig4Tradicional jogo;
    while (true) {
        jogo.gerenciar();
        partidas_jogadas++;
        cout << "Partidas jogadas: " << partidas_jogadas << endl;

        Resultado_atual resultado = jogo.fimDeJogo();
        if (resultado == Vitoria_Jogador_2 || jogo.getPontuacao2() >= 1) {
            cout << "Jogador 2 venceu uma partida!!" << endl;
            break;
        }

        jogo.resetarTabuleiro();
        
    }
    return 0;
}