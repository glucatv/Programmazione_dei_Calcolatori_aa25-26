
# Verso l'implementazione della struttura dizionario

Un dizionario può essere implementato tramite un array `d` in cui a ogni chiave `k` viene associata, mediante una funzione di indirizzamento `h`, una posizione `i` dell'array.

Il contenuto di `d[i]` è una struttura che raccoglie tutte le coppie chiave-valore `(k, v)` per le quali la funzione di indirizzamento restituisce lo stesso valore `i`, cioè tutte le chiavi tali che `h(k) = i`.

- La *ricerca* di una coppia associata a una chiave `k` avviene calcolando `i = h(k)` e consultando il contenuto di `d[i]` per individuare la presenza di una coppia con chiave `k`.

- L'*inserimento* di una nuova coppia `(k, v)` avviene calcolando la posizione `i = h(k)` e aggiungendo la coppia alla struttura contenuta in `d[i]`, verificando eventualmente che la chiave non sia già presente. Se già presente, si aggiorna il suo valore con `v`.

- La *cancellazione* di una coppia con chiave `k` avviene calcolando `i = h(k)` e rimuovendo dalla struttura in `d[i]` la coppia corrispondente, se presente.

Se la funzione di indirizzamento `h` è efficiente e il suo costo non cresce con il numero di coppie del dizionario, e se anche le strutture contenute in `d[i]` hanno dimensione limitata, allora le operazioni di ricerca, inserimento e cancellazione hanno costo costante.

Le strutture in `d[i]` verranno implementate come **liste concatenate**

# Liste concatenate

Una lista concatenata è una struttura lineare formata da elementi detti *nodi*, ognuno dei quali contiene l'informazione e un riferimento al nodo successivo nella lista. Il primo nodo della lista è detto *testa* e permette di accedere a tutti gli altri nodi seguendo i riferimenti. L'ultimo nodo ha un riferimento nullo, che indica la fine della lista.

Questa struttura permette di aggiungere, cercare o rimuovere elementi scorrendo i nodi uno dopo l'altro, senza richiedere che la memoria sia contigua.

```C
#include <stdio.h>
#include <stdlib.h>

struct nodo {
    double info; // informazione
    struct nodo *next; // riferimento al nodo successivo
};
typedef struct nodo nodo;
typedef nodo* lista;

void mostra_lista(nodo*);

int main(){
    nodo *L = NULL; // lista concatenata vuota; oppure lista L = NULL

    L = malloc( sizeof(nodo) ); // nuovo nodo, testa della lista
    (*L).info = 3.14; // definizione del campo info
    (*L).next = NULL; // primo ed ultimo nodo, il riferimento successivo è NULL

    nodo *p = malloc( sizeof(nodo) );
    p->info = 2.71; // equivalente a (*p).info = 2.71
    p->next = L;
    L = p;

    p = malloc( sizeof(nodo) );
    p->info = 0.9;
    p->next = L;
    L = p;

    mostra_lista(L);
}

void mostra_lista(nodo *L){
    nodo *p = L;

    printf("[");
    while ( p != NULL ){ 
        printf("%f ", p->info);
        p = p->next;
    }
    printf("]\n");
}
```
