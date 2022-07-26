In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. 
Use this observation to write a faster version of bitcount.

Explanation: 
When subtracting 1 from the number, the rightmost bit in the numbers bit representation will need
to be distributed among bits that are lesser than itself, that means to the right of it. Forexample:
0b010 - 1 = 0b001. This will always be the case. Now, since we know that the bit representation of the number
before only had 0's to the right of the rightmost 1 bit, the & operator will there remove the new 1's
that were distributed, and thereby remove the rightmost 1-bit from the original number. 