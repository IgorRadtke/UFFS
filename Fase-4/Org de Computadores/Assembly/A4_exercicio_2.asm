	.data
vetor:		.word	-6, 34, 3, 9, 20, 65, -2, -9, 36, 0
StrVetor: 	.string "Vetores Ordenados: "
str_space: 	.string "  "

	.text
main:
	la	s11, vetor
	li	s10,10
	li 	a7, 4	
	mv	a1,s10
	mv	a0, s11
	jal 	f_ordena_1
	
	li 	a7, 4	
	la 	a0, StrVetor
	ecall
	
	mv	a1,s10
	mv	a0, s11
	jal 	f_imprime

f_swap: # a0) primeiro indice a trocar, a1) segundo indice, a2) endereço do vetor
	li 	t4, 4	
	mul 	t0, a0, t4  
	add 	t0, t0, a2  
	mul 	t1, a1, t4  
	add 	t1, t1, a2  
	
	lw 	t2, 0(t0)	
	lw 	t3, 0(t1)	
	
	sw 	t3, 0(t0)	
	sw 	t2, 0(t1)	
	ret
	
f_ordena_1: # Bubble Sort
	mv	a7, a0 # vetor
	mv	a6, a1 # Tamanho do vetor
	
for1:
	beq	t6, a6, endfor1
		addi	t6, t6, 1
		mv	t5, zero

for2:
	beq 	t5, a6, for1 
		li 	t4, 4
		mul 	s0, t5, t4	
		add 	s0, s0, a7 
		lw	s1, 0(s0)
		lw	s2, 4(s0)
	
		blt	s1,s2, SemSwap
		mv	a0, t5
		mv	a1, t5
		addi	a1, a1, 1
		mv	a2, a7
		mv	s3, ra
		jal	f_swap
		mv	ra,s3

SemSwap:	
	addi 	t5, t5, 1	
	j 	for2
	
endfor1:
	ret	
	
f_imprime: 
	mv	a2,a0		
	mv	t5, zero	
	
for:
	beq 	t5, a1, end
		li 	t4, 4	
		mul 	t4, t5, t4	
		add 	t4, t4, a2	
		lw 	a0, 0(t4)	
		li 	a7, 1	
		ecall		
	
		li 	a7, 4	
		la 	a0, str_space 
		ecall		
	
		addi 	t5, t5, 1	
		j 	for
end: 	
	nop
