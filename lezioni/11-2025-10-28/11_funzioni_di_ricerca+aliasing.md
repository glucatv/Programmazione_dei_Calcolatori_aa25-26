# Esercizio

Si scriva una funzione `argfind` che prende in input una lista di numeri `L` e un valore `k` e restituisce la posizione della prima occorrenza di `k` in `L`. Se `L` non contiene `k`, la funzione restituisca `-1`. 


```python
L = [2,1.9,4,6,7,4.3,2,9,2]
k = 0

n = len(L)

for i in range(n):
    if k == L[i]:
        #return i
        print(i)
        break # esce dal ciclo più interno

print(i)
```

    8
    


```python
def argfind(L, k):
    """
    Parametri: L una lista di numeri
                k un valore
    Ritorna i tale che L[i] == k oppure -1 se tale i non esiste
    """
    n = len(L)

    for i in range(n): # al più n volte
        if k == L[i]: # costo costante
            return i
    
    return -1

    # complessità temporale O(n) nel caso peggiore
    # nel caso migliore? k in testa, O(1)
    # nel caso medio? O(n), vedere conti per la soluzione al problema stringa palindroma 
```


```python
a = [2,1.9,4,6,7,4.3,2,9,2]
print( argfind(a, 4) )
print( argfind(a, 0) )
```

    2
    -1
    


```python
print(max(a), min(a))
```

    9 1.9
    


```python
def argmax(L):
    return argfind(L, max(L))
```


```python
print( a[argmax(a)] )
```

    9
    


```python
def argmax(L):

    cur_max, pos = None, None
    
    for i, x in enumerate(L): # unpacking
        if  cur_max == None or x > cur_max:
            cur_max, pos = x, i

    return pos
```


```python
a = [2,1.9,4,6,7,4.3,2,9,2]
print( a[argmax(a)] )
```

    9
    


```python
a = [2,1.9,4,6,7,4.3,2,9,2]
b = a # aliasing, b è un alias di a. a e b legati alla stessa lista
b[0] = None
print( a[0] )
```

    None
    


```python
a = [2,1.9,4,6,7,4.3,2,9,2]
c = a[:] # clonazione
c[0] = None
print( a[0] )
```

    2
    


```python
def attila( L ):
    for i in range(len(L)):
        L[i] = None
```


```python
a = [2,1.9,4,6,7,4.3,2,9,2]
attila(a)
print(a)
```

    [None, None, None, None, None, None, None, None, None]
    

# Esercizi

**1.** Scrivere la docstring della seguente funzione:

```python
    def argmax(L):

        cur_max, pos = None, None
        
        for i, x in enumerate(L):
            if  cur_max == None or x > cur_max:
                cur_max, pos = x, i

        return pos
```

**2.** Scrivere una funzione che abbia la seguente specifica

```python
    def second_max( L ):
        """
        Parametri: L una lista di numeri
        
        Ritorna il secondo valore più grande della lista L;
        se la lista contiene almeno due elementi, None altrimenti.
        
        Nel caso di due massimi, la funzione ritorna il massimo

        Esempi:
        
        se L = [3, 1, 4, 2, 0], la funzione ritorna 3
        se L = [3, 1, 4, 2, 4], la funzione ritorna 4

        """
```
