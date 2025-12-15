
# Aritmetica dei puntatori

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrCat(char *, char*);
```

```C
int main(){
    char str0[] = "programmazione";
    char str1[] = " dei calcolatori";
    char *str2;

    str2 = StrCat(str0, str1);
    printf("%s\n", str2);
    free(str2);


    printf("%s\n", str0+1); // indirizzo del byte successivo

    char str3[] = "012";
    strcpy(str0+1, str3); //  copia a partire dal secondo byte di str0
    printf("%s\n", str0);

    printf("%c\n", *(str1+5) ); // equivalente a printf("%c\n", str1[5] )

    int a[10] = {3,1,2};
    printf("%d\n", *(a+2) );

    for(int i; i < 10; i++){
        printf("%d\n", *(a+i) );
    }
}
```

Se `p` è un puntatore ad un array, `p + 2` è la posizione del terzo elemento puntato da `p`. L'indirizzo effettivo dipende dalla dichiarazione di `p`, ovvero dal tipo dell'elemento puntato da `p`.

```C
char *StrCat(char *s0, char *s1){
    int len_s0 = strlen(s0);
    int len_s1 = strlen(s1);
    char *cat = malloc((len_s0+len_s1+1)*sizeof(char));
    

    strcpy(cat, s0);
    strcpy(cat+len_s0, s1); // cat+len_s0 è l'indirizzo dell'elemento len_s0-esimo di cat
    return cat;
}
```

# Acquisizione di input e conversione

```C
int main(){
    char testo[100];
    float pi;
    printf("Digita un testo qualsiasi: ");
    scanf("%s", testo);
    printf("%s\n", testo);
    printf("Digita le prime 3 cifre di pi greco: ");
    scanf("%f", &pi);
    printf("%f\n", pi);
    int giorno, mese, anno;
    printf("Data di nascita g-m-a: ");
    int conversioni = scanf("%d-%d-%d", &giorno, &mese, &anno);
    if (conversioni == 3){
        printf("Giorno: %d\n", giorno);
        printf("Mese:   %d\n", mese);
        printf("Anno:   %d\n", anno);
    }
    char stringa_da_convertire[] = "15-12-2025";
    conversioni = sscanf(stringa_da_convertire, "%d-%d-%d", &giorno, &mese, &anno);
    if (conversioni == 3){
        printf("Giorno: %d\n", giorno);
        printf("Mese:   %d\n", mese);
        printf("Anno:   %d\n", anno);
    }
}
```
