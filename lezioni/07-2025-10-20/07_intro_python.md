# Esercizi per il fine settimana: soluzioni

1. Scrivere un programma che acquisisce un intero in input e stampa la somma di cifre che lo compongono. Ad esempio se l'utente digita `124`, il programma deve stampare `7`.


```python
n = input("Digita un numero:")
somma = 0
for x in n:
    somma += int(x)
print(somma)
```

    10
    


```python
n = int(input("Digita un numero:"))
somma = 0

while n != 0:
    somma += n%10    # modulo
    n = int(n/10) # oppure n = n//10, divisione intera

print(somma)

```

    6
    

2. Scrivere un programma che acquisisce due stringhe in input e le stampa allineandole al centro. Ovvero se le stringhe sono `0123456789` e `abc`, il programma deve stampare

```
            0123456789
               abc
```


```python
b = "01234567890"
a = "abc"

spazi = (len(a)-len(b))//2

if spazi >= 0:
    print(a)
    print(" "*spazi+b)

if spazi < 0:
    print(-spazi*" "+a)
    print(b)
```

        abc
    01234567890
    


```python
b = "01234567890"
a = "abc"

spazi = (len(a)-len(b))//2

if spazi >= 0:
    print(a)
    print(" "*spazi+b)
else:
    print(-spazi*" "+a)
    print(b)
```

        abc
    01234567890
    


```python
a = "01234567890"
b = "abc"

if len(a) > len(b):
    spazi_a, spazi_b = 0, (len(a)-len(b))//2
else:
    spazi_a, spazi_b = -(len(a)-len(b))//2, 0

print(" "*spazi_a+a)
print(" "*spazi_b+b)
```

    01234567890
        abc
    

# Riassunto sugli operatori

| Categoria      | Operatori                               |
|----------------|------------------------------------------|
| Aritmetici     | `+`, `-`, `*`, `/`, `//`, `%`, `**`      |
| Relazionali    | `==`, `!=`, `>`, `<`, `>=`, `<=`         |
| Logici         | `and`, `or`, `not`                       |



```python
a = "ProGrammAzione Dei calc0lat0r1"
minuscole = 0
for x in a:
    if x >= "a" and x <= "z":
        minuscole += 1

print(minuscole)
```

    21
    


```python
a = "ProGrammAzione Dei calc0lat0r1"

vocali = 0

for x in a:
    if x == "a" or x == "e" or x == "i" or x == "o" or x == "u":
        vocali += 1

print(vocali)
```

    9
    


```python
a = "ProGrammAzione Dei calc0lat0r1"

vocali_minuscole = 0

for x in a:
    if x in "aeiou":
        vocali_minuscole += 1

print(vocali_minuscole)
```

    9
    


```python
print("python" in "Programma in Python")
print("Pth" in "Programma in Python")
print("in P" in "Programma in Python")
```

    False
    False
    True
    
