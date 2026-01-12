#include "dizionario.h"

/***
Se la chiave in `v` è presente nella lista, aggiorna il valore corrispondente. Altrimenti inserisce in testa `v`.

Ritorna la lista modificata.
***/
nodo *inserisci(nodo *L, chiave_valore v){
    nodo *p = cerca(L, v.chiave);
    if (p != NULL) {
         p->info.valore = v.valore; 
    } else {
        L = inserisci_in_testa(L, v);
    }
    return L;
}

/***
Ritorna il puntatore al nodo della lista `L` tale che il campo `info.chiave` sia uguale a `k`. `NULL` altrimenti. 
***/
nodo *cerca(nodo* L, char *k){
    nodo *p = L;
    while( p != NULL  ){
        if ( strcmp(p->info.chiave, k) == 0 )
            return p;
        p = p->next;
    }
    return NULL;
}

/***
Inserisce un nuovo nodo con informazione `v` in testa alla lista identificata dal puntatore `L`.
***/

nodo *inserisci_in_testa(nodo *L, chiave_valore v){
    nodo *p = malloc( sizeof(nodo) );
    if (p == NULL)
        return L; // La malloc non è andata a buon fine
    p->info = v;
    p->next = L;
    return p;
}

/***
Cancella dalla lista il primo nodo `n` tale che `n.info.chiave` è uguale a `k`
***/
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

/***
Stampa il contenuto della lista
***/
void mostra_lista(nodo *L){
    nodo *p = L;

    printf("[");
    while ( p != NULL ){ 
        printf("( %s, %.2f ) ", p->info.chiave, p->info.valore );
        p = p->next;
    }
    printf("]\n");
}

