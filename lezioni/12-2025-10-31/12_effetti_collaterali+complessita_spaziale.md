# Soluzione esercizi

**Esercizio 1.** Scrivere la docstring della seguente funzione:

```python
    def argmax(L):

        cur_max, pos = None, None
        
        for i, x in enumerate(L):
            if  cur_max == None or x > cur_max:
                cur_max, pos = x, i

        return pos
```

**Prima versione**


```python
def argmax(L):
    """
    Parametri: L, lista di numeri
    Ritorna: la posizione del massimo in L
    """

    cur_max, pos = None, None
    
    for i, x in enumerate(L):
        if  cur_max == None or x > cur_max:
            cur_max, pos = x, i

    return pos
```


```python
a =  ["sette", "Zero", "uno", "sei", "due", "tre", "quattro"]
print( argmax(a) )
```

    1
    


```python
print("sei" > "sette")
```

    False
    


```python
print("una" < "unario")
```

    True
    


```python
print("una" < "Unario")
```

    False
    

Il confronto tra stringhe obbedisce all'ordinamento lessicografico (codifica ASCII). Quindi l'operatore `>` è definito anche tra altri tipi di dato, non necessariamente numerici.

**Seconda versione**


```python
def argmax(L):
    """
    Parametri: L, lista di elementi tutti confrontabili con >
    Ritorna: la posizione del massimo in L
    """

    cur_max, pos = None, None
    
    for i, x in enumerate(L):
        if  cur_max == None or x > cur_max:
            cur_max, pos = x, i

    return pos
```

Se

```python
a =  ["sette", 0, "uno", "sei", "due", "tre", "quattro"]
```

l'esecuzione di `argmax(a)` non rispetta le specifiche perché `a` contiene elementi non confrontabili

**Esercizio 2.** Scrivere una funzione che abbia la seguente specifica

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


```python
def second_max( L ):
        """
        Parametri: L una lista di numeri
        
        Ritorna il secondo valore più grande della lista L;
        se la lista contiene almeno due elementi, None altrimenti.
        
        Nel caso di due massimi, la funzione ritorna il massimo
        """
        if len(L) >= 2:
            p = argmax(L) # O(n) tempo; O(1) spazio extra
            del(L[p])     # O(n) tempo nel caso peggiore; O(1) spazio extra
            return max(L) # O(n) tempo; O(1) spazio extra
       
        # complessità temporale: O(n)
        # complessità spaziale: O(1) <====== spazio extra
        
        return None
```


```python
a = [3, 1, 4, 2, 0]
print( second_max(a) )
print(a)
```

    3
    [3, 1, 2, 0]
    

ATTENZIONE: la funzione non rispetta la specifica; ha **effetti collaterali** perché modifica la lista di input.

Soluzione, clonare la lista di input.


```python
def second_max( L ):
        """
        Parametri: L una lista di numeri
        
        Ritorna il secondo valore più grande della lista L;
        se la lista contiene almeno due elementi, None altrimenti.
        
        Nel caso di due massimi, la funzione ritorna il massimo
        """
        n = len(L)
        if n >= 2:
            L_c = L[:]       # O(n) tempo; O(n) spazio extra  
            p = argmax(L_c)  # O(n) tempo; O(1) spazio extra
            del(L_c[p])      # O(n) tempo nel caso peggiore; O(1) spazio extra
            return max(L_c)  # O(n) tempo; O(1) spazio extra
        
        # complessità temporale: O(n)
        # complessità spaziale: O(n) <====== spazio extra
        
        return None
```


```python
a = [3, 1, 4, 2, 0]
print( second_max(a) )
print(a)
```

    3
    [3, 1, 4, 2, 0]
    

## Complessità spaziale

La soluzione precedente richiede l'utilizzo di una struttura dati la cui dimensione dipende dalla grandezza dell'input. In questo caso la soluzione richiede uno spazio extra lineare nella dimensione dell'input. Si dice che la **complessità spaziale** della soluzione è lineare.


```python
def second_max( L ):
        """
        Parametri: L una lista di numeri

        Ritorna il secondo valore più grande della lista L;
        se la lista contiene almeno due elementi, None altrimenti.

        Nel caso di due massimi, la funzione ritorna il massimo
        """

        n = len(L)
        if n >= 2:
                max1 = max(L[0], L[1])      # O(1) tempo; O(1) spazio extra
                max2 = min(L[0], L[1])      # O(1) tempo; O(1) spazio extra
                for x in L[2:]:             # per n-2 volte; O(n) spazio extra per slicing
                        if x > max1:        # O(1) tempo; O(1) spazio extra
                                max2 = max1
                                max1 = x
                        elif  x > max2:
                                max2 = x
                return max2
        else:
                return None
        
        # Complessità temporale: O(n)
        # Complessità spaziale: O(n), togliendo slicing O(1)
```

Lo slicing non risolve il problema della memoria extra, meglio usare l'indicizzazione 


```python
def second_max( L ):
    """
    Parametri: L una lista di numeri

    Ritorna il secondo valore più grande della lista L;
    se la lista contiene almeno due elementi, None altrimenti.

    Nel caso di due massimi, la funzione ritorna il massimo
    """

    n = len(L)
    if n >= 2:
        max1 = max(L[0], L[1])      # O(1) tempo; O(1) spazio extra
        max2 = min(L[0], L[1])      # O(1) tempo; O(1) spazio extra
        i = 2
        while i < n:                # per n-2 volte;
            x = a[i]             
            if x > max1:        # O(1) tempo; O(1) spazio extra
                max2 = max1
                max1 = x
            elif  x > max2:
                max2 = x
            i += 1
        return max2
    else:
        return None
        
        # Complessità temporale: O(n)
        # Complessità spaziale:  O(1)
```


```python
a = [3, 1, 4, 2, 0]
print( second_max(a) )
print(a)
```

    3
    [3, 1, 4, 2, 0]
    

# Esercizio per il fine settima

Implementare una funzione avente la seguente specifica

```python
    def intersezione(L0, L1):
        """
        Parametri: L0 e L1, due liste
        Ritorna una nuova lista contenente tutti i valori presenti sia in L0 che in L1;
            la lista ritornata non contiene duplicati
        """
```

Analizzare la complessità temporale e spaziale della soluzione proposta.
