# Merge sort

```python
def merge_sort(L, lx, rx):
    """
    Parametro: L, una lista di elementi confrontabili con <=
        lx < rx, due indici in L
    Ritorna: None

    Effetto collaterale: ordina gli elementi di L dalla posizione lx a rx-1
    """
    if lx >= rx-1:
        return None
    cx = (lx+rx)//2 # divisione intera

    merge_sort(L, lx, cx)
    merge_sort(L, cx, rx)
    merge(L, lx, cx, rx)
```

*Complessità temporale*: se $|L|=n$, abbiamo $\log_2 n$ livelli di ricorsione, ogni livello ha costo $O(n)$, quindi $O(n \log_2 n)$ costo totale (per i dettagli vedere libro o dispense)

# Esercizio

```python
def merge(L, lx, cx, rx):
    """
    Parametri: L una lista di elementi confrontabili con <=
        lx <= cx < rx, tre indici di L e tali che
        L[lx] <= L[lx+1] <= ... <= L[cx-1] e
        L[cx] <= L[cx+1] <= ... <= L[rx-1]
    Output: None

    Effetto collaterale: al termine della funzione
    L[lx] <= L[lx+1] <= ... <= L[rx-1]
    """
```


```python
def merge(L, lx, cx, rx):
    """
    Parametri: L una lista di elementi confrontabili con <=
        lx <= cx < rx, tre indici di L e tali che
        L[lx] <= L[lx+1] <= ... <= L[cx-1] e
        L[cx] <= L[cx+1] <= ... <= L[rx-1]
    Output: None

    Effetto collaterale: al termine della funzione
    L[lx] <= L[lx+1] <= ... <= L[rx-1]
    """

    M = []

    i, j = lx, cx

    while i < cx and j < rx:
        if L[i] <= L[j]:
            m = L[i]
            i += 1
        else:
            m = L[j]
            j += 1
        M.append(m)

    while i < cx:
        M.append(L[i])
        i += 1

    while j < rx:
        M.append(L[j])
        j += 1

    for i in range(len(M)):
        L[lx+i] = M[i]

    # complessità temporale O(rx-lx), nel caso peggiore O( len(L) )
    # complessità spaziale O(rx-lx), nel caso peggiore O( len(L) )
```


```python
a = [10,3]
merge(a, 0, 1, 2)
print(a)
```

    [3, 10]
    

Ora abbiamo tutto il necessario per definire la funzione `merge_sort`.


```python
def merge_sort(L, lx, rx):
    """
    Parametro: L, una lista di elementi confrontabili con <=
        lx < rx, due indici in L
    Ritorna: None

    Effetto collaterale: ordina gli elementi di L dalla posizione lx a rx-1
    """
    
    if lx >= rx-1:
        return None
    cx = (lx+rx)//2 # divisione intera

    merge_sort(L, lx, cx)
    merge_sort(L, cx, rx)
    merge(L, lx, cx, rx)

    # n = len(L)
    # complessità temporale: O(n log n), sempre
    # complessità spaziale: O(n) per la lista in merge + O(log n) per lo stack delle chiamate. In totale O(n)
```


```python
a = [6,2,3,1,9,0,1,2,6,5,3,8,1]
merge_sort(a, 0, len(a))
print(a)
```

    [0, 1, 1, 1, 2, 2, 3, 3, 5, 6, 6, 8, 9]
    

La versione che segue implementa le seguenti migliorie.

- Rende facoltativi i parametri `lx`e `rx`; se omessi viene ordinata l'intera lista
- Permette di personalizzare il criterio di ordinamento introducendo una funzione opzionale `key` che definisce il valore dell'elemento della lista da usare nel confronto all'interno della funzione `merge`. Di default questa funzione è l'identità


```python
def merge_sort(L, key=lambda x:x, lx=0, rx=None):
    """
    Parametro: L, una lista di elementi confrontabili con <=
        lx < rx, due indici in L
    Ritorna: None

    Effetto collaterale: ordina gli elementi di L dalla posizione lx a rx-1;
    
    se rx è None, ordina fino all'ultimo elemento della lista
    """

    def merge(L, lx, cx, rx):
        """
        Parametri: L una lista di elementi confrontabili con <=
            lx <= cx < rx, tre indici di L e tali che
            L[lx] <= L[lx+1] <= ... <= L[cx-1] e
            L[cx] <= L[cx+1] <= ... <= L[rx-1]
        Output: None

        Effetto collaterale: al termine della funzione
        L[lx] <= L[lx+1] <= ... <= L[rx-1]
        """

        M = []

        i, j = lx, cx

        while i < cx and j < rx:
            if key(L[i]) <= key(L[j]):
                m = L[i]
                i += 1
            else:
                m = L[j]
                j += 1
            M.append(m)

        while i < cx:
            M.append(L[i])
            i += 1

        while j < rx:
            M.append(L[j])
            j += 1

        for i in range(len(M)):
            L[lx+i] = M[i]

        # complessità temporale O(rx-lx), nel caso peggiore O( len(L) )
        # complessità spaziale O(rx-lx), nel caso peggiore O( len(L) )

    if rx == None:
        rx = len(L)

    if lx >= rx-1:
        return None
    cx = (lx+rx)//2 # divisione intera

    merge_sort(L, key, lx, cx)
    merge_sort(L, key, cx, rx)
    merge(L, lx, cx, rx)

    # n = len(L)
    # complessità temporale: O(n log n), sempre
    # complessità spaziale: O(n) per la lista in merge + O(log n) per lo stack delle chiamate. In totale O(n)

```

La valore di default viene definito con una funzione `lambda`. Queste sono funzioni anonime e brevi, molto adatte ad essere argomento di funzione. Ecco un esempio


```python
f = lambda x: x**2

print(f(12))
```

    144
    

Ordinare una lista di stringhe per lunghezza...


```python
a = ["zero", "uno", "due", "tre", "quattro", "cinque"]
merge_sort( a, len )
print(a)
```

    ['uno', 'due', 'tre', 'zero', 'cinque', 'quattro']
    

Ordinarle in base al secondo carattere...


```python
a = ["zero", "uno", "due", "tre", "quattro", "cinque"]
merge_sort(a, key=lambda x:x[1])
print(a)
```

    ['zero', 'cinque', 'uno', 'tre', 'due', 'quattro']
    

Ordinamento di default


```python
a = ["zero", "uno", "due", "tre", "quattro", "cinque"]
merge_sort(a)
print(a)
```

    ['cinque', 'due', 'quattro', 'tre', 'uno', 'zero']
    

**Problema** Ordinare una lista di numeri per numero di cifre crescenti (incluso il punto).


```python
a = [3.1416, 4, 2.71, 100]
merge_sort(a, key=lambda x: len(str(x)))
print(a)
```

    [4, 100, 2.71, 3.1416]
    

# Confronto fra tuple (e sequenze)

Si confrontano le tuple elemento per elemento, il valore del confronto è dato dal risultato sui primi elementi in cui queste differiscono.


```python
print( (10, 12) < (8, 1234567) )
print( (10, 12) < (18, 1234567) )
print( (10, 12) < (10, 1234567) )
print( (10, 12) < (10, 12, 0) )
print( (10, "uno") < (10, "due") )
print( (11, 2) < (10, "due") )

# tutto valido anche per liste
```

    False
    True
    True
    True
    False
    False
    

# Esercizio per il fine settimana

Descrivere una invocazione della funzione `merge_sort` che ordina una lista di stringhe per lunghezze crescenti, a parità di lunghezza, in ordine lessicografico.
