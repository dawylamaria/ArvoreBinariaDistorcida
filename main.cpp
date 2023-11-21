#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

void preOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        cout << raiz->data << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

bool arvoreDistorcida(NoArvore* raiz) {
    if (raiz == NULL) {
        return false;  
    } else {
        if ((raiz->esquerda == NULL && raiz->direita != NULL) || (raiz->esquerda != NULL && raiz->direita == NULL)) {
            return true;  
        } else {
            return arvoreDistorcida(raiz->esquerda) || arvoreDistorcida(raiz->direita);  
        }
    }
}

int main() {
    NoArvore* raiz = new NoArvore;
    raiz->data = 1;
    
    raiz->esquerda = new NoArvore;
    raiz->esquerda->data = 2;
    
    raiz->esquerda->esquerda = new NoArvore;
    raiz->esquerda->esquerda->data = 4;
    raiz->esquerda->esquerda->esquerda = NULL;
    raiz->esquerda->esquerda->direita = NULL;
    raiz->esquerda->direita = NULL;
    

    cout << "Arvore distorcida: ";
    preOrdem(raiz);
    cout << endl;

    cout << "A arvore eh distorcida? " << arvoreDistorcida(raiz) << endl;

    delete raiz->esquerda->esquerda->esquerda;
    delete raiz->esquerda->esquerda;
    delete raiz->esquerda;
    delete raiz;

    return 0;
}

