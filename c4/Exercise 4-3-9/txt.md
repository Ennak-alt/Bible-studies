Add commands to print the top element of the stack without popping, to duplicate it, and to swap the 
top two elements. Add a command to clear the stack.

#4-7
Write a routine `ungets(s)` that will push back an entire string onto the input. Should `ungets` know 
about `buf` and `bufp`, or should it just use `ungetch`?
**While just using ungetch might be easier, it will decrease the speed, and output more error messages 
than necessary. Without ungets knowing how much of the buf is filled, it will try to ungets a string
that is too large for the both, witch will result in a lot of error-messages that are uneeded, but it
will also result in more iterations thatn necessary.**

Yea, 4-8-9 have been done a bit half-assed, not tested at all.

