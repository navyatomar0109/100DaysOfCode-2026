# Find Lost Tickets


## Python

```python
#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'findLostTickets' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY tickets

def findLostTickets(n, tickets):
    present = [False] * (n + 1)

    for t in tickets:
        present[t] = True

    result = [i for i in range(1, n + 1) if not present[i]]

    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    tickets = list(map(int, input().rstrip().split()))

    result = findLostTickets(n, tickets)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

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
 * Complete the 'findLostTickets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY tickets
 *  3. INTEGER* result_count (set this to the number of missing tickets found)
 */

int* findLostTickets(int n, int* tickets, int tickets_count, int* result_count) {
    bool* present = (bool*)calloc(n + 1, sizeof(bool));

    for (int i = 0; i < tickets_count; i++) {
        present[tickets[i]] = true;
    }

    int* result = (int*)malloc(n * sizeof(int));
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            result[count++] = i;
        }
    }

    free(present);
    *result_count = count;
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char* tickets_line = readline();

    int* tickets = malloc(n * sizeof(int));
    int tickets_count = 0;

    char* token = strtok(tickets_line, " \t\r\n");
    while (token != NULL) {
        tickets[tickets_count++] = parse_int(token);
        token = strtok(NULL, " \t\r\n");
    }

    int result_count;
    int* result = findLostTickets(n, tickets, tickets_count, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", result[i]);
        if (i != result_count - 1) {
            fprintf(fptr, " ");
        }
    }
    fprintf(fptr, "\n");

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || (*endptr != '\0' && !isspace(*endptr))) {
        exit(EXIT_FAILURE);
    }

    return value;
}
```

---

## C++

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'findLostTickets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY tickets
 */

vector<int> findLostTickets(int n, vector<int> tickets) {
    vector<bool> present(n + 1, false);

    for (int t : tickets) {
        present[t] = true;
    }

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string tickets_temp_temp;
    getline(cin, tickets_temp_temp);

    vector<string> tickets_temp = split(rtrim(tickets_temp_temp));

    vector<int> tickets(tickets_temp.size());

    for (size_t i = 0; i < tickets_temp.size(); i++) {
        int tickets_item = stoi(tickets_temp[i]);

        tickets[i] = tickets_item;
    }

    vector<int> result = findLostTickets(n, tickets);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(' ', start)) != string::npos) {
        if (end != start) {
            tokens.push_back(str.substr(start, end - start));
        }

        start = end + 1;
    }

    if (start < str.length()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}
```

---

## Java

```java
import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.math.*;

class Result {

    /*
     * Complete the 'findLostTickets' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. INTEGER_ARRAY tickets
     */

    public static List<Integer> findLostTickets(int n, List<Integer> tickets) {
        boolean[] present = new boolean[n + 1];

        for (int t : tickets) {
            present[t] = true;
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (!present[i]) {
                result.add(i);
            }
        }

        return result;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        String[] ticketsTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> tickets = new ArrayList<>();

        for (int i = 0; i < ticketsTemp.length; i++) {
            int ticketsItem = Integer.parseInt(ticketsTemp[i].trim());
            tickets.add(ticketsItem);
        }

        List<Integer> result = Result.findLostTickets(n, tickets);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(Collectors.joining(" "))
        );
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
```

---

