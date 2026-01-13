
# Dizionari

Modifiche e nuove funzioni per garantire liste di trabocco di lunghezza costante. 

Il file [dizionario.c](dizionario.c) raccoglie tutte le funzioni per la gestione del dizionario. La funzione `main` è contenuta nello stesso file.

Sono presenti inoltre i file [lista.c](lista.c) e [dizionario.h](dizionario.h) già visti in precedenza.

## Versione finale della funzione `inserisci_dizionario`

Se in `d` è presente un elemento `e` tale che `e.chiave` è uguale a `elem.chiave`, aggiorna `e.valore` con `elem.valore`. Altrimenti aggiunge `elem` al dizionario.

Nel caso in cui si tratta di un nuovo elemento, viene incrementato il campo `n`.

```C
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
```

La lunghezza delle liste viene limitata raddoppiando la dimensione del dizionario tramite la funzione `ridimensiona_dizionario`. Questa ritorna un nuovo dizionario composto da `new_m` liste di trabocco e contenente gli stessi elementi di `d`.

```C
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
```

La funzione `cancella_testa` elimina ll nodo in testa alla lista di input, è definita nel file [lista.c](lista.c)

Se la lista è non vuota, cancella il nodo in testa alla lista altrimenti ritorna `NULL`.

```C
nodo *cancella_testa(nodo *L){
    nodo *p;
    if ( L == NULL )
        return NULL;
    
    p = L;
    L = L->next;

    free(p);
    return L;
}
```

Per monitorare l'effettivo utilizzo delle liste, si usa la seguente funzione che mostra le seguenti informazioni sul dizionario in input stampando:

- Il numero di elementi nel dizionario
- Il numero di liste di trabocco
- La dimensione della lista più lunga

```C
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
```

## Funzione `main`

Il programma legge ripetutamente stringhe dallo standard input (`stdin`)
e le utilizza come chiavi di un dizionario.

A ciascuna chiave è associato un valore intero che rappresenta
il numero di occorrenze della stringa letta.

Dopo l'inserimento, stampa le informazioni su dizionario.

```C
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
```
## Compilazione

Il programma è diviso i tre file: de definizioni dei tipi di dato sono sul file [dizionario.h](dizionario.h) e le funzioni delle liste sono definite sul file [lista.c](lista.c). Per compilare il programma occorre compilare insieme [dizionario.c](dizionario.c)  e [lista.c](lista.c).

Assumendo che tutti i file si trovino nella stessa cartella:

```bash
gcc lista.c dizionario.c
```

Eseguendo

```bash
cat moby_dick_elenco.txt | ./a.out
```

si ottiene

```bash
Dimensione dizionario: 19047
Numero liste di trabocco: 3071
Dimensione della lista più lunga: 17
```

# Argomenti alla linea di comando

Nei programmi scritti in linguaggio C è possibile passare dei valori direttamente dalla linea di comando al momento dell’esecuzione. Questi valori, detti *argomenti della linea di comando*, permettono all'utente di fornire dati al programma senza richiedere input durante l'esecuzione. Gli argomenti vengono ricevuti dalla funzione `main` tramite due parametri: un intero che indica il numero totale di argomenti passati e un array di stringhe che li contiene.

Il seguente programma utilizza i parametri della linea di comando per leggere una serie di valori numerici inseriti dall'utente. Ogni argomento viene analizzato e, se rappresenta un numero intero valido, viene sommato agli altri. Al termine, il programma stampa la somma complessiva degli interi forniti come input.

```c
#include <stdio.h>

int main(int nargs, char *args[]){
    int somma = 0;
    int n;
    for(int i = 1; i < nargs; i++){
        if ( sscanf(args[i], "%d", &n) == 1)
            somma += n;
    }
    printf("%d\n", somma);
}
```

Se il programma è compilato nel file `a.out`, la seguente esecuzione

```bash
./a.out 12 21 ciao 10
```

stampa `43`.