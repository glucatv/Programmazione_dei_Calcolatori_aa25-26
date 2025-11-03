# Esercizio per il fine settima: soluzione

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


```python
def intersezione(L0, L1):
    """
    Parametri: L0 e L1, due liste
    Ritorna una nuova lista contenente tutti i valori presenti sia in L0 che in L1;
        la lista ritornata non contiene duplicati
    """

    #  n, m = len(L0), len(L1)

    I = []


    for x in L0:                    # per n volte
        if x in L1 and x not in I:  # O(m) + O(|I|) tempo; 
            I.append(x)             # O(1) tempo

    return I

    # assumendo m==n
    # complessità temporale O(n**2)
    # complessità spaziale extra (rispetto a input e output): O(1)
    
```

La complessità spaziale è data dalla quantità di spazio extra rispetto a input ed output della soluzione in funzione della dimensione dell'input. Le liste di input e quella di output non devono essere considerate.


```python
a = [1,2,3,2,4, 5]
b = [2, 6, 8, 1, 5]

print( intersezione(a, b) )
```

    [1, 2, 5]
    


```python
def intersezione_debole(L0, L1):
    """
    Parametri: L0 e L1, due liste con elementi non ripetuti
    Ritorna una nuova lista contenente tutti i valori presenti sia in L0 che in L1;
        la lista ritornata non contiene duplicati
    """

    #  n, m = len(L0), len(L1)

    I = L0[:]                     # O(n) tempo e O(n) spazio


    for i, x in enumerate(I):    # per n volte             
        if x not in L1:          # O(n) nel caso peggiore
            del( I[i] )          # O(n) nel caso peggiore

    return I

    # assumendo m==n
    # complessità temporale: O(n**2) nel caso peggiore
    # complessità spaziale extra (rispetto a input e output): O(n)
    
```

In questo caso la complessità spaziale è lineare in quanto viene eseguita una copia della lista `L0` e `I`, al termine della funzione, potrebbe essere vuota.


```python
a = [1,3,2,4, 5]
b = [2, 6, 8, 1, 5]

print( intersezione_debole(a, b) )
```

    [1, 2, 5]
    

# Ricorsione

La seguente è una funzione ricorsiva in quanto è definita in termini di una istanza di se stessa (ma con diverso input). La convergenza della funzione è garantita: dopo `n` chiamate ricorsive la catena di chiamate giunge al *caso base* che viene risolto direttamente, senza ricorsione.


```python
def fattoriale( n ):
    """
    Parametro: n un intero >= 1
    Ritorna n! = n(n-1)(n-2)...2 se n > 1; 1 se n==1
    """

    # ritorna n*fattoriale(n-1) se n > 1
    # 1 altrimenti

    if n == 1:
        return 1
    else:
        return n*fattoriale(n-1)
```


```python
print( fattoriale(4) )
```

    24
    

## Lo stack delle chiamate *call stack*

Ad ogni chiamata di funzione, viene creato un nuovo ambiente (o *frame*) per la funzione che viene inserito in cima allo stack delle chiamate. Questo contiene tutte le informazioni necessarie all'esecuzione della funzione ed alla interazione di questa con l'esterno. Quando una funzione termina, il proprio frame è rimosso dallo stack e l'output della funzione viene ritornato al frame della funzione chiamante.

Eseguire il seguente codice su  [Python Tutor](https://pythontutor.com/).


```python
def cumsum(a):
    for i in range(1, len(a)):
        a[i] = a[i-1] + a[i]
        
a = [1,2,3,4,5]
cumsum(a)
print(a)
```

La funzione `range` quando invocata con due parametri, inizia a generare interi a partire dal valore del primo parametro.

Eseguire la funzione  `fattoriale` su [Python Tutor](https://pythontutor.com/).

$$
\frac{1}{n}
$$

# Esercizi

**1.** La funzione `range` accetta un terzo parametro, anche esso intero. Accedendo alla documentazione ufficiale, spiegare il comportamento del terzo parametro e scrivere un esempio di utilizzo.

**2.** Implementare in modo ricorsivo la seguente funzione

```python
    def argmax( L ):
        """
        Parametri: L una lista di valori confrontabili tra di loro
        Ritorna: se |L| > 0, la posizione del massimo in L, altrimenti None
        """
```
