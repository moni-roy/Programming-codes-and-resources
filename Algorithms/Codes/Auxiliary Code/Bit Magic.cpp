Set bit 						A |= 1 << bit
Clear bit 						A &= ~(1 << bit)
Test bit						(A & 1 << bit) != 0
Toggle bit 						A^(1<<bit)
Set subtraction 				A&~B
Set negation ALL_BITS 			^A
Value with only last set bit 	x & ~(x - 1)
Check if n is power of 2 		!( n&(n-1)) except n=0
Count trailing zeros 			__builtin_ctz(n)
Count leading zeros 			__builtin_clz(n)
total set bits 					__builtin_popcount(n)
Position of rightmost set bit 	log2(n&-n)
Turn off rightmost set bit 		n&(n-1)
