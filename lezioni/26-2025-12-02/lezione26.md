
# Stringhe

```C
#include <stdio.h>
#include <string.h>

/*
Prototipi
*/
int len(char a[]);
void upper(char a[]);
```

Calcola la lungherra della stringa ritornando la posizione del primo carattere di fine-stringa `\0`

```C
int len(char a[]){
    int i;
    for(i = 0; a[i] != '\0'; i++){
        //noops
    }
    return i;
    /*
    Complessità temporale: O(n) dove n è la
    lunghezza della stringa
    */
}
```

Sostituisce tutte le lettere minuscole nelle corrispondenti maiuscole. Usa operazioni aritmetiche su `char` sfruttando il fatto che in C i caratteri sono identificati dai codici ASCII.

```C
void upper_expensive(char testo[]){
    int i;
    for(i = 0; i < len(testo); i++){
        if ( testo[i] >= 'a' && testo[i] <= 'z') // && è and; || è or; ! è not 
            testo[i] = 'A' + (testo[i] - 'a');
    }
    /*
    Complessità temporale: O(n^2) perché len() ha costo lineare e viene eseguita n volte.
    */
}
```

L'operazione ha costo quadratico nella lunghezza della stringa perché ad ogni iterazione viene invocata la funzione `len`. Basterebbe invocarla una volta soltanto, prima del ciclo.

```C
void upper(char testo[]){
    int i, n = len(testo);
    for(i = 0; i < n; i++){
        if ( testo[i] >= 'a' && testo[i] <= 'z')
            testo[i] = 'A' + (testo[i] - 'a');
    }
    /*
    Complessità temporale: O(n)
    */
}
```

Questo `e il main che utilizza le precedenti funzioni

```C
int main(){
    char a[] = "stringa c";
    printf("%s\n", a);

    int n = sizeof(a)/sizeof(char);
    printf("%d\n", n);

    a[4] = '\0';
    n = sizeof(a)/sizeof(char);
    printf("%s, %d, %d\n", a, n, len(a));

    upper(a);
    printf("%s\n", a);

    printf("%ld\n", strlen(a)); // funzione della libreria string
}
```

# Puntatori

```C
#include <stdlib.h>

int main(){
    double *a = NULL; /* puntatore nullo, come fosse -1; */

    a = malloc(sizeof(double)); // funzione della libreria stdlib

    a[0] = 3.1415;
    printf("%f\n", a[0]);
}
```

Viene allocata memoria per un `double` e l'indirizzo assegnago ad `a`. Quest'ultimo può essere visto come un vettore di un elemento e, pertanto, accedere al `double` con l'indicizzazione.

Per ottenere un array di più double basta passare a `malloc` il numero di elementi voluti per `sizeof(double)`.

