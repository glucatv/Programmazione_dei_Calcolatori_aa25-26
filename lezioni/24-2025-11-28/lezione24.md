

# Algoritmo di archimede implementato in C.


Questa versione, rispetto a quella della scorsa lezione, utilizza il tipo di dato `double` al posto del `float`.  Il tipo `double` codifica numeri in virgola mobile a precisione doppia e garantisce maggiore risoluzione e quindi approssimazioni più precise.


```C
int archimede(){// il tipo di ritorno di default e' int, e questo e'un commento
    /*
    Stampa una approssimazione di pi-greco eseguendo iter_max iterazioni
    dell'algoritmo di Archimede 
    */

    /* dichiarazioni di variabile */
    double L_i = sqrt(2), L_c = 2;  // anziche float L_i = sqrt(2), L_c = 2;
    int c = 0, iter_max = 10;
    int n = 4;  // dichiarazione+inizializzazione
    double p_i, p_c;   // dichiarazioni
    // anziche float p_i, p_c;

    while (c < iter_max){
        p_i = n*L_i/2;
        p_c = n*L_c/2;
        printf("n = %4d; p_i = %.10f; p_c = %.10f\n", n, p_i, p_c);
        L_i = sqrt((2-sqrt(4-L_i*L_i)));
        L_c = 2*L_i/sqrt(4-L_i*L_i);
        c++;  // equivalente a c+= 1;
        n *= 2;
    }
}
```


La prossima versione utilizza il ciclo `for` al posto del `while`.


```C
int archimede(){        // il tipo di ritorno di default e' int, e questo e'un commento
    /*
    Stampa una approssimazione di pi-greco eseguendo iter_max iterazioni
    dell'algoritmo di Archimede 
    */

    /* dichiarazioni di variabile */
    double L_i = sqrt(2), L_c = 2;  // anziche float L_i = sqrt(2), L_c = 2;
    int c, iter_max = 10;
    int n = 4;  // dichiarazione+inizializzazione
    double p_i, p_c;   // dichiarazioni
    // anziche float p_i, p_c;

    for (c = 0; c < iter_max; c++){
        p_i = n*L_i/2;
        p_c = n*L_c/2;
        printf("n = %4d; p_i = %.10f; p_c = %.10f\n", n, p_i, p_c);
        L_i = sqrt((2-sqrt(4-L_i*L_i)));
        L_c = 2*L_i/sqrt(4-L_i*L_i);
        n *= 2;
    }
}
```

In generale l'espressione

```C
for( espr0; cond; espr1){
    blocco;
}
```

è equivalente a

```C
espr0;
while( cond ){
    blocco;
    espr1;
}
```

Nel prossimo esempio, la variabile `iter_max` diventa un parametro della funzione.


```C
int archimede(int iter_max){
    /*
    Stampa una approssimazione di pi-greco eseguendo iter_max iterazioni
    dell'algoritmo di Archimede 
    */

    /* dichiarazioni di variabile */
    double L_i = sqrt(2), L_c = 2;  // anziche float L_i = sqrt(2), L_c = 2;
    int n = 4;  // dichiarazione+inizializzazione
    double p_i, p_c;   // dichiarazioni
    // anziche float p_i, p_c;

    for (int c = 0; c < iter_max; c++){
        p_i = n*L_i/2;
        p_c = n*L_c/2;
        printf("n = %4d; p_i = %.10f; p_c = %.10f\n", n, p_i, p_c);
        L_i = sqrt((2-sqrt(4-L_i*L_i)));
        L_c = 2*L_i/sqrt(4-L_i*L_i);
        n *= 2;
    }
}
```


Quest'ultima verione restituisce un valore di tipo `double` usando l'istruzione `return`.


```C
double archimede(int iter_max){
    /*
    Stampa una approssimazione di pi-greco eseguendo iter_max iterazioni
    dell'algoritmo di Archimede. Restituisce la media degli ultimi
    perimetri
    */

    /* dichiarazioni di variabile */
    double L_i = sqrt(2), L_c = 2;  // anziche float L_i = sqrt(2), L_c = 2;
    int n = 4;  // dichiarazione+inizializzazione
    double p_i, p_c;   // dichiarazioni
    // anziche float p_i, p_c;

    for (int c = 0; c < iter_max; c++){
        p_i = n*L_i/2;
        p_c = n*L_c/2;
        printf("n = %4d; p_i = %.10f; p_c = %.10f\n", n, p_i, p_c);
        L_i = sqrt((2-sqrt(4-L_i*L_i)));
        L_c = 2*L_i/sqrt(4-L_i*L_i);
        n *= 2;
    }

    return (p_i+p_c)/2;
}
```


Il valore viene restituito alla funzione chiamante dove può essere utilizzato come nel seguente `main` in cui viene assegnato ad una variabile.

```C
int main(){
    double pi = archimede(12);
    printf("%f\n", pi);
}
```


# Tipi di dato scalari

- **Interi**: Oltre agli `int` (a 32 bit), esistono i `long` a 64 bit, i `char` a 8 bit...
- **Virgola mobile**: `float`, `double`


```C
int main(){
    char c = 65; // int a 8 bit

    printf("%d, %c\n",  c, c);

    c = 'a'; // assegno a c la codifica ASCII di a minuscolo

    for(int i = 0; i < 10; i++ )
        printf("%c\n", c+i);
}
```


# Gli array

Sequenze di elementi di tipo omogeneo


```C
int main(){
    double pi[3] = {2.8284271247, 3.0614674589, 3.1214451523};
    int a[10]; // valori indefiniti
    int b[10] = {12, 1, 9}; // gli altri sono 0
    int z[100] =  {0}; // tutti 0

    // a = {0,1,2} NO!

    for(int i = 0; i < 3; i++)
        printf("%f\n", pi[i]);

    printf("----------------------------\n");

    int n = sizeof(a); // ritorna la dimensione in byte di a
    n /= sizeof(int); 

    for(int i = 0; i < n; i++)
        printf("%d\n", a[i]);

    printf("----------------------------\n");

    for(int i = 0; i < 10; i++)
        printf("%d\n", b[i]);

    printf("----------------------------\n");

    pi[2] = 3.141592; // modifica di un elemento
    for(int i = 0; i < 3; i++)
        printf("%f\n", pi[i]);

}
```
