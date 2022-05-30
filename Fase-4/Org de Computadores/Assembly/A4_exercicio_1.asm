	.data
numA:    .asciz "Insira o primeiro numero A: "
numB:    .asciz "Insira o segundo numero B: "
numC:    .asciz "Insira o terceiro numero C: "

	.text
main:
    li a7,4
    la a0,numA
    ecall
    li a7,5
    ecall
    mv s1,a0
    
    
    li a7,4
    la a0,numB
    ecall
    li a7,5
    ecall
    mv s2,a0
    
    
    li a7,4
    la a0,numC
    ecall
    li a7,5
    ecall
    mv s3,a0
    
verifica:
	mv t1, s1
	mv t2, s2
	mv t3, s3	
	add a0,t2,t3
	bgt a0,t1, true
	li a0, 0
	li a7, 1
	ecall
	j fim
	

true:
    li a0, 1
    li a7, 1
    ecall 
    j fim
    
fim:
    nop
    
    
