	.data
num:	.word 9, 8, 5, -5, 3
	.text
main:
	la a0, num
	li a1, 5
	addi s0, zero,0
    	add s1, zero,zero
    	addi t0, zero,0
	add a2, zero, a0
loop:
	beq t0, a1, teste
	lw t1, 0(a2)
	blt t1, zero, oloco
	add s0, s0,t1

	jal teste2
oloco:
	add s1, s1,t1
teste2:
	addi t0 t0,1
	slli t2 t0,2
	add a2 a0,t2

	jal loop
teste:
	add a0 zero,s0
	add a1 zero,s1
	jalr zero



A funcao do codigo assembly e ler e somar todos os valores incrementados no vetor.

