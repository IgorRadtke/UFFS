01-1 
not1 = float(input('Insira a Nota da primeira prova: '))
not2 = float(input('Insira a Nota da segunda prova: '))
not3 = float(input('Insira a Nota da terceira prova: '))
cont1 = (not1*3 + not2*3 + not3*4)/10
print ("A média final calculada é: ", cont1)


01-2
obj = int(input('Quantos quilômetros o objeto percorreu ? '))
temp = int(input('Quantas horas leva para percorrer a distância ? '))
calc1 = obj/temp
calc2 = calc1/1224
print ('A velocidade em mach foi de ', (calc1))


01-3
fer = int(input('Quantidade de ferro de solda comprado: '))
est = int(input('Quantidade de estanho comprado: '))
sol = int(input('Quantidade de sugador de solda comprado: '))
calc1 = (fer*34.67)
calc2 = (est*14.56)
calc3 = (sol*18.90)
if fer >= 10 <= 20:
    calc4 = calc1*0.9
    print('Com o desconto acima de 10 unidades, pagará: ', (calc4+calc2+calc3))
elif fer > 20:
    calc5 = calc1*0.82
    print('Com o desconto comprando acima de 20 unidade, pagará: ', (calc5+calc2+calc3))
else:
    print ('Sem desconto você pagará: ', (calc1+calc2+calc3))
 
 
01-4 
a = int(input('Digite um número inteiro: '))
b = int(input('Digite um segundo número inteiro: '))
aux=b
b=a
a = aux
print(a)
print(b)

01-5
alf = float(input('Valor taxa de alfabetizaçõa: '))
univ = int(input('Número de universidades: '))
parq = int(input('Número de parques: '))
cap = float(input('Renda per capita: '))
if alf < 80 or cap <1000:
    print('Não aconselhavel')
elif alf >= 85 and cap > 1000 and univ > 0:
    print('Aconselhável com precaução')
elif alf > 90 and cap <= 1200 and univ >= 2:
    print('Aconselhavel')
else:
    print('fortemente aconselhavel')


02-1
num = int(input('Digite um número inteiro: '))
par = [ ]
for c in range (num):
    if c %2==0:
        par.append(c)
print (par)


