.data 
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!"
# Declare any necessary data here


str1: .asciiz "Enter the price of each BobCat Bar: \0"
str2: .asciiz "Enter the number of bar wrappers needed to exchange for a new bar: \0"
str3: .asciiz "Enter how much money you have: \0"

funcstr1: .asciiz "Good! Let me run the numbers ...\n"
funcstr2: .asciiz "You first buy "
funcstr3: .asciiz " bars.\n"

loopstr1: .asciiz "Then, you will get another "

endstr1: .asciiz "With $"
endstr2: .asciiz ", you will receive a maximum of "
endstr3: .asciiz " BobCat Bars!\n"
 


.text

main:
		#This is the main program.
		
		#It first asks user to enter the price of each BobCat Bar.
		#It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
		#It then asks user to enter how much money he/she has.
		#It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered. 
		#It then prints out a statement about the maximum BobCat Bars the user will receive.
		
		addi $sp, $sp, -16	# Feel free to change the increment if you need for space.
		sw $ra, 0($sp)
		# Implement your main here
		
		li  $v0, 4
		la  $a0, str1
		syscall #asks user to enter the price of each BobCat Bar
		
		li  $v0, 5
		syscall 
		sw $v0, 12($sp) #stores price of each BobCat Bar on stack
		

		li  $v0, 4
		la  $a0, str2
		syscall #asks user to enter the number of bar wrappers needed to exchange for a new bar
		
		li  $v0, 5
		syscall 
		sw $v0, 8($sp) #stores the number of bar wrappers needed to exchange for a new bar
		

		li  $v0, 4
		la  $a0, str3
		syscall #asks user to enter how much money he/she has
		
		li  $v0, 5
		syscall 
		sw $v0, 4($sp) #stores the amount of money the costomer has
#end of information input		

		jal maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars

# Print out final statement here
		li  $v0, 4
		la  $a0, endstr1
		syscall
		
		li  $v0, 1
		lw  $a0, 4($sp)
		syscall #outputs the amount of money
		
		li  $v0, 4 
		la  $a0, endstr2
		syscall
		
		li  $v0, 1
		lw  $a0, 0($sp)
		syscall #outputs the total amount of candy bars
		
		li  $v0, 4
		la  $a0, endstr3
		syscall


		j end			# Jump to end of program

maxBars:
		# This function calculates the maximum number of BobCat Bars.
		# It takes in 3 arguments ($a0, $a1, $a0) as n, price, and money. It returns the maximum number of bars

    		lw $a0, 8($sp) #store n in $a0
		lw $a1, 12($sp) #store price in $a1
		lw $a2, 4($sp) #store money in $a2
		
    		#$s0 is the total number of bars so far
		
    		addi $sp, $sp -4 #store return on the stack
		sw $ra, 0($sp) 
    	
    		div $a2, $a1 #*CustMoney / *BarPrice;
 		mflo $s0 # total_bars = *CustMoney / *BarPrice;

		li  $v0, 4
		la  $a0, funcstr1
		syscall #prints "Good! Let me run the numbers ... \n"
		
		
		beq $s0, $0, done   #check for 0 bars --if (total_bars != 0)
		
		li  $v0, 4
		la  $a0, funcstr2
		syscall #prints how many bars money can initialy buy part 1
		
		li  $v0, 1
		la  $a0, ($s0)
		syscall #prints # of bars money can initialy buy
		
		li  $v0, 4
		la  $a0, funcstr3
		syscall #prints how many bars money can initialy buy part 2
		
		add $a0, $s0, $0 #store # of bars in $a0
		lw $a1, 12($sp) #store n in $a1
		
		jal newBars
		#add $s0, $s0, $v0

	done:		
	#Epilogue
		#add $v1, $s0, $0
		lw $ra, 0($sp)
		addi $sp, $sp, 4
		sw $s0, 0($sp)  # stores return value in total number of BobCat Bars
		jr $ra #should be $sp
		# End of maxBars

newBars:
		# This function calculates the number of BobCat Bars a user will receive based on n.
		# It takes in 2 arguments ($a0, $a1) as number of bars so far and n.
		
		addi $sp, $sp, -4 #store return on the stack
		sw $ra, 0($sp) 
		
		div $a0, $a1 #total_bars = total_bars / *WraperNum;
		mfhi $t1 # remainder
		mflo $t0 # number of bars
		
		
		beq $t0, 0, newdone
		
		li  $v0, 4
		la  $a0, loopstr1
		syscall #prints recursive phrase 1
		
		
		li  $v0, 1
		la  $a0, ($t0)
		syscall #prints # of bars money can buy
		
		li  $v0, 4
		la  $a0, funcstr3
		syscall #prints recursive phrase 2
		
		add $s0, $s0, $t0 # adds new bars to total
		add $a0, $t0, $0 #store # of bars in $a0
		add $a0, $a0, $t1 #store remaining wrapers $a0
		
		jal newBars
		
		
newdone:		
	#Epilogue
		lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra
		# End of newBars

end: 
		# Terminating the program
		lw $ra, 0($sp)
		addi $sp, $sp, 20
		li $v0, 10 
		syscall