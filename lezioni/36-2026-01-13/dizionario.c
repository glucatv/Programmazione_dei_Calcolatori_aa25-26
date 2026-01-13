/***
# Dizionari

Aggiungeremo alla struttura dati delle funzionalità che garantiranno liste di trabocco di lunghezza media costante.

Valuteremo il risultato creando un dizionario contentente come chiavi le parole contenute in un testo, e come valore, il numero di volte in cui queste vi compaiono.

La definizione aggiornata della struttura è contenuta del file [dizionario.h](dizionario.h) che deve essere incluso in questo modo
***/

#include "dizionario.h"

/***
Sono stati aggiunti:

* il campo `n` contenente il numero di elementi nel dizionario;
* il campo `h` contenente il puntatore alla funzione hash.

Vedere i commenti nel file. 


Funzione hash giocattolo utilizzata per dizionari con 2 liste.
***/
int h(char *k, int m) {
    return k[0] % 2;
}

/***
Funzione hash 'seria', multo utilizzata in pratica
***/
int hash_djb2(char *key, int size) {
    unsigned int h = 5381;

    while (*key) {
        h = ((h << 5) + h) + *key; 
        key++;
    }

    return h % size;
}

/***
Ritorna un dizionario vuoto con `m` liste di trabocco.
***/
dizionario init_dizionario(int m){
    dizionario d;
    d.m = m;
    d.n = 0; 
    d.h = hash_djb2;
    d.a = malloc(sizeof(lista)*m);
    for(int i = 0; i < m; i++)
        d.a[i] = NULL;
    return d;
}

/***
Se in `d` è presente un elemento `e` tale che `e.chiave` è uguale a `elem.chiave`, aggiorna `e.valore` con `elem.valore`. Altrimenti aggiunge `elem` al dizionario.

Nel caso in cui si tratta di un nuovo elemento, viene incrementato il campo `n`.
***/
dizionario inserisci_dizionario(dizionario d, chiave_valore elem){
    int p = d.h(elem.chiave, d.m); // la lista che deve contenere elem

    nodo *u = cerca(d.a[p], elem.chiave);

    if ( u == NULL){
        d.a[p] = inserisci_in_testa(d.a[p], elem);
        d.n++;
        if ( d.n> 10*d.m ){  // non è più vero che la lunghezza media delle liste è inferiore a 10
            d = ridimensiona_dizionario(d, 2*d.m+1);
        }
    } else {
        u->info.valore = elem.valore;
    }

    return d;
}

/***
Ritorna un nuovo dizionario di dimensione new_m, contenente gli stessi elementi di d
***/
dizionario ridimensiona_dizionario(dizionario d, int new_m){
    int i = 0;
    lista L;
    lista *old_a = d.a;
    int old_m = d.m;
    d.a = malloc(sizeof(lista)*new_m);
    d.m = new_m;
    d.n = 0;
    
    for (i=0; i < d.m; i++){
        d.a[i] = NULL;
    }

    for(i = 0; i < old_m; i++){
        L = old_a[i];
        while ( L != NULL){
            d = inserisci_dizionario(d, L->info);
            L = cancella_testa(L); 
        }
    }

    free(old_a);

    return d;

}

/***
Se in `d` è presente un elemento `e` tale che `e.chiave` è uguale a `k`, lo elimina dal dizionario. Altrimenti lascia tutto invariato.
***/
dizionario cancella_dizionario(dizionario d, char *k){
    int p = d.h(k, d.m);

    d.a[p] = cancella(d.a[p], k); // la verifica è incorporata

    return d;
}

/***
Stampa tutti gli elementi di `d`, lista per lista.
***/
void mostra_dizionario(dizionario d){
    printf("====================================\n");
    for(int i=0; i < d.m; i++){
        printf("* %3d - ", i);
        mostra_lista(d.a[i]);
    }
}

