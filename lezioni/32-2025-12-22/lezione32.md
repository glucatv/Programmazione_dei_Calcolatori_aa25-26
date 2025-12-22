
# Liste concatenate

```C
#include <stdio.h>
#include <stdlib.h>
```

Definizione delle strutture e tipi.

```C
struct nodo {
    double info; // informazione
    struct nodo *next; // riferimento al nodo successivo
};
typedef struct nodo nodo;
typedef nodo* lista;
```

Prototipi delle funzioni

```C
void mostra_lista(nodo*);
nodo *inserisci_in_testa(nodo*, double);
nodo *cancella(nodo*, double);
```

## Inserimento in testa alla lista

Inserisce un nuovo nodo con informazione `v` in testa alla lista identificata dal puntatore `L`.

```C
nodo *inserisci_in_testa(nodo *L, double v){
    nodo *p = malloc( sizeof(nodo) );
    if (p == NULL)
        return L; // La malloc non è andata a buon fine
    p->info = v;
    p->next = L;
    return p;
}
```

## Cancellazione

Cancella dalla lista il primo nodo contenente l'informazione `v`.

Si distinguono i seguenti casi:

- La lista è vuota: viene restituito `NULL`
- Il nodo da cancellare è il primo della lista: viene ritornato il puntatore al nodo successivo a `L`
- La lista contiene solo un nodo: la lista non viene modificata
- La lista non contiene il valore `v`: la lista non viene modificata
- La lista contiene `v` in una posizione che non è la prima: viene posizionato un puntatore `p` al nodo precedente in modo da modificare il campo `next` del nodo puntato da `p`, bypassando quello contenente `v`.

Nei casi in cui ci sia effettivamente una cancellazione, la memoria utilizzata dal nodo eliminato viene deallocata con la funzione `free`.

```C
nodo *cancella(nodo *L, double v){
    nodo *t, *p;
    if ( L == NULL)
        return NULL;
    if (L->info == v){
        // cancella il primo nodo della lista
        t = L;
        L = L->next;
        free(t);
        return L;
    }
    if (L->next == NULL) // non ci sono altri nodi oltre al primo
        return L; 
    p = L;
    // ricerca del nodo precedente a quello contenente v
    while( p->next != NULL && p->next->info != v){
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
        printf("%.1f ", p->info);
        p = p->next;
    }
    printf("]\n");
}
```

Alcuni esperimenti

```C
int main(){
    nodo *L = NULL; // lista concatenata vuota; oppure lista L = NULL

    for(int i=0; i < 10; i++){
        L = inserisci_in_testa(L, i);
    }

    mostra_lista(L);

    L = cancella(L, 4); // cancellazione al centro
    mostra_lista(L);
    L = cancella(L, 9); // cancellazione in testa
    mostra_lista(L);
    L = cancella(L, 0); // cancellazione in coda
    mostra_lista(L);
    L = cancella(L, 10); // tentativo di cancellazione
    mostra_lista(L);
}
```
