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

	li $t0, -1 #set counter to -1
	beqz $a0, return #if $a0 == 0 {go to return)
loop:
	
	beqz $a0, return #if ($a0 == 1){ go to return}
	
	srl $a0, $a0, 1 #shift $a0 by 1
	
	addi $t0, $t0, 1 #counter ++

	j loop
					
return:
	add $v0, $t0, $0
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
