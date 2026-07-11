<h2 align="center">Week 4 Day 24 (08/07/2026)</h2>

## 1. Happy Number (LeetCode #202)
A problem that teaches number manipulation and cycle detection techniques by repeatedly transforming a number based on the sum of squares of its digits. You're given a positive integer n. Repeatedly replace it with the sum of the squares of its digits. Keep doing this until one of two things happens: the number reaches 1, in which case it's a "happy number" and you return true, or the process enters an infinite loop that never reaches 1, in which case you return false.

This problem is commonly asked in interviews and helps build concepts like:
- Two pointers
- Cycle detection
- Mathematical simulation
- Digit extraction

which are important for number-based problem solving.

**Your task:** Determine whether the given number is happy using an optimized approach.

### Examples

**Input:**
```
n = 19
```
**Output:**
```
true
```

---

**Input:**
```
n = 2
```
**Output:**
```
false
```

---

## 2. Squares of a Sorted Array
A problem that teaches two pointer techniques by building a sorted array of squares directly from a sorted input array. You're given an integer array nums sorted in non decreasing order. Return an array containing the square of each number in nums, with the results also sorted in non decreasing order. Because negative numbers can square into large positive values, the largest squares will come from either end of the array, so simply squaring elements in place won't leave the result sorted a smarter, linear-time approach is needed.

This problem is commonly asked in interviews and helps build concepts like:
- Two pointers
- Array traversal

which are important for efficient array-processing problems.

**Your task:** Given the sorted array, compute the square of each element and output the results in non-decreasing order.

### Examples

**Input:**
```
nums = [-4,-1,0,3,10]
```
**Output:**
```
[0,1,9,16,100]
```

---

**Input:**
```
nums = [-7,-3,2,3,11]
```
**Output:**
```
[4,9,9,49,121]
```

---
