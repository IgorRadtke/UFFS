    .data
    
    .text
main:
    addi s0, zero,0
    add s1, zero,zero
    addi t0, zero,0
    add a2, zero, a0
    beq t0, a1, teste
    
    lw t1, 0(a2)
    blt t1, zero, oloco
    add s0, s0,t1
    jal teste2 
oloco:
    teste2:
    add s1, s1,t1
    addi t0 t0,1
    slli t2 t0,2
    
    add a2 a0,t2
    add a0 zero,s0
teste:
    add a1 zero,s1
    jalr ra