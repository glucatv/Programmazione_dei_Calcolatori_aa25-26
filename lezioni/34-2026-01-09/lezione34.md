
# Dizionari

Un dizionario è implementato con un array di `m` liste concatenate. La lista contenente una coppia chiave-valore è stabilita da una funzione *hash* della chiave.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

La definizione di lista resta immutata.

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

Definizione di dizionario.

```C
struct dizionario {
    lista *a;
    int m;
};
typedef struct dizionario dizionario;
```

I prototipi delle nuove funzioni

```C
dizionario init_dizionario(int);
dizionario inserisci_dizionario(dizionario, chiave_valore);
dizionario cancella_dizionario(dizionario, char*);
void mostra_dizionario(dizionario);
```

Prototipi delle funzioni sulle liste, rimasti immutati

```C
void mostra_lista(nodo*);
nodo *inserisci_in_testa(nodo*, chiave_valore);
nodo *cancella(nodo*, char*); // cancellazione rispetto alla chiave che è una stringa
nodo *cerca(nodo*, char*);
void aggiorna(nodo*, char*, double);
nodo *inserisci(nodo*, chiave_valore);
```

Funzione hash giocattolo utilizzata per dizionari con 2 liste.

```C
int h(char *k) {
    return k[0] % 2;
}
```

Ritorna un dizionario vuoto con `m` liste di trabocco

```C
dizionario init_dizionario(int m){
    dizionario d;
    d.m = m;
    d.a = malloc(sizeof(lista)*m);
    for(int i = 0; i < m; i++)
        d.a[i] = NULL;
    return d;
}
```

Se in `d` è presente un elemento `e` tale che `e.chiave` è uguale a `elem.chiave`, aggiorna `e.valore` con `elem.valore`. Altrimenti aggiunge `elem` al dizionario.

```C
dizionario inserisci_dizionario(dizionario d, chiave_valore elem){
    int p = h(elem.chiave); // la lista che deve contenere elem
    d.a[p] = inserisci(d.a[p], elem); // aggiorna o inserisce nella lista
    return d;
}
```

Se in `d` è presente un elemento `e` tale che `e.chiave` è uguale a `k`, lo elimina dal dizionario. Altrimenti lascia tutto invariato.

```C
dizionario cancella_dizionario(dizionario d, char *k){
    int p = h(k);

    d.a[p] = cancella(d.a[p], k); // la verifica è incorporata

    return d;
}
```

Stampa tutti gli elementi di `d`, lista per lista.

```C
void mostra_dizionario(dizionario d){
    printf("====================================\n");
    for(int i=0; i < d.m; i++){
        mostra_lista(d.a[i]);
    }
}
```

Esperimenti

```C
int main(){
    dizionario d = init_dizionario(2);

    chiave_valore v0 = {"zero", 0};
    chiave_valore v1 = {"uno", 1};
    chiave_valore v2 = {"due", 2};
    chiave_valore v3 = {"tre", 3};
    chiave_valore v4 = {"quattro", 4};
    chiave_valore vn = {"zero", 0.5};

    d = inserisci_dizionario(d, v0);
    d = inserisci_dizionario(d, v1);
    d = inserisci_dizionario(d, v2);
    d = inserisci_dizionario(d, v3);
    d = inserisci_dizionario(d, v4);
    d = inserisci_dizionario(d, vn);

    mostra_dizionario(d);

    d = cancella_dizionario(d, "due");
    d = cancella_dizionario(d, "nove");
    mostra_dizionario(d);
}
```

Per rendere la struttura efficiente, le liste devono essere 'corte': devono avere una lunghezza costante nel numero `n` di elementi nel dizionario. Quindi `m` deve essere una frazione costante di `n`. Ovvero `m = n/c`, dove `c` è una costante `>=1`.

Inoltre, la funzione hash `h` deve distribuire in maniera uniforme gli elementi nelle `m` liste.

Se le due proprietà sono vere, ogni lista contiene circa `c` elementi, il che comporta che tutte le operazioni richiedono tempo costante.

La prima proprietà viene garantita usando, per il dizionario, un array a dimensione variabile.

La seconda proprietà viene garantita da una funzione hash facile da calcolare e che distribuisca in modo uniforme le chiavi tra le `m` liste.

## Funzioni sulle liste già descritte in precedenza.

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

Cancella dalla lista il primo nodo `n` tale che `n.info.chiave` è uguale a `k`

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
