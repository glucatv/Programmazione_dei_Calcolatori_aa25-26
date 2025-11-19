# Esercizi per il fine settimana: soluzioni

1. Sia `n` una variabile intera, scrivere un programma che crei una lista contenente i primi `n` interi.



```python
n = 10 # input

a = [] # lista vuota. Costo O(1)

for x in range(n): # inserimento in coda degli interi da 0 a n-1
    a.append(x) # costo O(1)

# costo totale O(n)

print(a)

```

    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    


```python
a = list(range(n)) #  funzione di conversione

print(a)
```

    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    


2. Sia `a` una lista contenente soltanto numeri, si costruisca la lista delle somme parziali di `a`, ovvero una lista, denominata `somme` della stessa dimensione di `a` tale che `somme[i]` contiene la somma dei primi `i+1` elementi in `a`.

Nel risolvere gli esercizi si utilizzino soltanto gli strumenti fin qui introdotti a lezione.


```python
a = [6,3,2,4,1,3]

# sia n = len(a), la complessità temporale dipenderà da n

somme = [] # costo O(1)

for x in a:  # per n volte
    if somme == []: # verifica lista vuota, anche con len(somme) == 0, costo O(1)
        somme.append(x) # O(1)
    else:
        c = somme[-1] + x  # valore inserito al passo precedente + x, # O(1) perché indicizzazione richiede tempo costante
        somme.append(c) # O(1)

# tempo totale O(n)

print(somme)
```

    [6, 9, 11, 15, 16, 19]
    

Il costo computazionale, in termini di tempo di calcolo, della soluzione è lineare nella lunghezza della lista in quanto, per `n` volte si eseguono: un confronto con la lista vota (tempo che non dipende dalla lunghezza della lista, indicizzazione e operazioni aritmetiche). Il costo dell'indicizzazione è costante perché gli elementi della lista sono memorizzati in posizioni consecutive di memoria e ogni elemento occupa lo stesso spazio.


```python
def cumsum( L ): # L parametro formale
    '''
    Parmetri: L una lista di numeri (int o float)

    Stampa la lista delle somme comulative
    '''

    somme = [] # variabile locale, visibilità interna alla funzione. Lo sono anche i parametri formali

    for x in L:  # x, variabile locale
        if somme == []: 
            somme.append(x) 
        else:
            c = somme[-1] + x  # c, variabile locale
            somme.append(c) 

    return somme # definisce il risultato, interrompe la funzione
```


```python
a = [6,3,2,4,1,3]
b = cumsum(a) # a, parametro attuale. Assegnato a L al momento dell'esecuzione 
print(b[2])
```

    11
    


```python
help(cumsum)
```

    Help on function cumsum in module __main__:
    
    cumsum(L)
        Parmetri: L una lista di numeri (int o float)
    
        Stampa la lista delle somme comulative
    
    

# Esercizio

Si scriva una funzione `argfind` che prende in input una lista di numeri `L` e un valore `k` e restituisce la posizione della prima occorrenza di `k` in `L`. Se `L` non contiene `k`, la funzione restituisca `-1`. 
