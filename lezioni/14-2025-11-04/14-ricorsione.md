# Esercizi

**1.** La funzione `range` accetta un terzo parametro, anche esso intero. Accedendo alla documentazione ufficiale, spiegare il comportamento del terzo parametro e scrivere un esempio di utilizzo.



```python
help(range)
```

    Help on class range in module builtins:
    
    class range(object)
     |  range(stop) -> range object
     |  range(start, stop[, step]) -> range object
     |
     |  Return an object that produces a sequence of integers from start (inclusive)
     |  to stop (exclusive) by step.  range(i, j) produces i, i+1, i+2, ..., j-1.
     |  start defaults to 0, and stop is omitted!  range(4) produces 0, 1, 2, 3.
     |  These are exactly the valid indices for a list of 4 elements.
     |  When step is given, it specifies the increment (or decrement).
     |
     |  Methods defined here:
     |
     |  __bool__(self, /)
     |      True if self else False
     |
     |  __contains__(self, key, /)
     |      Return bool(key in self).
     |
     |  __eq__(self, value, /)
     |      Return self==value.
     |
     |  __ge__(self, value, /)
     |      Return self>=value.
     |
     |  __getattribute__(self, name, /)
     |      Return getattr(self, name).
     |
     |  __getitem__(self, key, /)
     |      Return self[key].
     |
     |  __gt__(self, value, /)
     |      Return self>value.
     |
     |  __hash__(self, /)
     |      Return hash(self).
     |
     |  __iter__(self, /)
     |      Implement iter(self).
     |
     |  __le__(self, value, /)
     |      Return self<=value.
     |
     |  __len__(self, /)
     |      Return len(self).
     |
     |  __lt__(self, value, /)
     |      Return self<value.
     |
     |  __ne__(self, value, /)
     |      Return self!=value.
     |
     |  __reduce__(...)
     |      Helper for pickle.
     |
     |  __repr__(self, /)
     |      Return repr(self).
     |
     |  __reversed__(...)
     |      Return a reverse iterator.
     |
     |  count(...)
     |      rangeobject.count(value) -> integer -- return number of occurrences of value
     |
     |  index(...)
     |      rangeobject.index(value) -> integer -- return index of value.
     |      Raise ValueError if the value is not present.
     |
     |  ----------------------------------------------------------------------
     |  Static methods defined here:
     |
     |  __new__(*args, **kwargs)
     |      Create and return a new object.  See help(type) for accurate signature.
     |
     |  ----------------------------------------------------------------------
     |  Data descriptors defined here:
     |
     |  start
     |
     |  step
     |
     |  stop
    
    


```python
for i in range(10,4,-1):
    print(i)
```

    10
    9
    8
    7
    6
    5
    

**2.** Implementare in modo ricorsivo la seguente funzione

```python
    def argmax( L ):
        """
        Parametri: L una lista di valori confrontabili tra di loro
        Ritorna: se |L| > 0, la posizione del massimo in L, altrimenti None
        """
```


```python
def argmax( L, i ):
    """
    Parametri: L una lista di valori confrontabili tra di loro, un indice della lista (i<n)
    Ritorna la posizione del massimo tra gli elementi L[i], L[i+1],...,L[n-1] se n > 0, altrimenti None
    """
    n = len(L)
    if n == 0:
        return None
    if i == n-1:
        return i

    p = argmax( L, i+1 )
    if L[i] > L[p]:
        return i
    else:
        return p
```


```python
a = [ 11, 0, 4, 1, 2, 8, 10]
print( argmax(a, 0) )
```

    0
    

Sia $T(n)$ il numero di operazioni eseguite dalla funzione su una sottolista di dimensione `n`. Allora per opportune costanti $c_0$ e $c_1$:

- $T(n) = c_0$ se $n < 2$
- $T(n) = c_1 + T(n-1)$ altrimenti

Sviluppando, $T(n) = (n-1)c_0 + c_1$ che è $O(n)$.

Lo spazio extra occupato è dato dal numero massimo di frame sullo stack delle chiamate, ovvero $n$. Quindi 

- Complessità temporale e spaziale: $O(n)$

# Clonazione profonda

Clonazione semplice


```python
a = [1,2,3,4,5,7]
b = a[:]
```

La clonazione di una lista crea una copia degli alias


```python
L0 = [ [0,1], [2,3], 4 ]
L1 = L0[:]

L1[0][0] = "uno"

print(L0, L1)
```

    [['uno', 1], [2, 3], 4] [['uno', 1], [2, 3], 4]
    

Le liste al secondo livello non vengono copiate. Questa soluzione risolve il problema al secondo livello, ma questo resta sui livelli successivi.


```python
L1 = []

for x in L0:
    if type(x) == list:
        L1.append(x[:])
    else:
        L1.append(x)
```

La *clonazione profonda* richiede la copia della lista e di tutte le eventuali sottoliste annidate. Si risolve con la tecnica della ricorsione. 

# Esercizio

L'implementazione ricorsiva della funzione `argmax` non rispetta le specifiche indicate. Dire perché e proporre una soluzione ricorsiva che le rispetti.