/***
Ritorna `1` se `k` è una chiave di `d`, `0` altrimenti
***/
int in_dizionario(dizionario d, char *k){
    int p = d.h(k, d.m);

    if ( cerca(d.a[p], k) == NULL)
        return 0;
    return 1;
}

/***
Ritorna il valore associato alla chiave `k`.

`k` deve essere una chiave del dizionario, deve essere preventivamente
verificato con `in_dizionario`.
***/
double ottieni_valore_dizionario(dizionario d, char *k){
    int p = d.h(k, d.m);

    nodo *u = cerca(d.a[p], k);

    return u->info.valore;
}

void mostra_info(dizionario d){
    int max_len = 0;

    for(int i = 0; i < d.m; i++){
        int curr_len = lunghezza(d.a[i]);
        if (curr_len > max_len)
            max_len = curr_len;
    }

    printf("Dimensione dizionario: %d\n", d.n);
    printf("Numero liste di trabocco: %d\n", d.m);
    printf("Dimensione della lista più lunga: %d\n", max_len);
}

/***
Esperimenti:

Il programma legge ripetutamente stringhe dallo standard input (stdin)
e le utilizza come chiavi di un dizionario.

A ciascuna chiave è associato un valore intero che rappresenta
il numero di occorrenze della stringa letta.

L'inserimento e l'aggiornamento delle chiavi avviene dinamicamente,
utilizzando una struttura dati "dizionario".
***/

int main() {
    /* Inizializza il dizionario con una capacità iniziale di 128 elementi */
    dizionario d = init_dizionario(2);

    /* Buffer utilizzato da getline per leggere le righe */
    char *word = NULL;
    unsigned long len = 0;
    int nread;

    char *temp;

    /*
     * Legge dallo standard input (tastiera) una riga alla volta.
     * Ogni riga rappresenta una chiave del dizionario.
     *
     * La funzione getline alloca dinamicamente (o rialloca)
     * il buffer 'word' e vi memorizza la riga letta.
     * Il valore di ritorno è il numero di caratteri letti,
     * oppure -1 in caso di EOF.
     */
    while ((nread = getline(&word, &len, stdin)) != -1) {

        /* Rimuove il carattere di newline finale, se presente */
        if (nread > 0 && word[nread - 1] == '\n')
            word[nread - 1] = '\0';

        /* Recupera il numero di occorrenze già presenti
        (se esiste la chiave) */
        int occorrenze = 0;
        if (in_dizionario(d, word) == 1) {
            occorrenze = ottieni_valore_dizionario(d, word);
        }

        /*
         * Crea una copia della stringa 'word'.
         * Questo è necessario perché la funzione inserisci_dizionario
         * salva direttamente il puntatore alla stringa nel nodo,
         * e 'word' viene riutilizzato ad ogni chiamata di getline.
         */
        temp = malloc(strlen(word) + 1);
        strcpy(temp, word);

        /* Inserisce (o aggiorna) la coppia chiave-valore nel dizionario */
        chiave_valore v = { temp, occorrenze + 1 };
        d = inserisci_dizionario(d, v);
    }

    /* Stampa il contenuto finale del dizionario */
    //mostra_dizionario(d);
    mostra_info(d);
}

/***
Se l'elenco di parole è contenuto in un file, ad esempio
[Moby Dick](moby_dick_elenco.txt), è possibile fornire il file come input
al programma tramite la redirezione dello standard input.
 
Esempio di esecuzione da linea di comando:

`./a.out < moby_dick_elenco.txt`

oppure

`cat moby_dick_elennco.txt | ./a.out`

# Compilazione

Il programma è diviso i tre file: de definizioni dei tipi di dato sono sul file [dizionario.h](dizionario.h) e le funzioni delle liste sono definite sul file [lista.c](lista.c). Per compilare il programma occorre compilare insieme il presente file con il file [lista.c](lista.c).

Assumendo che tutti i file si trovino nella stessa cartella:

```bash
gcc lista.c lezione35.c
```
***/
