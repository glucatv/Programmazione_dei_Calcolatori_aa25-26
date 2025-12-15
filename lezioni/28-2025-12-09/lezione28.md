

# Array dinamici


```C
struct lista {
    double *a; // la sequenza è memorizzata in questo array
    int n, c;  // numero di elementi nella lista e capacità dell'array
};
typedef struct lista lista;

lista nuova_lista();
lista append(lista, double);
lista rem_last(lista);
void mostra_lista(lista);
```

Ritorna una lista vuota

```C
lista nuova_lista(){
    lista lst = {NULL, 0, 0};
    return lst;
}
```

Stampa le informazioni sulla lista e i sui elementi

```C
void mostra_lista(lista lst){
    printf("[");
    for(int i = 0; i < lst.n; i++){
        printf("%f ", lst.a[i]);
    }
    printf("]");
    printf("\n\tc = %d; n = %d\n", lst.c, lst.n);
}
```

## Aggiunge un nuovo elemento `x` in fondo alla lista, ritorna la lista modificata

```C
lista append(lista lst, double x){
    if ( lst.c == lst.n ){
        lst.c = 2*lst.c+1;
        lst.a = realloc(lst.a, lst.c*sizeof(double));
    }
    lst.a[lst.n] = x;
    lst.n++;
    return lst;
}
```

Nel caso peggiore la `realloc` deve allocare l'intero spazio per un nuovo array e copiare tutti gli $n$ elementi nel nuovo spazio. In questo caso la complessità temporale è $O(n)$. Nel caso in cui nell'array ci sia ancora spazio o la riallocazione è avvenuta espandendo l'array corrente, la complessità è costante.

Si osservi che dopo una operazione di inserimento "costosa" di costo $c'n$ (per una opportuna costante $c'$), il nuovo array avrà $n$ posizioni libere. Questo garantirà che le successive $n$ operazioni di inserimento in coda saranno eseguite in tempo costane. Sia $c$ questa costante allora, nel caso peggiore $n$ operazioni di `append` hanno un costo temporale totale pari a $c'n + nc$ ovvero $O(n)$. Mediando, una singola operazione ha costo costante. Questo tipo di analisi della complessità è detta *ammortizzata* e valuta il costo medio per operazione su una sequenza di operazioni anche quando alcune sono più costose.

Poichè, nel caso peggiore, l'array contiene $n$ posizioni libere, queste devono essere considerate memoria extra e quindi la complessità spaziale è lineare in $n$.

### Eliminare l'ultimo elemento dalla lista

Basterebbe decrementare $n$, però questo esporrebbe al rischio di avere un array di dimensioni enormi rispetto alla quantità di elementi effettivement utilizzati a scapito della complessià spaziale che risulterebbe non più legata ad $n$. Per evitare questo, la dimensione dell'array viene di mezzata quando l'occupazione effettiva scenda al di sotto della soglia di $1/4$ della dimensione totale.

```C
lista rem_last(lista lst){
    if ( lst.n <= lst.c/4 ){
        lst.c = lst.c/2+1;
        lst.a = realloc(lst.a, lst.c*sizeof(double));
    }
    lst.n--;
    return lst;
}
```

La complessità rimane $O(1)$ poiché la riduzione della capacità non comporta alcuna copia degli elementi, ma solo una riallocazione nello stesso blocco di memoria.

Inoltre, la stessa riallocazione garantisce che la quantità di memoria extra (non utilizzata) è non superiore a 3 volte la memoria utilizzata. Quindi la complessità spaziale resta lineare anche a seguito di molte cancellazioni.

Un esempio di esecuzione.

```C
int main(){
    lista L = nuova_lista();
    for(int i = 0; i < 10; i++){
        L = append(L, i*3.1415);
    }
    while (L.n > 0){
        L = rem_last(L);
        mostra_lista(L);
    }
}
```

# Array di tipo non omogeneo

Gli elementi degli array in C sono tutti dello stesso tipo. Per simulare ciò che avviene in Python con le liste si usa un tipo che vada bene per tutti. Una scelta molto versatile è quella di utilizzare un array di puntatori. Quindi ogni elemento dell'array non è altro che l'indirizzo all'elemento effettivo.  

```C
struct lista {
    void **a;  // array di puntatori generici (void*)
    char *tipo; // 'i' per int; 'd' per double;
    int n, c;  // numero di elementi nella lista e capacità dell'array
};
typedef struct lista lista;
```

