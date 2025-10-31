# Si scriva una funzione `argfind` che prende in input una lista di numeri `L` e un valore `k` e restituisce la posizione della prima occorrenza di `k` in `L`. Se `L` non contiene `k`, la funzione restituisca `-1`. 
L = [2,1.9,4,6,7,4.3,2,9,2]
k = 0

n = len(L)

for i in range(n):
    if k == L[i]:
        print(i)
        break
    
print(i)