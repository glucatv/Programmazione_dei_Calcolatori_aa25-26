# 1. Sia `n` una variabile intera, scrivere un programma che crei una lista contenente i primi `n` interi.

n = 10

a = list(range(n))

print(a)

# 2. Sia `a` una lista contenente soltanto numeri, si costruisca la lista delle somme parziali di `a`, ovvero una lista, denominata `somme` della stessa dimensione di `a` tale che `somme[i]` contiene la somma dei primi `i+1` elementi in `a`.

somme = []

for x in a:
    if somme == []:
        somme.append(x)
    else:
        c = somme[-1] + x
        somme.append(c)
        
print(somme)