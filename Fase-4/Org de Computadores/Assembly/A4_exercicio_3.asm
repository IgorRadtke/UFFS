	.data
informa: .string  "Insira o valor para encontrar a linha e coluna: "
vetor:	.word 2,8,-3,7,1,-2,4,5,3,5,1,-4
infa0:	.string	"a0= "
infa1:	.string "   a1= "

	.text
main:
	li a7,4
	la a0, informa
	ecall
	li a7,5
	ecall
	mv s4, a0
			
	li s0, 0
	la a3, vetor
	addi a1, zero, 3 #numero de linha
	addi a2, zero, 4 #numero de colunas
	
	addi s1, zero,-1
	add s2, zero,zero
	add s3, zero,zero
	addi s5, zero,-1
	addi s6, zero,-1
for1:	
	beq s1,a1, encerra
	addi s1,s1,1
	mv s2,zero
for2:
	beq s2, a2,for1
	lw s3, 0(a3)
	beq s3, s4,guarda_L_C
	jal prox

guarda_L_C:	
	mv s5, s1 # Linha
	mv s6, s2 # Coluna
	
prox:
	addi a3, a3, 4
	addi s2, s2, 1
	j for2
	
encerra:
#printa a0
	li a7,4
	la a0, infa0
	ecall
	mv a0, s5 # Linha
	li a7, 1
	ecall
#printa a1
	li a7,4
	la a0, infa1
	ecall
	mv a1, s6 # coluna
	mv a0, a1
	li a7, 1
	ecall

fim:
	nop
