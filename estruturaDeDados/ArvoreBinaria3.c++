#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* arv_criavazia(void);
Arv* arv_cria(char c, Arv* e, Arv* d);
void arv_imprime(Arv* a);

int main() {
    system("color f0");

    Arv* a = arv_cria('A',
        arv_cria('B',
            arv_cria('D', arv_criavazia(), arv_criavazia()),
            arv_cria('E', arv_criavazia(), arv_criavazia())
        ),
        arv_cria('C',
            arv_criavazia(),
            arv_cria('F',
                arv_criavazia(),
                arv_cria('H',
                    arv_criavazia(),
                    arv_cria('I', arv_criavazia(), arv_criavazia())
                )
            )
        )
    );

    arv_imprime(a);
    getch();
    return 0;
}

Arv* arv_criavazia(void) {
    return NULL;
}

Arv* arv_cria(char c, Arv* sae, Arv* sad) {
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

void arv_imprime(Arv* a) {
    if (!a)
        return;

    cout << a->info << " ";
    arv_imprime(a->esq);
    arv_imprime(a->dir);
}