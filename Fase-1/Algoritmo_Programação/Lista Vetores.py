
#questão1:
A=[]
B=[]
for fun in range(10):
  a=input()
  A.append(a)
for don in range(10):
  b=input()
  B.append(b)
X=input()
for fon in range (len(A)):
  if A[fon]==X:
    d=fon
    print("posição:", d)
    print("elemento:", B[d])
    break
    
#questão2:
A=[]
B=[]
mag=(A, B)
for f in range(5):
  con=int(input())
  A.append(con)
for ixi in range(5):
  r2=int(input())
  B.append(r2)
values = list(zip(*mag))
sum_1 = sum(i for i in values[0]) 
sum_2 = sum(i for i in values[1])
sum_3 = sum(i for i in values[2])
sum_4 = sum(i for i in values[3])
sum_5 = sum(i for i in values[4])
print('SOMA: ', sum_1, sum_2, sum_3, sum_4, sum_5)

#questão3:
A=[]
for i in range(10):
  b=int(input())
  A.append(b)
maior=A[0]
menor=A[0]
for c in range(10):
  if A[c]>maior:
    maior=A[c]
for d in range(10):
  if A[d]<menor:
    menor=A[d]  
print(maior, menor)

#questão4:
F=[]
for i in range(5):
  g=input()
  F.append(g)
t=int(input("digite a posição a ser removida: "))
del(F[t])
print("novo vetor: ",F)
print("novo tamanho do vetor: ",(len(F)))

#questão5:
values = list(map(int, input().split()))
qtd_duplicated = 0
duplicados = []
values_length = len(values) 
for i in range(values_length):
    for j in range(i):
        if values[i] == values[j] and values[i] not in duplicados:
            duplicados.append(values[i])
print(f'Número de elementos duplicados: {len(duplicados)}')
print("Números duplicados: ", duplicados)

#questão6:
values = list(map(int, input().split()))
par= []
impar= []
for i in range(len(values)):
    if values[i] % 2 == 0:
        par.append(values[i])
    else:
        impar.append(values[i])
print(f'Pares: {par}')
print(f'Ímpares: {impar}')