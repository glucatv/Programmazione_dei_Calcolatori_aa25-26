# Esercizi

**1.** Implementare la seguente funzione

```python
def ricerca_binaria_lx( L, k):
    """
    Parametri: L, una lista ordinata secondo <=; k un valore
    Ritorna la posizione dell'occorrenza più a sinistra di k in L,
        se k non è presente in L ritorna -1
    """
```


*Soluzione*. Deve essere modificata la condizione di terminazione che deve contenere la condizione che la posizione `cx` sia l'ultima con `k`.


```python
def ricerca_binaria_lx( L, k):
    """
    Parametri: L, una lista ordinata secondo <=; k un valore
    Ritorna la posizione dell'occorrenza più a sinistra di k in L,
        se k non è presente in L ritorna -1
    """
    n = len(L)

    lx, rx = 0, n

    while lx <= rx-1:
        cx =int( (lx+rx)/2 )

        if L[cx] == k and (cx == 0 or L[cx-1] < k): # k piu a sinistra
            return cx
        if k <= L[cx]:
            rx = cx
        else:
            lx = cx+1

    return -1
```


```python
a = [0,0,0,0]
print(ricerca_binaria_lx(a, 0))
```

    0
    


**2.** Implementare la seguente funzione

```python
def unione(L0, L1):
    """
    Parametri: L0 e L1, due liste ordinate rispetto l'operatore <=

    Ritorna: la lista Lu contenente l'unione di L0 e L1. Gli elementi in
        Lu sono ordinati secondo <= e senza ripetizioni
    """
```


```python
def unione(L0, L1):
    """
    Parametri: L0 e L1, due liste ordinate rispetto l'operatore <=

    Ritorna: la lista Lu contenente l'unione di L0 e L1. Gli elementi in
        Lu sono ordinati secondo <= e senza ripetizioni
    """
    Lu = []

    i, j = 0, 0

    while i < len(L0) and j < len(L1):
        if L0[i] <= L1[j]:
            m = L0[i]
            i += 1
        else:
            m = L1[j]
            j += 1
        
        if len(Lu) == 0 or Lu[-1] < m:
                Lu.append(m)

    # una delle due liste è stata processata, aggiungiamo a Lu gli
    # elementi dell'altra lista
    while i < len(L0):
        if len(Lu) == 0 or Lu[-1] < L0[i]:
            Lu.append(L0[i])
        i += 1

    while j < len(L1):
        if len(Lu) == 0 or Lu[-1] < L1[j]:
            Lu.append(L1[j])
        j += 1

    return Lu

    # complessità temporale O(n+m), come intersezione
    # complessità spaziale O(1), come intersezione

a = [0,1,1,4,5,6,6,7,7]
b = [1,2,2,3,6,7,8,9,9]
print(unione(a, b))
```

    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    

# Algoritmo di fusione


```python
def merge(L0, L1):
    """
    Parametri: L0 e L1 liste ordinate
    Output: M, lista ordinata contenente tutti gli elementi di L0 e L1
    """

    M = []

    i, j = 0, 0

    while i < len(L0) and j < len(L1):
        if L0[i] <= L1[j]:
            m = L0[i]
            i += 1
        else:
            m = L1[j]
            j += 1
        M.append(m)

    while i < len(L0):
        M.append(L0[i])
        i += 1

    while j < len(L1):
        M.append(L1[j])
        j += 1

    return M

    # complessità temporale O(n+m), come unione
    # complessità spaziale O(1), come unione
```


```python
a = [0,1,1,4,5,6,6,7,7]
b = [1,2,2,3,6,7,8,9,9]
print(merge(a, b))
```

    [0, 1, 1, 1, 2, 2, 3, 4, 5, 6, 6, 6, 7, 7, 7, 8, 9, 9]
    

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
