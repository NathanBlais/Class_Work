main:
	lui	$a0,0x8000
	jal	first1pos
	jal	printv0
	lui	$a0,0x0001
	jal	first1pos
	jal	printv0
	li	$a0,1
	jal	first1pos
	jal	printv0
	add	$a0,$0,$0
	jal	first1pos
	jal	printv0
	li	$v0,10
	syscall
first1pos:	# your code goes here
	li $v0, -1 #set counter to -1
	beq $a0, $0, return #if $a0 == 0 {go to return}
	li $v0, 31 #set counter to 31
	lui $t0 0x8000 #set mask
loop:
	and $t1, $a0, $t0 
	bne $t1, $0, return #if ($t1 == 0){go to return} if $t1 is != to 0 that means it hit the first 1
	addi $v0, $v0, -1 #counter --
	srl $t0, $t0, 1 #shift $t0 by 1
	j loop				
return:
	jr  $ra
printv0:
	addi	$sp,$sp,-4
	sw	$ra,0($sp)
	add	$a0,$v0,$0
	li	$v0,1
	syscall
	li	$v0,11
	li	$a0,'\n'
	syscall
	lw	$ra,0($sp)
	addi	$sp,$sp,4
	jr	$ra
