# Set


```python
insieme_vuoto = set()
print(insieme_vuoto)

a = set([1,2,1,6,7,5,0,6])
print(a)
print(1 in a)
```

    set()
    {0, 1, 2, 5, 6, 7}
    True



```python
a.add(10)
print(a)
a.remove(5)
print(a)
print(len(a))
```

    {0, 1, 2, 5, 6, 7, 10}
    {0, 1, 2, 6, 7, 10}
    6



```python
n = 500000
m = 100
a = set(list(range(n)))
b = set(list(range(m)))

c = set()

if n < m:
    A, B = a, b
else:
    A, B = b, a

for k in A: # per al più O(n) volte 
    if k in B: # O(1)
        c.add(k) # O(1)

print(c)

# complessità temporale righe 7-9: O( min(n, m) )
```

    {1, 3, 7}



```python
c = a.intersection(b)
# complessità temporale è O( min(n, m) )

d = a.union(b)  # O(n+m)
e = a.difference(b) # ( min(n,m) )

print(c)
print(d)
print(e)
```

    {1, 3, 7}
    {0, 1, 2, 3, 4, 5, 6, 7, 8}
    {8, 2, 6}


| Operazione / Struttura         | string        | tuple         | list          | dict          | set           |
|--------------------------------|---------------|---------------|---------------|---------------|---------------|
| *Indicizzazione*               | `O(1)`        | `O(1)`        | `O(1)`        | N/D           | N/D           |
| *Slicing*                      | `O(k)`        | `O(k)`        | `O(k)`        | N/D           | N/D           |
| *Ricerca*    `in`              | `O(n)`        | `O(n)`        | `O(n)`        | `O(1)`*       | `O(1)`*       |
| *Concatenazione / Unione*      | `O(n+m)`      | `O(n+m)`      | `O(n+m)`      | N/D           | `O(n+m)`      |
| *Inserimento*                  | N/D           | N/D           | `O(n)`        | `O(1)`*       | `O(1)`*       |
| *Inserimento in fondo*         | N/D           | N/D           | `O(1)`*       | N/D           | N/D           |
| *Cancellazione*                | N/D           | N/D           | `O(n)`       | `O(1)`*       | `O(1)`*       |
| *Cancellazione in fondo*       | N/D           | N/D           | `O(1)`*      | N/D           | N/D           |
| *Iterazione*                   | `O(n)`        | `O(n)`        | `O(n)`        | `O(n)`        | `O(n)`        |
| *Lettura lunghezza* `len()`    | `O(1)`        | `O(1)`        | `O(1)`        | `O(1)`        | `O(1)`        |



* `O(1)`* - **complessità ammortizzata**: `n` operazioni hanno costo totale `O(n)`, quindi `O(1)` in media


**Esercizio**: invertire un dizionario


```python
d = {"zero":0, "uno":1, "Uno":1, "due":2, "DUE":2}
d_inv = {}

for k in d:
    if d[k] in d_inv:
        d_inv[d[k]].append(k) # inserire k nella lista della chiave d[k] in d_inv
    else:
        d_inv[d[k]] = [k]

print(d_inv)

```

    {0: ['zero'], 1: ['uno', 'Uno'], 2: ['due', 'DUE']}



```python
d = {"zero":0, "uno":1, "Uno":1, "due":2, "DUE":2}
d_inv = {}

for k, v in d.items():
    if v in d_inv:
        d_inv[v].append(k) # inserire k nella lista della chiave v in d_inv
    else:
        d_inv[v] = [k]

print(d_inv)
```

    {0: ['zero'], 1: ['uno', 'Uno'], 2: ['due', 'DUE']}


altri metodi per iterare sui dizionari


```python
for v in d.values():
    print(v)

for k in d.keys():
    print(k)
```

    0
    1
    1
    2
    2
    zero
    uno
    Uno
    due
    DUE



```python
# print( d['tre'] )   # index error

print(d.get("Uno"))
print(d.get("UNO"))
print( d.get("UNO", 0) )
```

    1
    None
    0



```python
d = {"zero":0, "uno":1, "Uno":1, "due":2, "DUE":2}
d_inv = {}

for k, v in d.items():
    L = d_inv.get(v,[])
    L.append(k)

    d_inv[v] = L

print(d_inv)
```

    {0: ['zero'], 1: ['uno', 'Uno'], 2: ['due', 'DUE']}


# Esercizi per il fine settimana

**1.** Implementare la seguente funzione

```python
    def upper(a):
        """
        Parametro: a, una stringa
        Ritorna una nuova stringa identica ad a, tranne per il fatto
            che tutte le lettere minuscole sono sostituite dalle
            corrispondenti lettere maiuscole
        """
```

Per risolvere il problema si utilizzino le funzioni `ord` e `chr` (vedere la documentazione) e si consideri il metodo delle stringhe `join` per limitare i costi computazionali.

Non sono ammesse altre funzioni o metodi non trattati a lezione.

**2.** Implementare la seguente funzione

```python
    def moda(L):
        """
        Parametro: L, una lista di interi
        Ritorna l'elemento più fraquente in L
        """
```

**3.** Consultando la documentazione dire quali dei seguenti dati possono essere utilizzati come chievi in un dizionario: `str`, `list`, `tuple`, `dict`, `set`.
