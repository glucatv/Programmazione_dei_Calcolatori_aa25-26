
# Allocazione dinamica di stringhe

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrCat(char *, char*);

int main(){
    char str0[] = "programmazione";
    char str1[] = " dei calcolatori";
    char *str2;

    //strcat(str0, str1); ///  PERICOLO!!!! 
    //printf("%s\n", str0);

    str2 = StrCat(str0, str1);
    printf("%s\n", str2);

}
```

La funzione `strcat` richiede che l'array su cuoi eseguire la concatenazione abbia memoria sufficiente. La prossima funzione gestisce tutto in modo dinamico: date due stringhe, ritorna una nuova stringa contenente la concatenazione delle due.

```C
char *StrCat(char *s0, char *s1){
    int len_s0 = strlen(s0);
    int len_s1 = strlen(s1);
    char *cat = malloc((len_s0+len_s1+1)*sizeof(char));
    

    strcpy(cat, s0);
    strcat(cat, s1);

    return cat;
}
```

Allocare l'array `cat` in questo modo

```C
char cat[len_s0+len_s1+1];
```

non è corretto perché la funzione ritornerebbe l'indirizzo di una variabile locale, `cat`, che al termine della funzione viene deallocata. La memoria allocata con `malloc` (e `realloc`) viene deallocata esplicitamente chiamando una apposita funzione (`free`), oppure al termine del programma.

Al posto di `strcat(cat, s1)` è piu conveniente usare `strcpy(cat+len_s0, s1)`. Il perché alla prossima lezione.

