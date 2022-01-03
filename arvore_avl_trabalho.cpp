#include <bits/stdc++.h>

using namespace std;

typedef int tipochave;

typedef struct aux {
    tipochave chave;
    int fb;
    aux *esq, *dir;
} no;

typedef no* pont;

pont criaArvore()
{
    return 0;
}

/*
    Percorre a árvore seguindo o caminho definido pelas
    regras de inserção (valores menores a esquerda do nó
    e maiores a direita). Quando encontra um espaco vazio
    efetua a inserção.
    Obs.: Ao invés de utilizar o tipo no** a função recebe
    em p uma referência (ponteiro indireto) ao endereço do
    nó de chamada.
 */
void inserir(pont &p, tipochave c)
{
    if (!p) {
        p = new no;
        p->chave = c;
        p->esq = 0;
        p->dir = 0;
    } else {
        if (c < p->chave)
            inserir(p->esq, c);
        else
            inserir(p->dir, c);
    }
}

void mostra(pont p)
{
    if (p) {
        cout << p->chave;
        cout << '(';
            mostra(p->esq);
            mostra(p->dir);
        cout << ')';
    }
}

void mostraSimetrica(pont p)
{
    if (p) {
        cout << '(';
            mostraSimetrica(p->esq);
            cout << p->chave;
            mostraSimetrica(p->dir);
        cout << ')';
    }
}

void mostraPos(pont p)
{
    if (p) {
        cout << '(';
            mostraPos(p->esq);
            mostraPos(p->dir);
        cout << ')';
        cout << p->chave;
    }
}

void funcMostraHorizontal(pont arv, bool *mapa, int nivel = 0, bool esq = true)
{
    if (arv) {
        mapa[nivel] = true; // Define que a linha deste nível deve ser escrita

        if (nivel) // Vai para o nó da esquerda (e verifica se  da esquerda), então desbilita a linha anterior
            mapa[nivel-1] = (esq) ? false : true;

        funcMostraHorizontal(arv->esq, mapa, nivel+1, true);

        cout << left;

        // Exibe as linhas antes do nó
        for (int i = 0; i < nivel; i++)
        {
            cout.width(4);
            if (i < nivel-1) {
                cout << (mapa[i] ? '|' : ' ');
            } else {
                cout.fill('-');
                cout << '+';
                cout.fill(' ');
            }
        }

        // Exibe o nó
        cout << arv->chave << " fb(" << arv->fb << ")" << endl;

        if (nivel)
            mapa[nivel-1] = (!esq) ? false : true;

        funcMostraHorizontal(arv->dir, mapa, nivel+1, false);
    }
}

void mostraHorizontal(pont arv) {
    bool mapa[255] = {};
    funcMostraHorizontal(arv, mapa);
}

bool remover(pont &p, tipochave n)
{
    // Caso o nó não seja encontrado
    if (!p)
        return false;

    // Percorre a árvore em busca do nó
    if (n < p->chave)
        remover(p->esq, n);
    else if (n > p->chave)
        remover(p->dir, n);

    else
    {
        // Guardamos o nó encontrado em aux
        pont aux = p;

        /*
            O nó p é o que desejamos remover, ele é filho de um nó
            pai e por isso atribuimos null a ele antes de desalocar
            o espaço de memória.
         */

        if (!p->esq && !p->dir) {

            // Remoção de um nó folha
            p = 0;
            delete aux;

        } else if (!p->esq || !p->dir) {

            // Caso haja só um filho
            if (p->esq)
                p = p->esq;
            else
                p = p->dir;

            delete aux;

        } else {

            // Troca a chave do nó buscado e apaga o nó que substiui

            pont paiAux = p;
            aux = paiAux->dir;

            while (aux->esq) {
                paiAux = aux;
                aux = aux->esq;
            }

            if (paiAux->chave == n)
                paiAux->dir = aux->dir;
            else
                paiAux->esq = aux->dir;

            p->chave = aux->chave; // Troca a chave

            delete aux; // Libera a memória do endereço do nó

        }
    }
    return true;
}

/*
    Percorre todos od nós da árvore de forma recursiva.
    Começa a limpar a memória quando encontra um nó nulo.
    Retorna nullptr pois é preciso remover a referência do
    ponteiro daquele endereço.
    e.g. Quando se limpa o nó armazenado em p:
        p = limpa(p);
 */
pont limpar(pont &raiz)
{
    if (!raiz)
        return 0;

    raiz->esq = limpar(raiz->esq);
    raiz->dir = limpar(raiz->dir);

    delete raiz;
    return 0;
}

int contarNos(pont raiz)
{
    if (!raiz)
        return 0;

    return contarNos(raiz->esq) + 1 + contarNos(raiz->dir);
}

