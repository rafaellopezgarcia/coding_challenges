# Container with most water

## Leetcode link
https://leetcode.com/problems/container-with-most-water

## Level 
- [ ] Easy
- [x] Medium
- [ ] Hard

## Solutions

### Times Solved

### Solution 1

#### Language
C++

#### Status
- [ ] Not solved
- [x] Solved with help
- [ ] Solved

#### Time to solution
20 minutes

### Mistakes
I could not remember how the problem is solved nor the intuition behind the solution.

**Intuition**: The area is given by the height of the shortest bar.
- We take two pointers when at the far left and the other at the far right of the array.
- We move the pointer of the bar with the shortest height, as the highest has always
the potential to provide a better solution, but the shortest has teh guarantee that will
not be better than the solution of the pointer which bar is higher.