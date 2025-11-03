# Operatori bit-a-bit


```python
n = 7

print(n>>1) # shift a sx
print(n<<1) # shift a dx
```

    3
    14
    


```python
a = 6
b = 3

print(a&b) # and bit-a-bit
print(a|b) # or bit-a-bit

```

    2
    7
    

### Tabella operatori aggiornata

| Categoria      | Operatori                                |
|----------------|------------------------------------------|
| Aritmetici     | `+`, `-`, `*`, `/`, `//`, `%`, `**`      |
| Relazionali    | `==`, `!=`, `>`, `<`, `>=`, `<=`         |
| Logici         | `and`, `or`, `not`                       |
| Bit-a-bit      | `&`, `\|`, `>>`, `<<`                    |

**Problema**. Usare operatori bit a bit per calcolare il logaritmo intero in base 2 di `n`.


```python
n = 13

n_copia = n # preserviamo il valore originale di n operando su una sua copia
k = 0

while n_copia >= 2:
    print("n_copia = ", n_copia, "type(n_copia) = ", type(n_copia))
    n_copia = n_copia>>1 # equivale alla divisione intera per 2
    k += 1

print("Logaritmo intero in base 2 di", n, "=", k)
```

    n_copia =  13 type(n_copia) =  <class 'int'>
    n_copia =  6 type(n_copia) =  <class 'int'>
    n_copia =  3 type(n_copia) =  <class 'int'>
    Logaritmo intero in base 2 di 13 = 3
    

# Ancora sulle stringhe

**Problema**. Data una stringa `a`, stampare `True` se la stringa è palindroma (può essere letta da dx a sx o da sx a dx allo stesso modo)

## Slicing e indici negativi


```python
pal = "itopinonavevanonipoti"
a = "0123456789"

print(a[3])

# a[0] = "I" NO, le stringhe sono immutabili

# slicing
print( a[1:6] ) # nuova stringa
print( a[:6]) 
b = a[:]
print(b)
print(a[2:8:2]) # slicing con  step
print(a[8:2:-1])
print(a[::-1])
print(a[-1]) # ultimo carattere
print(a[-2])
print(a[-len(a)]) # primo carattere
```

    3
    12345
    012345
    0123456789
    246
    876543
    9876543210
    9
    8
    0
    

*Soluzione con slicing e step negativo*


```python
print( pal == pal[::-1])
```

    True
    

Soluzione corretta, *elegante*, compatta ma costosa perché:

- Richiede la creazione di una nuova stringa della stessa dimensione di quella di input (consumo di memoria)
- La copia occupa spazio e richiede tempo per le singole operazioni di copia dei caratteri
- Il costo resta elevato anche nel caso estremo in cui il primo e l'ultimo carattere sono diversi.

Una soluzione più efficiente confronta coppie di caratteri simmetrici rispetto al centro della stringa solo fintanto che questi sono uguali. Non c'è occorre nessuna copia.


```python
a = "itopinonavevanonipoti"
#a = "kayak"

i, n = 0, len(a)
sembra_palindroma = True

while i < n/2 and sembra_palindroma:
    if a[i] != a[-i-1]: # coppia di caratteri simmetrici
        sembra_palindroma = False
    else:
        i += 1

print(sembra_palindroma)
```

    True
    

Questa soluzione confronta tutte le coppie solo quando serve, ovvero nel caso in cui la stringa è palindroma. Altrimenti il ciclo viene interrotto in anticipo.
