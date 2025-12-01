
# Le fasi della compilazione e struttura di un programma C 

Precompilazione, compilazione, linking

Direttive del preprocessore

```C
#include <stdio.h>
#include <math.h> 
```

Prototipi delle funzioni

```C
double archimede(int);
```

```C
int main(){
    double pi = archimede(12);
    printf("%f\n", pi);
}
```


Definizione della funzione: può essere posizionata in qualsiasi punto purché sia stato inserito il prototipo.

```C
double archimede(int iter_max){
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

Compilare con

```bash
gcc nomefile.c -lm
```

Il parametro `-l` serve per indicare quale libreria esterna collegare in fase di linking: `m` è il nome della libreria `math` che contiene la funzione `sqrt`.

# Array e funzioni

Alla funzione viene passato l'indirizzo di memoria dell'array. La funzione può modificare l'array.

```C
double somma_e_distruggi(double v[], int size ){
    int loc_size = sizeof(v)/sizeof(double);
    printf("size in func = %d\n", loc_size);
    double totale = 0;
    for(int i=0; i < size; i++){
        totale += v[i];
        v[i] = 0;
    }
    return totale;
}

int main(){
    double a[] = {0,1,2,3,4,5,6,7,8,10};
    int n = sizeof(a)/sizeof(double);
    printf("size in main = %d\n", n);
    int b[n];
    printf("%f\n", somma_e_distruggi(a, n));
    printf("%f\n", somma_e_distruggi(a, n));
}
```
