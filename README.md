# scalar
scalar test

Algorithm for solving the crossing bridge problem:

Input: an array of integers that denote the time required by each individual to cross the bridge
Output: the minimum total time used to cross the bridge for all people

1. Sort the array in ascending order: the fastest in the front and the slowest at the end
2. If there are more than 3 persons left, run iteration to move the last two accross the bridge at each iteration
3. If there are 3 left: add them up 
4. If there are 2 or 1 left: take the last one (slowest)
5. Done
