
# Liste concatenate per dizionari

Specializziamo l'implementazione delle liste concatenate per rappresentare le *liste di trabocco* dei dizionari (vedere lezione 31).

I nodi della lista conterranno nel campo `info` le coppie chiave-valore del dizionario. Assumiamo per semplicità e senza perdita di generalità che le chiavi siano stringhe ed i valori siano `double`.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

Esempio di definizione della coppia chiave-valore

```C
 
struct chiave_valore {
    char *chiave;
    double valore;
};
typedef struct chiave_valore chiave_valore;

struct nodo {
    chiave_valore info; // informazione
    struct nodo *next; // riferimento al nodo successivo
};
typedef struct nodo nodo;
typedef nodo* lista;
```

Prototipi delle funzioni

```C
void mostra_lista(nodo*);
nodo *inserisci_in_testa(nodo*, chiave_valore);
nodo *cancella(nodo*, char*); // cancellazione rispetto alla chiave che è una stringa
nodo *cerca(nodo*, char*);
void aggiorna(nodo*, char*, double);
nodo *inserisci(nodo*, chiave_valore);
```

Se la chiave in `v` è presente nella lista, aggiorna il valore corrispondente. Altrimenti inserisce in testa `v`.

Ritorna la lista modificata.

```C
nodo *inserisci(nodo *L, chiave_valore v){
    nodo *p = cerca(L, v.chiave);
    if (p != NULL) {
         p->info.valore = v.valore; 
    } else {
        L = inserisci_in_testa(L, v);
    }
    return L;
}
```

Se L contiene un nodo con chiave k, aggiorna il suo valore associato con `v`. Altrimenti non fa nulla.

```C
void aggiorna(nodo* L, char* k, double v){
    nodo *p = cerca(L, k);
    if (p != NULL){
        p->info.valore = v;
    }
}
```

Ritorna il puntatore al nodo della lista `L` tale che il campo `info.chiave` sia uguale a `k`. `NULL` altrimenti. 

```C
nodo *cerca(nodo* L, char *k){
    nodo *p = L;
    while( p != NULL  ){
        if ( strcmp(p->info.chiave, k) == 0 )
            return p;
        p = p->next;
    }
    return NULL;
}
```

Inserisce un nuovo nodo con informazione `v` in testa alla lista identificata dal puntatore `L`.

```C
nodo *inserisci_in_testa(nodo *L, chiave_valore v){
    nodo *p = malloc( sizeof(nodo) );
    if (p == NULL)
        return L; // La malloc non è andata a buon fine
    p->info = v;
    p->next = L;
    return p;
}
```

Cancella dalla lista il primo nodo `n` tale che `n.info.chiave` è uguale a k

```C
nodo *cancella(nodo *L,  char *k){
    nodo *t, *p;
    if ( L == NULL)
        return NULL;
    if ( strcmp(L->info.chiave, k) == 0 ){  // L->info.chiave == k confrontiamo due puntatori (indirizzi)
        // cancella il primo nodo della lista
        t = L;
        L = L->next;
        free(t);
        return L;
    }
    if (L->next == NULL) // non ci sono altri nodi oltre al primo
        return L; 
    p = L;
    // ricerca del nodo precedente a quello contenente la chiave k
    while( p->next != NULL && strcmp(p->next->info.chiave, k) !=0 ) {
        p = p->next;
    }
    if(p->next != NULL){ // il nodo da cancellare esiste 
        t = p->next;
        p->next = p->next->next;
        free(t);
    }
    return L;
}
```

Stampa il contenuto della lista

```C
void mostra_lista(nodo *L){
    nodo *p = L;

    printf("[");
    while ( p != NULL ){ 
        printf("( %s, %.2f ) ", p->info.chiave, p->info.valore );
        p = p->next;
    }
    printf("]\n");
}
```

Alcuni esperimenti

```C
int main(){
    nodo *L = NULL; // lista concatenata vuota; oppure lista L = NULL

    chiave_valore pi = {"pi", 3.14};
    chiave_valore e = {"e", 2.71};
    chiave_valore zero = {"zero", 0};
    chiave_valore altro = {"x", 9};
    chiave_valore altro_ancora = {"x", 0.24};
    chiave_valore y = {"y", 100};

    L = inserisci_in_testa(L, pi);
    L = inserisci_in_testa(L, altro);
    L = inserisci_in_testa(L, e);
    L = inserisci_in_testa(L, zero);
    
    mostra_lista(L);
    
    aggiorna(L, "x",  -10.21);
    aggiorna(L, "y",  -10.21);
    mostra_lista(L);

    L = inserisci(L, altro_ancora);
    mostra_lista(L);
    L = inserisci(L, y);
    mostra_lista(L);

    nodo *u = cerca(L, "ee");
    if ( u != NULL){
        printf("il valore di %s è %.2f\n", u->info.chiave, u->info.valore);
    }

 
    L = cancella(L, "zero");
    mostra_lista(L);
    L = cancella(L, "x");
    mostra_lista(L);
    L = cancella(L, "pi");
    mostra_lista(L);
    L = cancella(L, "pi");
    mostra_lista(L);
    L = cancella(L, "e");
    mostra_lista(L);
}
```
