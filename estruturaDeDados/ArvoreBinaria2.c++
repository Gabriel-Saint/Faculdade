#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct arv{
       char info; //tem que alterar a info para int
       struct arv* esq;
       struct arv* dir;
};
//declarando o tipo struct 
typedef struct arv Arv;
//protótipo cria uma árvore vazia
Arv* arv_criavazia(void);
//cria uma árvore com a informação do nó raiz c, e 
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria(char c, Arv* e, Arv* d);
//retorna true se a árvore estiver vazia e 
//false caso contrário
int arv_vazia(Arv* a);
//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera(Arv* a);
//indica ocorrência (1) ou não (0) do caracter c
int arv_pertence(Arv* a, char c);
//imprime informações dos nós da árvore
void arv_imprime(Arv* a);
void arv_preordem(Arv* a);
void arv_inordem(Arv* a);
void arv_posordem(Arv* a);
int max2(int a, int b);
int arv_altura(Arv* a);

main(){
/*
//EXERCÍCIO 3 - CRIANDO A ÁRVORE DO EXERCÍCIO
//subárvore 18
Arv* a1 = arv_cria(18, arv_criavazia(), arv_criavazia());
//subárvore 14
Arv* a2 = arv_cria(14, arv_criavazia(), a1);
//subárvore 18
Arv* a3 = arv_cria(18, arv_criavazia(), arv_criavazia());
//subárvore 16
Arv* a4 = arv_cria(16, a2, a3);
//subárvore 26
Arv* a5 = arv_cria(26, arv_criavazia(), arv_criavazia());
//subárvore 33
Arv* a6 = arv_cria(33, arv_criavazia(), arv_criavazia());
//subárvore 28
Arv* a7 = arv_cria(28, a5, a6);
//subárvore 25
Arv* a8 = arv_cria(25, a4, a7);
//subárvore 30
Arv* a9 = arv_cria(30, arv_criavazia(), arv_criavazia());
//subárvore 42
Arv* a10 = arv_cria(42, arv_criavazia(), arv_criavazia());
//subárvore 40
Arv* a11 = arv_cria(40, a9, a10);
//subárvore 51
Arv* a12 = arv_cria(51, arv_criavazia(), arv_criavazia());
//subárvore 55
Arv* a13 = arv_cria(55, arv_criavazia(), arv_criavazia());
//subárvore 53
Arv* a14 = arv_cria(53, a12, a13);
//subárvore 50
Arv* a15 = arv_cria(50, a11, a14);
//árvore a
Arv* a = arv_cria(34, a8, a15);
*/
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
    
                       

//mostrando a árvore montada
arv_imprime(a);
cout << "\tArvore montada."; 
//mostrando pré-ordem
cout << "\n";
arv_preordem(a);
cout << "\tArvore pre-ordem.";    
//mostrando in-ordem
cout << "\n";   
arv_inordem(a);
cout << "\tArvore in-ondem."; 
//mostrando pós-ordem
cout << "\n";   
arv_posordem(a);
cout << "\tArvore pos-ordem."; 
cout << "\nAltura da arvore: " << arv_altura(a);

getch();       
}
//função cria uma árvore vazia
Arv* arv_criavazia(void){
     return NULL;
}
//função que cria uma árvore com a informação do nó raiz c, 
//e com subárvore esquerda e e subárvore direita d
Arv* arv_cria(char c, Arv* sae, Arv* sad){
     Arv* p=(Arv*)malloc(sizeof(Arv));
     p->info = c;
     p->esq = sae;
     p->dir = sad;
     return p;
}
//função arv_vazia que retorna true se a árvore  
//estiver vazia e false caso contrário
int arv_vazia(Arv* a){    
    return a==NULL;
}
//função que libera o espaço de memória ocupado pela árvore a
Arv* arv_libera(Arv* a){
     if (!arv_vazia(a)){
        arv_libera(a->esq); //libera sae
        arv_libera(a->dir); //libera sad
        free(a); //libera raiz
     }
     return NULL;     
}
//função que indica ocorrência (1) ou não (0) do caracter c
int arv_pertence(Arv* a, char c){
    if (arv_vazia(a)){
       return 0; //árvore vazia, não encontrou
    }
    else{
       return a->info==c ||
       arv_pertence(a->esq, c) ||
       arv_pertence(a->dir, c);        
    }
}
//função que imprime informações dos nós da árvore
void arv_imprime(Arv* a){
     if (!arv_vazia(a)){
        cout << a->info << " "; //mostra a raiz
        arv_imprime(a->esq); //mostra sae
        arv_imprime(a->dir); //mostra sad
     }
}

//função que imprime informações dos nós da árvore - pré-ordem
void arv_preordem(Arv* a){
     if (!arv_vazia(a)){
        cout << a->info << " "; //mostra a raiz
        arv_preordem(a->esq); //mostra sae
        arv_preordem(a->dir); //mostra sad
     }
}
//função que imprime informações dos nós da árvore - in-ordem
void arv_inordem(Arv* a){
     if (!arv_vazia(a)){
        arv_inordem(a->esq); //mostra sae                        
        cout << a->info << " "; //mostra a raiz
        arv_inordem(a->dir); //mostra sad
     }
}
//função que imprime informações dos nós da árvore - pós-ordem
void arv_posordem(Arv* a){
     if (!arv_vazia(a)){
        arv_posordem(a->esq); //mostra sae                        
        arv_posordem(a->dir); //mostra sad
        cout << a->info << " "; //mostra a raiz        
     }
}
int max2(int a, int b){
    return (a>b) ? a : b;
}
int arv_altura(Arv* a){
    if (arv_vazia(a))
      return -1;
    else
      return 1 + max2(arv_altura(a->esq), arv_altura(a->dir));
}