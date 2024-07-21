# Rotate matrix

## Leetcode link
https://leetcode.com/problems/rotate-image

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
- [ ] Solved with help
- [x] Solved

#### Time to solution
35 minutes

### Conclusions
It took me time to figure out the intuition behind the solution
- Rotating the matrix has a pattern in which rotating one element
produces the rotation of other three elements. This is the core of
the solution

- The previous pattern has to be called inside two for loops, one to
move along the rows and the other one to move along the columns.

- Moving along the rows is done $\frac{n}{2}$

- Moving along the columns starts from `j=i` and stops at `n-i-1`