L'array nella lista contiene puntatori al tipo generico `void`. Quindi `void **a` va letto come `a` array di puntatori. È stato inserito il nuovo campo `tipo` che è un array della stessa dimensione di `a` e indica il tipo dell'elemento in posizione `i` della lista. Per semplicità assumiamo che la lista possa contenere solo `double` e `int`, tenendo presente che l'insieme di questi tipi può essere allargato a piacere. 

La funzione `append` dovrà prendere un parametro aggintivo di tipo `char` che descrive il tipo di dato che stiamo aggiungendo; il parametro relativo al valore del dato è sostituito con l'indirizzo al dato; questo, coerentemente con la definizione del campo `a` dentro la `struct` che definisce la lista, è di tipo puntatore a `void`.

```C
lista nuova_lista();
lista append(lista, void*, char);
void mostra_lista(lista);
```

La funzione che ritorna la lista vuota deve definire anche il campo `tipo`.

```C
lista nuova_lista(){
    lista lst = {NULL, NULL, 0, 0};
    return lst;
}
```

La funzione `append`, eventualmente ridimensione anche il campo `tipo`.

```C
lista append(lista lst, void *x, char t){
    if ( lst.c == lst.n ){
        lst.c = 2*lst.c+1;
        lst.a = realloc(lst.a, lst.c*sizeof(void*));
        lst.tipo = realloc(lst.tipo, lst.c*sizeof(char));
    }
    lst.a[lst.n] = x;
    lst.tipo[lst.n] = t;
    (lst.n)++;
    return lst;
}
```

Nella funzione `mostra_lista` si deve distinguere come effettuare la stampa in funzione del tipo dell'elemento da stampare. Se questo è di tipo intero il formato da usare è `"%d"` altrimenti, nel caso di `double` questo è `"%f"`.

L’operazione che permette di ottenere il valore memorizzato all’indirizzo indicato da un puntatore si chiama *dereferenziazione* e si esegue tramite l’operatore `*`. Ad esempio, se la variabile `p` è un puntatore a `float`, allora `*p` rappresenta il `float` puntato da `p`, cioè il valore memorizzato all’indirizzo contenuto in `p`.

Poiché `lst.a[i]` è un puntatore, `*(lst.a[i])` sarebbe, in linea di principio, il valore puntato da `lst.a[i]`. Tuttavia `lst.a[i]` è un puntatore a `void`, cioè un puntatore generico che non può essere dereferenziato direttamente. Per poter accedere al dato, occorre prima convertirlo in un puntatore al tipo corretto, ad esempio `int` o `double`. Questa conversione di tipo si chiama *casting* e la sua sintassi è `(nuovo_tipo)valore`, che indica la conversione di `valore` nel tipo `nuovo_tipo`.

```C
void mostra_lista(lista lst){
    printf("[");
    for(int i = 0; i < lst.n; i++){
        if (lst.tipo[i] == 'i')
            printf("%d ", *(int*)(lst.a[i]) );
        else if (lst.tipo[i] == 'd')
            printf("%f ", *(double*)(lst.a[i]) );
    }
    printf("]");
    printf("\n\tc = %d; n = %d\n", lst.c, lst.n);
}
```

Nel nostro caso, l'espressione `(int*)(lst.a[i])` converte `lst.a[i]` in un puntatore a `int`; solo dopo questa conversione possiamo applicare l’operatore `*` per dereferenziarlo e ottenere il valore memorizzato all’indirizzo indicato dal puntatore. In questo modo si recupera l’intero a cui `lst.a[i]` effettivamente punta.

La funzione `main` crea una piccola lista contenente due `double` e un `int`, memorizzati in tre variabili. Alla funzione `append` dobbiamo passare l'indirizzo di memoria in cui sono memorizzati questi valori, cioè l’indirizzo a cui fanno riferimento le variabili stesse. Per ottenere l'indirizzo di una variabile si utilizza l'operatore `&`: se `x` è una variabile, allora `&x` è l'indirizzo di memoria in cui `x` è memorizzata.

```C
int main(){
    lista L = nuova_lista();
    double pi = 3.1415;
    double e = 2.71;
    int k = 60;
    L = append(L, &pi, 'd');
    L = append(L, &k, 'i');
    L = append(L, &e, 'd');

    mostra_lista(L);
}
```
