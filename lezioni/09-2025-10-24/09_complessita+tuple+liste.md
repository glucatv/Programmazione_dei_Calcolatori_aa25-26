# Complessità computazionale

Una misura di quante risorse (come tempo o memoria) un algoritmo richiede per risolvere un problema, in funzione della dimensione dell’input.

- Complessità temporale: legata al numero di operazioni **elementari** eseguite dall'algoritmo
- Complessità spaziale: quantità di memoria utilizzata


```python
a = "itopinonavevanonipoti"*10000
n = len(a)
print("x" == a[0])  # operazione elementare: tra scalari di tipo int, float, bool
print("x" in a)     # nasconde fino a n operazioni elementari
```

    False
    False
    

Esempio


```python
# INPUT
a = "itopinonavevanonipoti"
n = len(a)

# Preambolo
i = 0
sembra_palindroma = True

# Parte centrale
while i < n/2 and sembra_palindroma:
    if a[i] != a[-i-1]: # coppia di caratteri simmetrici
        sembra_palindroma = False
    else:
        i += 1

# Conclusioni
print(sembra_palindroma)
```

    True
    

Calcoliamo la complessità temporale del programma in funzione di `n`.

Assumiamo `a` palindroma

- sia `c0` il costo del preambolo
- sia `c1` il costo delle conclusioni
- sia `c` il costo costo del corpo del while (solo il blocco di)

`c0`, `c1` e `c` non dipendono da `n`: sono **costanti**.

Costo totale:

$T(n) = c0 + c1 + c2\cdot n/2$ è una funzione lineare in $n$, diciamo che il tempo di calcolo cresce linearmente in $n$. Oppure, la complesità temporale del programma è lineare in $n$.

Per descrivere questo comportamento con $n$ che cresce *asintoticamente*, si usa la notazione O-grande che semplifica una funzione tenendo solo il termine che cresce più velocemente al crescere di $n$, ignorando costanti e termini più piccoli..

Quindi si dice che $T(n)$ è $O(n)$ (O-grande di $n$) per dire che la crescita di $T(n)$ è al più lineare in $n$.

Se `a` non palindroma

$T(n) \leq c0 + c1 + c2\cdot n/2$

$T(n)$ è $O(n)$ nel caso peggiore.

Nell'analisi della complessità si considera solitamente il caso peggiore, talvolta il caso medio.

**Complessità del caso medio**: è la media dei costi di tutti i possibili casi, nel nostro caso

$$T_m(n) = \frac{1+2+\ldots+n/2}{n/2}$$

Poiché $1+2+...+(k-1)+k = (k+1)k/2$ allora

$$T_m(n) = \frac{\left(\frac{n}{2}+1\right)\frac{n}{4}}{n/2} = \Big(\frac{n}{2}+1\Big)\frac{1}{2}$$

che è $O(n)$

Altro esempio: se $T(n) = c0 + c1\cdot n + c2\cdot n^2$ allora la crescita di $T(n)$ sarebbe $O(n^2)$

# Tupla


```python
n, i = 10, 0

print(n, i)

# una tupla
t = 10, 0  #  # impacchettamento, unpacking

print(type(t))

print(t)

# per le tuple sono definite tutte le operazioni sulle stringhe, come le stringhe sono immutabili

n, i = t # spacchettamento, packing

print(n, i)

t = (0, 3.14, ('python', 0, 'stringa'), 9)

print(t[0]) # indicizzazione
```

    10 0
    <class 'tuple'>
    (10, 0)
    10 0
    

# Lista

Struttura dati dinamica. Oltre a tutte le operazioni disponibili per le tuple, si possono modificare, aggiungere o cancellare elementi.


```python
a = [] # lista vuota
b = [0, 3.14, ('python', 0, 'stringa'), 9, [1,2,3] ]

print(b[2])

b[2] = 'nuovo valore'

print(b)

del(b[2])

print(b)

b.append('ultimo elemento')

print(b)
```

    ('python', 0, 'stringa')
    [0, 3.14, 'nuovo valore', 9, [1, 2, 3]]
    [0, 3.14, 9, [1, 2, 3]]
    [0, 3.14, 9, [1, 2, 3], 'ultimo elemento']
    

# Esercizi per il fine settimana

1. Sia `n` una variabile intera, scrivere un programma che crei una lista contenente i primi `n` interi.

2. Sia `a` una lista contenente soltanto numeri, si costruisca la lista delle somme parziali di `a`, ovvero una lista, denominata `somme` della stessa dimensione di `a` tale che `somme[i]` contiene la somma dei primi `i+1` elementi in `a`.

Nel risolvere gli esercizi si utilizzino soltanto gli strumenti fin qui introdotti a lezione.
