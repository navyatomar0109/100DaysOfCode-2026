# Swap Kth Node from Beginning and End

## Problem Statement

You are given the head of a singly linked list containing **N** nodes and an integer **K**.

Your task is to swap the **Kth** node from the beginning of the list with the **Kth** node from the end of the list, and return the head of the modified linked list.

> **Note:** You may swap the nodes themselves or simply swap their values, as long as the resulting linked list is correct.  
> **K** is **1-indexed**, i.e., `K = 1` refers to the first node from the beginning or the end.

---

## Input Format

- The first line contains an integer **N**, the number of nodes in the linked list.
- The next **N** lines each contain an integer, representing the value of a node in the linked list from head to tail.
- The last line contains an integer **K**.

---

## Constraints

- `1 ≤ N ≤ 10^5`
- `1 ≤ K ≤ N`
- `-10^9 ≤ node.value ≤ 10^9`

---

## Example 1

### Input
```text
6
5
10
8
5
9
3
2
```

### Output
```text
5
9
8
5
10
3
```

### Explanation

The **2nd** node from the beginning is **10**, and the **2nd** node from the end is **9**. Swapping them results in the modified linked list shown above.

---

## Example 2

### Input
```text
5
1
2
3
4
5
1
```

### Output
```text
5
2
3
4
1
```

### Explanation

The **1st** node from the beginning is **1**, and the **1st** node from the end is **5**. Swapping them gives the resulting linked list.