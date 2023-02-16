/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Second-Best Spanning Tree is a variant of MST problem, We can see that the second best ST is actually the
MST with just two edges difference. One edge is taken out from the MST and another chord edge is added into the MST. Next, for each edge in the MST (there are at
most V-1 edges in the MST), temporarily flag it so that it cannot be chosen, then try to
find the MST again in O(E) but now excluding that flagged edge. Note that we do not
have to re-sort the edges at this point. The best spanning tree found after this process is
the second best ST. 
 * Time: 
 * Status: 
 */