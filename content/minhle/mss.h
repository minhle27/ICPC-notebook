/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Minimum Spanning Subgraph of MST problem. Some edges in the given graph have already
been fixed and must be taken as part of the solution. For Kruskal’s algorithm, we first take into account
all the fixed edges and their costs. Then, we continue running Kruskal’s algorithm on the
remaining free edges until we have a spanning subgraph (or spanning tree). For Prim’s
algorithm, we give higher priorities to these fixed edges so that we will always take them
and their costs.
 * Time: 
 * Status: 
 */