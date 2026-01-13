#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
La definizione di lista resta immutata.
***/ 
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

/***
Definizione di dizionario.

Per consentire una gestione che garantisca che la lunghezza media delle liste sia costante, il numero delle liste di trabocco deve essere aumentato quando il rapporto tra il numero di elementi della lista e il numero di liste va oltre una costante `c`.

Per gestire questi eventi è necessario mantenere un campo con il numero di elementi del dizionario.

Inoltre, la struttura contiene un riferimento alla funzione hash utilizzato attraverso un puntatore a funzione.
***/
struct dizionario {
    lista *a;
    int m; // numero di liste
    int n; // numero di elementi  
    int (*h)(char *k, int m);   // puntatore alla funzione hash  <<<NEW
};
typedef struct dizionario dizionario;

/***
Prototipi funzioni hash
***/
int h(char*, int);
int hash_djb2(char*, int);


/***
I prototipi delle nuove funzioni
***/
dizionario init_dizionario(int);
dizionario inserisci_dizionario(dizionario, chiave_valore);
dizionario cancella_dizionario(dizionario, char*);
void mostra_dizionario(dizionario);
int in_dizionario(dizionario, char*);
double ottieni_valore_dizionario(dizionario, char*);
dizionario ridimensiona_dizionario(dizionario, int);

/***
Prototipi delle funzioni sulle liste, rimasti immutati
***/
void mostra_lista(nodo*);
nodo *inserisci_in_testa(nodo*, chiave_valore);
nodo *cancella(nodo*, char*); // cancellazione rispetto alla chiave che è una stringa
nodo *cerca(nodo*, char*);
void aggiorna(nodo*, char*, double);
nodo *inserisci(nodo*, chiave_valore);
nodo *cancella_testa(nodo*);
int lunghezza(nodo*);