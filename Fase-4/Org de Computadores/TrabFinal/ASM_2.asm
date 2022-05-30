    .data
    .text
main:
        addi    sp, sp, -1760

        nop    
        nop    
        
        sw      ra, 1756(sp)  
        sw      s0, 1752(sp)
        
        nop    
        nop    
        
        addi    s0, sp, 1760
        li      a0, 0
        
        nop    
        nop       
             
        sw      a0, -16(s0)
        li      a1, 11

        nop    
        nop    
        
        sw      a1, -1748(s0)
        li      a1, 12
        
        nop    
        nop    
        
        sw      a1, -1752(s0)
        sw      a0, -1756(s0)
LBB0_1:
        lw      a0, -1756(s0)
        lw      a1, -1748(s0)

        nop    
        nop    

        bge     a0, a1, LBB0_8
        li      a0, 0

        nop    
        nop    
        
        sw      a0, -1760(s0)
LBB0_2:
        lw      a0, -1760(s0)
        lw      a1, -1752(s0)

        nop    
        nop    
   
        bge     a0, a1, LBB0_6
        lw      a1, -1756(s0)
        lw      a2, -1760(s0)

        nop    
        nop    

        add     a0, a1, a2
        li      a3, 48
        
        nop            
        nop    
        
        mul     a4, a1, a3 
        addi    a1, s0, -592

        nop    
        nop    
        
        add     a1, a1, a4
        slli    a2, a2, 2
        
        nop    
        nop    
        
        add     a1, a1, a2
        
        nop    
        nop    
        nop    
        nop            
        
        sw      a0, 0(a1)
        lw      a2, -1756(s0)
        lw      a1, -1760(s0)

        nop    
        nop    
        
        sub     a0, a2, a1
        mul     a3, a1, a3
        addi    a1, s0, -1168
 
        nop    
        nop                
        
        add     a1, a1, a3
        slli    a2, a2, 2
        
        nop    
        nop    
        
        add     a1, a1, a2
        
        nop    
        nop     
               
        sw      a0, 0(a1)     
        lw      a0, -1760(s0)
        
        nop    
        nop    
        
        addi    a0, a0, 1
        
        nop    
        nop            
        
        sw      a0, -1760(s0)
        j       LBB0_2
LBB0_6:
        lw      a0, -1756(s0)

        nop    
        nop     
        
        addi    a0, a0, 1
        
        nop    
        nop     
                
        sw      a0, -1756(s0)
        j       LBB0_1
LBB0_8:
        lw      a3, -1748(s0)
        lw      a4, -1752(s0)
        addi    a0, s0, -592
        addi    a1, s0, -1168
        addi    a2, s0, -1744
        call    matrix_mult
        li      a0, 0
        lw      ra, 1756(sp)               
        lw      s0, 1752(sp)                  
        addi    sp, sp, 1760
        j    fim
matrix_mult:
        nop
        nop

        addi    sp, sp, -48
               
        nop 
        nop        
        
        sw      ra, 44(sp)                      
        sw      s0, 40(sp)                       
        addi    s0, sp, 48
        
        nop 
        nop           
        
        sw      a0, -12(s0)
        sw      a1, -16(s0)
        sw      a2, -20(s0)
        sw      a3, -24(s0)
        sw      a4, -28(s0)
        li      a0, 0
        
        nop 
        nop  
        
        sw      a0, -32(s0)
LBB1_1:     
        lw      a0, -32(s0)
        lw      a1, -24(s0)
        bge     a0, a1, LBB1_7
        
LBB1_2:    
        li      a0, 0
        
        nop 
        nop            
        
        sw      a0, -36(s0)
LBB1_3: 
        lw      a0, -36(s0)
        lw      a1, -28(s0)
        
        nop 
        nop         
        
        bge     a0, a1, LBB1_6
        li      a0, 0
        
        nop 
        nop 
        
        sw      a0, -40(s0)
LBB1_4:
        lw      a0, -40(s0)
        lw      a1, -28(s0)
        
        nop 
        nop        
        
        bge     a0, a1, LBB1_5
        lw      a0, -12(s0)
        lw      a1, -32(s0)
        li      a4, 48
         
        nop 
        nop 

        mul     a3, a1, a4
        
        nop 
        nop         
        
        add     a0, a0, a3
        lw      a2, -40(s0)
        
        nop 
        nop         
        
        slli    a1, a2, 2
        
        nop 
        nop  
                
        add     a0, a0, a1
                 
        nop 
        nop  
                
        lw      a0, 0(a0)
        lw      a1, -16(s0)
        mul     a2, a2, a4
  
        nop 
        nop      
        
        add     a2, a2, a1
        lw      a1, -36(s0)
        
        nop 
        nop          
        
        slli    a1, a1, 2

        nop 
        nop        
        
        add     a2, a2, a1  
        
        nop                
        nop     
     
        lw      a2, 0(a2)
        
        nop 
        nop          
        
        mul     a2, a0, a2
        lw      a0, -20(s0)
        
        nop 
        nop         
        
        add     a0, a0, a3
        
        nop 
        nop         
        
        add     a1, a1, a0
             
        nop 
        nop         
        
        lw      a0, 0(a1)

        nop 
        nop         
        
        add     a0, a0, a2
 
        nop 
        nop        
        
        sw      a0, 0(a1)
        lw      a0, -40(s0)
        
        nop 
        nop         
        
        addi    a0, a0, 1 
      
        nop 
        nop    
                       
        sw      a0, -40(s0)
        j       LBB1_4
LBB1_5:   
        lw      a0, -36(s0)
    
        nop 
        nop           
        
        addi    a0, a0, 1
        
        nop 
        nop            
        
        sw      a0, -36(s0)
        j       LBB1_3
LBB1_6:  
        lw      a0, -32(s0)
       
        nop 
        nop          
        
        addi    a0, a0, 1
       
        nop 
        nop 
        
        sw      a0, -32(s0)
        j       LBB1_1
LBB1_7:
        lw      ra, 44(sp)                     
        lw      s0, 40(sp)            
        addi    sp, sp, 48
        ret
fim:
    nop