# Esercizi per il fine settimana: soluzioni

**1.** Implementare la seguente funzione

```python
    def lower(a):
        """
        Parametro: a, una stringa
        Ritorna una nuova stringa identica ad a, tranne per il fatto
            che tutte le lettere minuscole sono sostituite dalle
            corrispondenti lettere maiuscole
        """
```

Per risolvere il problema si utilizzino le funzioni `ord` e `chr` (vedere la documentazione) e si consideri il metodo delle stringhe `join` per limitare i costi computazionali.

Non sono ammesse altre funzioni o metodi non trattati a lezione.

*Soluzione*



```python
def lower(a):
        """
        Parametro: a, una stringa
        Ritorna una nuova stringa identica ad a, tranne per il fatto
            che tutte le lettere minuscole sono sostituite dalle
            corrispondenti lettere maiuscole
        """

        # n = len(a)

        lower_a = ""
        for c in a: # per n volte
            if c >= "A" and c <= "Z":
                 nuovo_c = chr(ord("a")+ord(c)-ord("A"))
            else:
                 nuovo_c = c
            lower_a += nuovo_c   # complessità temporale, O( len(lower_a) ); complessità spaziale, O( len(lower_a) )
        return lower_a

        # complessità temporale O(n**2); complessità spaziale O(n)

testo = "PrograMMazioNe"
print( lower(testo) )

```

    programmazione



```python
def lower(a):
        """
        Parametro: a, una stringa
        Ritorna una nuova stringa identica ad a, tranne per il fatto
            che tutte le lettere minuscole sono sostituite dalle
            corrispondenti lettere maiuscole
        """

        # n = len(a)

        lower_a = []
        for c in a: # per n volte
            if c >= "A" and c <= "Z":
                 nuovo_c = chr(ord("a")+ord(c)-ord("A"))
            else:
                 nuovo_c = c
            lower_a.append(nuovo_c)   # complessità temporale, O( 1 ); complessità spaziale, O( 1 )
        return "".join(lower_a)

        # complessità temporale O(n); complessità spaziale O(n)

testo = "PrograMMazioNe"
print( lower(testo) )
```

    programmazione


**2.** Implementare la seguente funzione

```python
    def moda(L):
        """
        Parametro: L, una lista di interi
        Ritorna l'elemento più fraquente in L
        """
```

*Soluzione*


```python
def moda(L):
    """
    Parametro: L, una lista di interi
    Ritorna l'elemento più fraquente in L
    """

    occ = {}
    for e in L: # per n=len(L) volte
        occ[e] = occ.get(e, 0)+1
        # Equivalente a ...
        #if e in occ:
        #    occ[e] += 1
        #else:
        #    occ[e] = 1
        
        
    return max(occ.items(), key=lambda t: t[1])[0]

    # Equinvalente a...
    #k_max = None
    #for k in occ: # al massimo n volte
    #    if k_max == None or occ[k] > occ[k_max]:
    #        k_max = k

    #return k_max

    

    # complessità temporale: O(n) sempre; complessità spaziale O(n) nel caso peggiore

a = [1, 4, 4, 100000, 6]
moda(a)
```




    4



**3.** Consultando la documentazione dire quali dei seguenti dati possono essere utilizzati come chievi in un dizionario: `str`, `list`, `tuple`, `dict`, `set`.

*Soluzione*: i tipi immotabili possono essere usati come chiavi, gli altri no.

# Preliminare sul linguaggio C

Traduzione in C dell'algoritmo di Archimede per l'approssimazione di $\pi$.

Versione in Python:

```python
L_i, L_c = 2**0.5, 2
iter_max = 10
n = 4

for _ in range(iter_max):
    p_i, p_c = n*L_i/2, n*L_c/2
    print(n, p_i, p_c)
    L_i = (2 - (4-L_i**2)**0.5)**0.5
    L_c = 2*L_i/(4-L_i**2)**0.5
    n *= 2
```

Questa è una funzione C, chiamata nella funzione `main`,  che traduce il codice precedente.

```C
int archimede(){
    float L_i = sqrt(2), L_c = 2;
    int c = 0, iter_max = 10;
    int n = 4;
    float p_i, p_c;

    while (c < iter_max){
        p_i = n*L_i/2;
        p_c = n*L_c/2;
        printf("%f %f\n", p_i, p_c);
        L_i = sqrt((2-sqrt(4-L_i*L_i)));
        L_c = 2*L_i/sqrt(4-L_i*L_i);
        c += 1;
        n *= 2;
    }
}

int main(){
    archimede();
}
```

 Il codice può essere copiato in un file e compilato nel seguente modo

```bash
gcc nomefile.c -lm
```
