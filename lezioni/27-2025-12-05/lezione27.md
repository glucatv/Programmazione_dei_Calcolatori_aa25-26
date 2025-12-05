

# La funzione `realloc`

```C
int main(){
    double *a = NULL;
    int i, n = 3;

    a = malloc(3*sizeof(double));

    if ( a==NULL ){
        return 0;
    }

    a[0] = 3.1415;
    a[1] = 2*3.1415;
    a[2] = 3*3.1415;

    for(i=0; i < n; i++)
        printf("%f\n", a[i]);

    printf("==========================\n");

    n++;
    a = realloc(a, n*sizeof(double) ); // complessità temporale O(n) nel caso peggiore

    if (a == NULL )
        return 0;

    a[3] = 4*3.1415;
    for(i=0; i < n; i++)
        printf("%f\n", a[i]);
}
```

# `struct` e `typedef`

```C
struct punto {
    double x;
    double y;
    // oppure double x, y;
};
typedef struct punto punto;

int main(){
    struct punto p0 = {2.1, 0.5};
    punto p1 = {0, 1};
    p0.y = p0.x + p0.y;
    printf("(%f, %f)\n", p0.x, p0.y);
    printf("(%f, %f)\n", p1.x, p1.y);
}
```

# Array dinamici

Definiamo un nuovo tipo di dato chiamato `lista` che implementa una struttura dati sequenziale contenente `double` sulla quale sono definite le operazioni di creazione di `lista` vuota, indicizzazione in lettura e scrittura, inserimento e cancellazione dalla coda.


```C
struct lista {
    double *a; /* la sequenza è memorizzata in questo array */
    int n, c; /* numero di elementi nella lista e capacità dell'array */
};
typedef struct lista lista;

lista nuova_lista();
lista append(lista, double);
void mostra_lista(lista);

int main(){
    lista L = nuova_lista();
    for(int i = 0; i < 10; i++){
        L = append(L, i*3.1415);
        mostra_lista(L);
    }
}
```

Ritorna una lista vuota

```C
lista nuova_lista(){
    lista lst = {NULL, 0, 0};
    return lst;
}
```

Aggiunge un nuovo elemento x in fondo alla lista, ritorna la lista modificata

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
