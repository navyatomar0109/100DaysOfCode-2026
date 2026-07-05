# Vowel Balance

## Problem Summary

Given a string `s`, find the length of the **longest "balanced" substring**, where a substring is considered balanced if - treating each vowel (`a, e, i, o, u`, case-insensitive) as weight **+1** and each consonant as weight **−2** - the weighted sum of the substring is **≤ 0**. Also report **how many** substrings of that maximum length achieve balance. If no non-trivial balanced substring exists, output `No` / `solution` on two lines.

**Core idea (prefix sum + Fenwick/BIT "min index" trick):**
1. Build a prefix-weight array `P`, where `P[0] = 0` and `P[i+1] = P[i] + weight(s[i])`.
2. A substring `s[k..j-1]` is balanced exactly when `P[j] - P[k] <= 0`, i.e. `P[k] >= P[j]`.
3. So for each ending index `j`, we need the **smallest `k` with `P[k] >= P[j]`** to maximize the substring length `j - k`.
4. Since `P[k]` values are bounded (`-2n <= P[k] <= n`), they can be mapped directly to array indices (no sorting needed) and stored in a **Fenwick tree indexed by (a transform of) value**, where each position keeps the **minimum index `k`** seen so far with that value (or larger, via the transform `idx = hi_val - v + 1`, which reverses order so a Fenwick prefix-min naturally answers "smallest k with P[k] >= v").
5. Process `j` from `0` to `n`: first *query* the tree for the best (smallest) index satisfying `P[k] >= P[j]` (skip `j == 0` since there's no earlier prefix), then *update* the tree at `P[j]`'s position with index `j`.
6. Track the best (maximum) length found and how many times that maximum length is achieved.

**Time complexity:** O(n log n) — one Fenwick query and one update per position.
**Space complexity:** O(n) — for the prefix array and the Fenwick tree (range is `O(n)` since weights are bounded by `−2n` to `n`).

---

## Python

```python
#!/bin/python3

import math
import os
import random
import re
import sys
from bisect import bisect_left

#
# Complete the 'longestBalancedSubstring' function below.
#
# The function is expected to return an INTEGER_ARRAY of size 2:
#   result[0] = length of the longest balanced substring (0 if none exists)
#   result[1] = number of balanced substrings of that length
#
# The function accepts STRING s as parameter.
#

def longestBalancedSubstring(s):
    n = len(s)

    P = [0] * (n + 1)
    for i in range(n):
        c = s[i].lower()
        w = 1 if c in ('a', 'e', 'i', 'o', 'u') else -2
        P[i + 1] = P[i] + w

    lo_val = -2 * n
    hi_val = n
    rng = (hi_val - lo_val) + 1

    fen = [float('inf')] * (rng + 2)

    def update(k, val):
        while k <= rng:
            if fen[k] > val:
                fen[k] = val
            k += k & (-k)

    def query(k):
        res = float('inf')
        while k > 0:
            if fen[k] < res:
                res = fen[k]
            k -= k & (-k)
        return res

    best_len = 0
    best_count = 0

    for j in range(n + 1):
        v = P[j]
        idx_v = (hi_val - v + 1)

        if j > 0:
            res = query(idx_v)
            if res != float('inf'):
                length = j - res
                if length > best_len:
                    best_len = length
                    best_count = 1
                elif length == best_len:
                    best_count += 1

        update(idx_v, j)

    return [best_len, best_count]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = longestBalancedSubstring(s)

    if result[0] == 0:
        fptr.write("No\n")
        fptr.write("solution\n")
    else:
        fptr.write(str(result[0]) + "\n")
        fptr.write(str(result[1]) + "\n")

    fptr.close()
```

---

## C

```c
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);

/*
 * Complete the 'longestBalancedSubstring' function below.
 *
 * The function is expected to return an INTEGER (the length of the
 * longest balanced substring, or 0 if none exists).
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_POINTER count  (write the number of balanced substrings
 *     of the returned length into *count)
 */

int longestBalancedSubstring(char* s, int* count) {
    int n = (int)strlen(s);

    /* vowel = +1, consonant = -2; a substring is balanced iff its
       weighted sum <= 0 */
    long long *P = (long long*)malloc(sizeof(long long) * (n + 1));
    P[0] = 0;
    for (int i = 0; i < n; i++) {
        char c = (char)tolower((unsigned char)s[i]);
        int w = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') ? 1 : -2;
        P[i + 1] = P[i] + w;
    }

    /* P[i] is always within [-2n, n], so we can index Fenwick slots
       directly by value - no sort / comparator function needed */
    long long lo_val = -2LL * n;
    long long hi_val = (long long)n;
    int range = (int)(hi_val - lo_val) + 1;

    int *fen = (int*)malloc(sizeof(int) * (range + 2));
    for (int i = 0; i <= range + 1; i++) fen[i] = INT_MAX;

    int best_len = 0, best_count = 0;

    for (int j = 0; j <= n; j++) {
        long long v = P[j];
        int idx_v = (int)(hi_val - v + 1);

        if (j > 0) {
            int res = INT_MAX;
            int k = idx_v;
            while (k > 0) {
                if (fen[k] < res) res = fen[k];
                k -= k & (-k);
            }
            if (res != INT_MAX) {
                int length = j - res;
                if (length > best_len) { best_len = length; best_count = 1; }
                else if (length == best_len) best_count++;
            }
        }

        {
            int k = idx_v;
            while (k <= range) {
                if (fen[k] > j) fen[k] = j;
                k += k & (-k);
            }
        }
    }

    free(P);
    free(fen);
    *count = best_count;
    return best_len;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s_str = readline();
    char* s = ltrim(rtrim(s_str));

    int count = 0;
    int result = longestBalancedSubstring(s, &count);

    if (result == 0) {
        fprintf(fptr, "No\nsolution\n");
    } else {
        fprintf(fptr, "%d\n%d\n", result, count);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) break;
    }

    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length + 1);

    return data;
}

char* ltrim(char* str) {
    if (!str) return str;
    while (*str != '\0' && isspace((unsigned char)*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return str;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
```

---

## C++

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'longestBalancedSubstring' function below.
 *
 * The function is expected to return an INTEGER (the length of the
 * longest balanced substring, or 0 if none exists).
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_REFERENCE count  (set count to the number of balanced
 *     substrings of the returned length)
 */

int longestBalancedSubstring(string s, int &count) {
    int n = (int)s.size();

    vector<long long> P(n + 1);
    P[0] = 0;
    for (int i = 0; i < n; i++) {
        char c = tolower((unsigned char)s[i]);
        int w = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') ? 1 : -2;
        P[i + 1] = P[i] + w;
    }

    long long lo_val = -2LL * n;
    long long hi_val = (long long)n;
    int range = (int)(hi_val - lo_val) + 1;

    vector<int> fen(range + 2, INT_MAX);

    int best_len = 0, best_count = 0;

    for (int j = 0; j <= n; j++) {
        long long v = P[j];
        int idx_v = (int)(hi_val - v + 1);

        if (j > 0) {
            int res = INT_MAX;
            int k = idx_v;
            while (k > 0) {
                if (fen[k] < res) res = fen[k];
                k -= k & (-k);
            }
            if (res != INT_MAX) {
                int length = j - res;
                if (length > best_len) { best_len = length; best_count = 1; }
                else if (length == best_len) best_count++;
            }
        }

        int k = idx_v;
        while (k <= range) {
            if (fen[k] > j) fen[k] = j;
            k += k & (-k);
        }
    }

    count = best_count;
    return best_len;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int count = 0;
    int result = longestBalancedSubstring(s, count);

    if (result == 0) {
        fout << "No\n" << "solution\n";
    } else {
        fout << result << "\n" << count << "\n";
    }

    fout.close();

    return 0;
}
```

---

## Java

```java
import java.io.*;
import java.util.*;

class Result {
    /*
     * Complete the 'longestBalancedSubstring' function below.
     *
     * The function is expected to return an INTEGER_ARRAY of size 2:
     *   result[0] = length of the longest balanced substring (0 if none exists)
     *   result[1] = number of balanced substrings of that length
     */

    public static int[] longestBalancedSubstring(String s) {
        int n = s.length();

        long[] P = new long[n + 1];
        P[0] = 0;
        for (int i = 0; i < n; i++) {
            char c = Character.toLowerCase(s.charAt(i));
            int w = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') ? 1 : -2;
            P[i + 1] = P[i] + w;
        }

        long loVal = -2L * n;
        long hiVal = (long) n;
        int range = (int) (hiVal - loVal) + 1;

        int[] fen = new int[range + 2];
        Arrays.fill(fen, Integer.MAX_VALUE);

        int bestLen = 0, bestCount = 0;

        for (int j = 0; j <= n; j++) {
            long v = P[j];
            int idxV = (int) (hiVal - v + 1);

            if (j > 0) {
                int res = Integer.MAX_VALUE;
                int k = idxV;
                while (k > 0) {
                    if (fen[k] < res) res = fen[k];
                    k -= k & (-k);
                }
                if (res != Integer.MAX_VALUE) {
                    int length = j - res;
                    if (length > bestLen) { bestLen = length; bestCount = 1; }
                    else if (length == bestLen) bestCount++;
                }
            }

            int k = idxV;
            while (k <= range) {
                if (fen[k] > j) fen[k] = j;
                k += k & (-k);
            }
        }

        return new int[]{bestLen, bestCount};
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        int[] result = Result.longestBalancedSubstring(s);

        if (result[0] == 0) {
            bufferedWriter.write("No");
            bufferedWriter.newLine();
            bufferedWriter.write("solution");
            bufferedWriter.newLine();
        } else {
            bufferedWriter.write(String.valueOf(result[0]));
            bufferedWriter.newLine();
            bufferedWriter.write(String.valueOf(result[1]));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
        bufferedReader.close();
    }
}
```

---

## Notes on Edge Cases Handled

| Case | Handling |
|---|---|
| No balanced substring exists | `best_len` stays `0`; output is `No` / `solution` on two lines |
| Case-insensitive vowels | All languages lowercase each character before checking vowel membership |
| Weight bounds | `P` values are bounded in `[-2n, n]`, so the Fenwick tree can be indexed directly by a linear transform of the value — no coordinate compression via sorting/binary search is needed |
| Multiple substrings tying for the max length | `best_count` is incremented (not reset) whenever a new match ties the current `best_len` |
| Overflow of prefix sums | `P` is stored as `long long` / `long` (C, C++, Java) since consonant weight `-2` can push values to `±2n`, which may exceed `int` range for very large `n` |
| Empty or all-consonant / all-vowel strings | Still processed correctly through the same prefix-sum + Fenwick logic; no special-casing required |