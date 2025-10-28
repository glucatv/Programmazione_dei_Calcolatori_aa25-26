#Es 1

n = input("Inserisci un numero intero: ")
somma = 0
for x in n:
    somma += int(x)
print(somma)

# Es 2

a = input("Scrivere la prima stringa: ")
b = input("Scrivere la seconda stringa: ")

spazi = (len(a)-len(b))//2

if spazi >= 0:
    print(a)
    print(" "*spazi+b)
    
if spazi < 0:
    print(-spazi*" "+a)
    print(b)