# Approssimazione di  $\pi$

## Campionamenti casuali


```python
# questo è un commento
import random # importazione della libreria random  

n = 400 # definizione di variabile
n_c = 0 # operazioni di assegnamento

# equivalente a...
# n, n_c = 400, 0

print('Valori iniziali di n e n_c:', n, n_c) # funzione interna di Python

for _ in range(n): # range, funzione interna di Python
    x = random.uniform(-1, 1) # uniform, funzione della libreria random
    y = random.uniform(-1, 1)

    if x**2 + y**2 <= 1:
        n_c = n_c+1 # valuto espressione a dx di = e assegno il valore alla variabile a sx
        # oppure... n_c += 1

print('valore di pi calcolato = ', 4 * n_c / n )
```

    Valori iniziali di n e n_c: 400 0
    valore di pi calcolato =  3.15
    
