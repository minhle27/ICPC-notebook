/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Bit manipulation
 * Time:
 * Status: 
 */


/*
1) To multiply/divide an integer by 2, we only need to shift all8 bits in the integer
left/right, respectively. Notice that the truncation in the shift right operation
automatically rounds the division-by-2 down, e.g., 17/2 = 8.

S = 34 (base 10) = 100010 (base 2)
S = S<<1 = S*2 = 68 (base 10) = 1000100 (base 2)
S = S>>2 = S/4 = 17 (base 10) = 10001 (base 2)
S = S>>1 = S/2 = 8 (base 10) = 1000 (base 2) <- LSB is gone
(LSB = Least Significant Bit)

*/

/*
2) To set/turn on the j-th item (0-based indexing) of the set,
use the bitwise OR operation S |= (1<<j).

S = 34 (base 10) = 100010 (base 2)
j = 3, 1<<j = 001000 <- bit 1 is shifted to the left 3 times
-------- OR (true if either of the bits is true)
S = 42 (base 10) = 101010 (base 2) // update S to this new value 42
*/

/*
4) To check if the j-th item of the set is on,
use the bitwise AND operation T = S & (1<<j).
If T=0, then the j-th item of the set is off.
If T != 0 (to be precise, T = (1<<j)), then the j-th item of the set is on.

S = 42 (base 10) = 101010 (base 2)
j = 3, 1<<j = 001000 <- bit 1 is shifted to the left 3 times
-------- AND (only true if both bits are true)
T = 8 (base 10) = 001000 (base 2) -> not zero, the 3rd item is on
*/

