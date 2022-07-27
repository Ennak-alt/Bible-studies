In a two's complement number representation, our version of `itoa` does not handle the largest negative 
number, that is, the value of n equal to -(2^(-wordsize-1)).

In a two's complement number representation, whenever the leftmost bit is 1, you have a negative number,
more specifically, when the leftmost bit is 1, the number will be between -1 and -2^31 (if it a 32 bit number). 
When representing a negative number, the bits will be "inverted", lets say you have -1 in an 8-bit number, this will be
1b1111111, this is because when a bit is 1, it basically means to not subtract that bit, that means that -2 will be
1b1111110. On the other hand, if the leftmost bit is 0, we either have 0 or a positive number. This means
that positive numbers can be represented with one less number since 0 needs to also be represented.
This means that the highest positive number in a 32 bit complement number representation is 2^31-1,
so if you try to convert -2^31 to a positive number (as is the case in `itoa`), it will result 
in an overflow.
