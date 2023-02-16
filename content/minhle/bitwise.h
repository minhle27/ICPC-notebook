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
3) To check if the j-th item of the set is on,
use the bitwise AND operation T = S & (1<<j).
If T=0, then the j-th item of the set is off.
If T != 0 (to be precise, T = (1<<j)), then the j-th item of the set is on.

S = 42 (base 10) = 101010 (base 2)
j = 3, 1<<j = 001000 <- bit 1 is shifted to the left 3 times
-------- AND (only true if both bits are true)
T = 8 (base 10) = 001000 (base 2) -> not zero, the 3rd item is on
*/

/*
4) To clear/turn off the j-th item of the set,
use the bitwise AND operation S &= ~(1<<j).

S = 42 (base 10) = 101010 (base 2)
j = 1, ~(1<<j) = 111101 <- ~ is the bitwise NOT operation
-------- AND
S = 40 (base 10) = 101000 (base 2) // update S to this new value 40
*/

/*
5) To toggle (flip the status of) the j-th item of the set,
use the bitwise XOR operation S ^= (1<<j).

S = 40 (base 10) = 101000 (base 2)
j = 2, (1<<j) = 000100 <- bit 1 is shifted to the left 2 times
-------- XOR <- true if both bits are different
S = 44 (base 10) = 101100 (base 2) // update S to this new value 44
*/

/*
6) To get the value of the least significant bit of S that is on (first from the right),
use T = ((S) & -(S)). This operation is abbreviated as LSOne(S).

Notice that T = LSOne(S) is a power of 2, i.e., 2^j .
To get the actual index j (from the right), we can use __builtin_ctz(T) below.
*/

/*
7) To turn on all bits in a set of size n, use S = (1<<n) - 1
*/

/*
8) To enumerate all proper subsets of a given a bitmask, e.g., if mask = (18)10 = (10010)2,
then its proper subsets are {(18)10 = (10010)2, (16)10 = (10000)2, (2)10 = (00010)2},
we can use:
int mask = 18;
for (int subset = mask; subset; subset = (mask & (subset-1)))
    cout << subset << "\n";
*/

/*
__builtin_popcount(S) to count how many bits that are on in S and
__builtin_ctz(S) to count how many trailing zeroes in S.
*/