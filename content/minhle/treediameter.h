/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: The diameter of a tree is the maximum length of a path between two nodes.
 * Time: O(N) for both algorithm
 * Status: 
 */

// First Algorithm
A general way to approach tree problems is to first root the tree
arbitrarily and then solve the problem separately for each subtree
An important observation is that every path in a rooted tree has a highest point:
the highest node that belongs to the path. Thus, we can calculate for each node x the
length of the longest path whose highest point is x. One of those paths corresponds
to the diameter of the tree. 
toLeaf(x): the maximum length of a path from x to any leaf
maxLength(x): the maximum length of a path whose highest point is x
First, to calculate toLeaf(x), we go through the children of x,
choose a child c with the maximum toLeaf(c), and add one to this value. Then,
to calculate maxLength(x), we choose two distinct children a and b such that the
sum toLeaf(a) + toLeaf(b) is maximum and add two to this sum. (The cases
where x has less than two children are easy special cases.)

// Second Algorithm
Another efficient way to calculate the diameter of a tree is based
on two depth-first searches. First, we choose an arbitrary node a in the tree and find
the farthest node b from a. Then, we find the farthest node c from b. The diameter
of the tree is the distance between b and c.