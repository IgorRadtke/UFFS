	.data
str_a0:		.string "Insira o valor de a0: "
str_a1:		.string "Insira o valor de a1: "
resultado:	.string "Resultado: "
	.text
main:
	la a0, str_a1
	li a7, 4
	ecall
	li a7, 5
	ecall
	mv a1, a0
	
	la a0, str_a0
	li a7, 4
	ecall
	li a7, 5
	ecall
	
	mv s0, zero
	mv s1, zero

multiplica:
	beq s1, a0, soma
	add s0, s0, a1 #soma = soma + b
	addi s1, s1, 1
	j multiplica
	
soma:
	mv s2, zero # s2 == v0
	mv s2, s0 
fim:
	nop
	
	