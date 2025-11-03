# Logaritmo intero in base 2


```python
n = 13

n_copia = n # preserviamo il valore originale di n operando su una sua copia
k = 0

while n_copia >= 2:
    print("n_copia = ", n_copia, "type(n_copia) = ", type(n_copia))
    n_copia /= 2 # equivalente a n_copia = n_copia/2
    k = k+1 # k += 1

print("Logaritmo intero in base 2 di", n, "=", k)
```

    n_copia =  13 type(n_copia) =  <class 'int'>
    n_copia =  6.5 type(n_copia) =  <class 'float'>
    n_copia =  3.25 type(n_copia) =  <class 'float'>
    Logaritmo intero in base 2 di 13 = 3
    


```python
n = input("Digita qualcosa: ")
print(n)
print(type(n))
```

    13
    <class 'str'>
    


```python
n = input("Digita un numero: ")

n_copia = int(n) # funzione che ritorna il valore intero in n
# altre funzioni di conversione: float(), str() 

k = 0

while n_copia >= 2:
    n_copia /= 2 # equivalente a n_copia = n_copia/2
    k = k+1 # k += 1

print("Logaritmo intero in base 2 di", n, "=", k)
```

    Logaritmo intero in base 2 di 7 = 2
    


```python
n = input("Digita un numero: ") # ritorna una stringa

print(type(n))
```

    <class 'str'>
    

# Stringhe


```python
a = "abcdefgh"

print( len(a) )

x = a[2]

print( x, type(x) )

```

    8
    c <class 'str'>
    

**Problema**. Stampare una stringa in verticale


```python
a = "abcdefgh"

i = 0
# i = 0.0  # NO, perché float non può essere usato come indice

while i < len(a):
    print(a[i])
    i += 1


```

    a
    b
    c
    d
    e
    f
    g
    h
    


```python
a = "abcdefgh"

for x in a:
    print(x)
```

    a
    b
    c
    d
    e
    f
    g
    h
    


```python
a = "abcdefgh"

for i in range(len(a)):
    print( a[i] ) # indicizzazione
```

    a
    b
    c
    d
    e
    f
    g
    h
    


```python
a = "abcdefgh"

for i, x in enumerate(a):
    print( i, x )
```

    0 a
    1 b
    2 c
    3 d
    4 e
    5 f
    6 g
    7 h
    


```python
a = "123"
b = "abcd"
c = a+b # concatenazione
d = 3*b # ripetizione, d = b*3 è equivalente. Il numero DEVE essere int
print(c)
print(d)

```

    123abcd
    abcdabcdabcd
    

**Esercizio**: Dato un intero n (chiedere all'utente), disegnare un quadrato nxn con asterischi. Esempio n = 3

```
***
***
***
```


```python
n = int( input("Digita un intero: ") )

riga = "*"*n

for _ in range(n):
    print( riga )
```

    **********
    **********
    **********
    **********
    **********
    **********
    **********
    **********
    **********
    **********
    

Come sopra ma solo perimetro.


```python
n = int( input("Digita un intero: ") )

riga_piena = "*"*n
riga_centrale = "*" + " "*(n-2) + "*"

print(riga_piena)

for _ in range(n-2):
    print(riga_centrale)

if n > 1:
    print(riga_piena)

```

    *******
    *     *
    *     *
    *     *
    *     *
    *     *
    *******
    

# Esercizi per il finesettimana

1. Scrivere un programma che acquisisce un intero in input e stampa la somma di cifre che lo compongono. Ad esempio se l'utente digita `124`, il programma deve stampare `7`.

2. Scrivere un programma che acquisisce due stringhe in input e le stampa allineandole al centro. Ovvero se le stringhe sono `0123456789` e `abc`, il programma deve stampare

```
            0123456789
               abc
```