/*
    A peculiariedade da função altura é precisar comparar a altura
    da subárvore da esquerda e da direita, e ver qual das duas é a
    maior. Isso ocorre pois a altura da árvore se dá pela maior
    ditância de um nó folha até a raiz.
 */

int altura(pont raiz)
{
    if (!raiz)
        return -1;

    int esq, dir;

    esq = altura(raiz->esq);
    dir = altura(raiz->dir);

    if (esq > dir)
        return 1 + esq;
    else
        return 1 + dir;
}

int fatorBalanceamento(pont raiz)
{
    return altura(raiz->esq) - altura(raiz->dir);
}

void atualizaFB(pont g)
{
    if (g) {
        g->fb = fatorBalanceamento(g);
        atualizaFB(g->esq);
        atualizaFB(g->dir);
    }
}

// Funcões da árvore AVL

pont rotacionarEsqEsq(pont p)
{
    pont temp = p;
    pont esq = temp->esq;

    temp->esq = esq->dir;
    esq->dir = temp;

    return esq;
}

pont rotacionarEsqDir(pont p)
{
    pont temp = p;
    pont esq = temp->esq;
    pont dir = esq->dir;

    temp->esq = dir->dir;
    esq->dir = dir->esq;
    dir->esq = esq;
    dir->dir = temp;

    return dir;
}

pont rotacionarDirEsq(pont p)
{
    pont temp = p;
    pont dir = temp->dir;
    pont esq = dir->esq;

    temp->dir = esq->esq;
    dir->esq = esq->dir;
    esq->dir = dir;
    esq->esq = temp;

    return esq;
}

pont rotacionarDirDir(pont p)
{
    pont temp = p;
    pont dir = temp->dir;

    temp->dir = dir->esq;
    dir->esq = temp;

    return dir;
}

pont balancear(pont p)
{
    if (!p)
        return 0;

    pont balanceado = 0;
    if (p->esq)
        p->esq = balancear(p->esq);

    if (p->dir)
        p->dir = balancear(p->dir);

    int fator = p->fb;
    if (fator >= 2) {
        if (p->dir->fb <= -1)
            balanceado = rotacionarEsqDir(p);
        else
            balanceado = rotacionarEsqEsq(p);

    } else if (fator <= -2) {
        if (p->dir->fb >= 1)
            balanceado = rotacionarDirEsq(p);
        else
            balanceado = rotacionarDirDir(p);
    } else {
        balanceado = p;
    }

    return balanceado;
}

int main() {
    pont arv = criaArvore();
    int menu = -1;
    tipochave v;

    do {
        system("cls");
        cout << "0: Sair" << endl;
        cout << "1: Inserir" << endl;
        cout << "2: Mostrar" << endl;
        cout << "3: Excluir" << endl;
        cout << "4: Podar Arvore (Limpar)" << endl;
        cout << "5: Contar numero de nos" << endl;
        cout << "6: Altura da arvore" << endl;
        cin >> menu;
        fflush(stdin);

        switch (menu)
        {
        case 0:
            cout << "Programa finalizado." << endl;
            system("pause");
            break;

        case 1:
            cout << "Informe o valor a ser inserido: ";
            cin >> v;
            inserir(arv, v);
            atualizaFB(arv);
            arv = balancear(arv);
            atualizaFB(arv);
            break;

        case 2:
            cout << "1: Prefixada" << endl;
            cout << "2: Simetrica" << endl;
            cout << "3: Posfixada" << endl;
            cout << "4: Horizontal" << endl;
            cin >> menu;
            fflush(stdin);

            if (!arv) {
                cout << "Arvore Vazia" << endl;
                cout << endl;
            } else {
                cout << "Elementos da Arvore: ";
                switch (menu)
                {
                case 1:
                    mostra(arv);
                    break;

                case 2:
                    mostraSimetrica(arv);
                    break;

                case 3:
                    mostraPos(arv);
                    break;

                case 4:
                    cout << endl;
                    mostraHorizontal(arv);
                    break;

                default:
                    mostra(arv);
                    break;
                }
                cout << endl;
            }

            menu = 2;
            system("pause");
            break;

        case 3:
            cout << "Informe o valor a ser removido: ";
            cin >> v;
            fflush(stdin);

            if (remover(arv, v)) {
                cout << "Valor removido com sucesso." << endl;
                atualizaFB(arv);
                arv = balancear(arv);
                atualizaFB(arv);
            } else {
                cout << "Valor nao encontrado." << endl;
            }

            system("pause");
            break;

        case 4:
            arv = limpar(arv);
            cout << "Arvore limpa com sucesso." << endl;
            system("pause");
            break;

        case 5:
            cout << "A arvore possui " << contarNos(arv) << " no(s)." << endl;
            system("pause");
            break;

        case 6:
            cout << "A arvore possui altura " << altura(arv) << '.' << endl;
            system("pause");
            break;

        default:
            break;
        }
    } while (menu);

    return 0;
}
