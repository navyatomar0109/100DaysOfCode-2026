# Longest Balanced Substring

## Problem Statement

While digitizing an old manuscript, **Meera** notices that some passages read more smoothly than others. She defines a substring as **balanced** if the number of vowels in it is at most twice the number of consonants. In other words, a substring with **v** vowels and **c** consonants is balanced if and only if:

\[
v <= 2c
\]

Given a string **s**, determine:

1. The length of the **longest balanced substring**.
2. The number of balanced substrings having **that maximum length**.

The letters **a, e, i, o, u** (both uppercase and lowercase) are considered vowels. Every other Latin letter is treated as a consonant.

> **Note:** Two substrings are considered distinct if they have different starting or ending positions, even if their contents are identical.

If no balanced substring exists, print **`No solution`**.

---

## Input Format

- A single line containing a non-empty string **s** consisting of uppercase and lowercase Latin letters.

---

## Constraints

- `1 ≤ |s| ≤ 2 × 10^5`
- `s` contains only Latin letters (`a-z`, `A-Z`)

---

## Example 1

### Input
```text
Abo
```

### Output
```text
3
1
```

### Explanation

The entire string **"Abo"** contains **2 consonants** and **1 vowel**, satisfying `1 ≤ 2 × 2`. Hence, it is balanced, and no longer substring exists.

---

## Example 2

### Input
```text
OEIS
```

### Output
```text
3
1
```

### Explanation

The longest balanced substring is **"EIS"**, which contains **2 vowels** and **1 consonant**, satisfying `2 ≤ 2 × 1`.

---

## Example 3

### Input
```text
EA
```

### Output
```text
No solution
```

### Explanation

The string contains only vowels, so every substring has **0 consonants**. Therefore, the condition `v ≤ 2c` is never satisfied, and no balanced substring exists.