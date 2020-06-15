//C++

int flipBit(int n) 
{ 
	if (~n == 0) /* If all bits are 1, binary representation of n has all 1s */
		return 8*sizeof(int); 

	int currLen = 0, prevLen = 0, maxLen = 0; 
	while (n!= 0) 
	{ 
		// If Current bit is a 1 then increment currLen++ 
		if ((n & 1) == 1) 
			currLen++; 

		// If Current bit is a 0 then check next bit of n
		else if ((n & 1) == 0) 
		{ 
			/* Update prevLen to 0 (if next bit is 0) or currLen (if next bit is 1). */
			prevLen = (n & 2) == 0? 0 : currLen; 

			// If two consecutively bits are 0 then currLen also will be 0. 
			currLen = 0; 
		} 

		// Update maxLen if required 
		maxLen = max(prevLen + currLen, maxLen); 

		// Remove last bit (Right shift) 
		n >>= 1; 
	} 
	return maxLen+1; 
}