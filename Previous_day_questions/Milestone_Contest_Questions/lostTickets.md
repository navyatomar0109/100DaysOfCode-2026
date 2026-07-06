# Find Missing Ticket Numbers

## Problem Statement

A ticket counter issued **n** tickets, each printed with a number between **1** and **n**. Some numbers may appear multiple times, while others may not appear at all.

You are given the sequence of ticket numbers in the order they were issued. Your task is to find every number in the range **[1, n]** that does **not** appear in the sequence, and print them in increasing order.

> **Note:** If every number from **1** to **n** appears at least once, print nothing (an empty line).

---

## Input Format

- The first line contains a single integer **n**, the number of issued tickets.
- The second line contains **n** space-separated integers:
  `nums[1], nums[2], ..., nums[n]`,
  where each value satisfies `1 ≤ nums[i] ≤ n`.

---

## Constraints

- `1 ≤ n ≤ 10^5`
- `1 ≤ nums[i] ≤ n`

---

## Example 1

### Input
```text
8
4 3 2 7 8 2 3 1
```

### Output
```text
5 6
```

### Explanation

The numbers **5** and **6** do not appear in the given sequence, so they are printed in increasing order.

---

## Example 2

### Input
```text
2
1 1
```

### Output
```text
2
```

### Explanation

The number **2** is missing from the sequence, so it is printed.