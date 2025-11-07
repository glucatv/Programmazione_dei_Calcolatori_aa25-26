# Esercizio

L'implementazione ricorsiva della funzione `argmax` non rispetta le specifiche indicate. Dire perché e proporre una soluzione ricorsiva che le rispetti.

**Soluzione.** La specifica originale non prevedeva il parametro `i`. Si risolve isolando la ricorsione con una seconda funzione.


```python
def argmax_r( L, i ):
    """
    Parametri: L una lista di valori confrontabili tra di loro, un indice della lista (i < n)
    Ritorna la posizione del massimo tra gli elementi L[i], L[i+1],...,L[n-1] se n > 0, altrimenti None
    """
    n = len(L)
    if n == 0:
        return None
    if i == n-1:
        return i

    p = argmax_r( L, i+1 )
    if L[i] > L[p]:
        return i
    else:
        return p
    

def argmax( L ):
    """
    Parametri: L una lista di valori confrontabili tra di loro
    Ritorna: se |L| > 0, la posizione del massimo in L, altrimenti None
    """
    return argmax_r(L, 0)
```


```python
print( argmax([6,3,1,0,3,10, 5]) )
```

    5
    

Per rendere tutto autocontenuto, possiamo definire la funzione ricorsiva come locale della funzione principale.


```python
def argmax( L ):
    """
    Parametri: L una lista di valori confrontabili tra di loro
    Ritorna: se |L| > 0, la posizione del massimo in L, altrimenti None
    """
    def argmax_r( L, i ):
        """
        Parametri: L una lista di valori confrontabili tra di loro, un indice della lista (i<n)
        Ritorna la posizione del massimo tra gli elementi L[i], L[i+1],...,L[n-1] se n > 0, altrimenti None
        """
        n = len(L)
        if n == 0:
            return None
        if i == n-1:
            return i

        p = argmax_r( L, i+1 )
        if L[i] > L[p]:
            return i
        else:
            return p

    return argmax_r(L, 0)
```


```python
print(argmax([6,3,1,0,3,10, 5]))
```

    5
    

# Clonazione profonda

La soluzione ricorsiva clona ricorsivamente tutti gli elementi della lista di partenza aggiungendoli in fondo alla lista di output.


```python
def deep_cloning( x ):
    """
    Parametro: x una lista, eventualmente contenente liste annidate
    Ritorna una copia profonda di x, ovvero clona x e tutte le sottoliste annidate 
    """

    if type(x) != list:
        return x
    
    C = []

    for e in x:
        C.append( deep_cloning(e) )

    return C
```


```python
a = [[0,[1,2,[3,4]]], [5,[6,[7,8]]]]

b = deep_cloning(a)

print(b)
```

    [[0, [1, 2, [3, 4]]], [5, [6, [7, 8]]]]
    

**Complessità temporale**. Sia `n` il numero complessivo di totale di elementi (liste o scalari) in tutte le sottoliste. L'algoritmo eseguirà una chiamata ricorsica per ognuno di questi elementi. Quindi in totale `n` esecuzioni. Ognuna richiede un numero costante di operazioni, quindi la complessità è `O(n)`.

**Complessità spaziale**. Ogni istanza della funzione occupa uno spazio costante. Lo spazio extra totale è dato dal massimo livello di annidamento che è `n` (`n` liste annidate). Quindi lo spazio totale extra è `O(n)`.

# Ordinamento

Algoritmo Bubble-Sort: alla k-esima iterazione, il k-esimo elementi in ordine di grandezza inversa viene posizionato nella sua posizione finale.


```python
a = [3,12,1,7,4,2,6,7,2,1]
n = len(a)

for c in range(n-1): # per n-1 volte
    for i in range(n-1-c): # per n-1 volte, non è necessario considerare gli ultimi c elementi
        if a[i] > a[i+1]:
            a[i], a[i+1] = a[i+1], a[i]

print(a)

# complessità temporale O(n**2)
# complessità spaziale O(1)
```

    [1, 1, 2, 2, 3, 4, 6, 7, 7, 12]
    

# Esercizi per il fine settimana

* Modificare l'algoritmo Bubble-Sort in modo che il ciclo esterno termini, e quidi l'algoritmo si arresti, non appena la lista risulti ordinata.

* Utilizzare il codice risultante per implementare la funzione con la seguente specifica

```python
    def bubble_sort( L ):
        """
        Parametro: una lista con elementi tutti confrontabili
        Ritorna: None

        Come effetto collaterale, ordina gli elementi di L dal più piccolo al più grande
        """
```

* Calcolare la complesità della funzione.
