# [XOR Transformations (Easy Version)](https://codeforces.com/contest/2267/problem/F1)

### Limits

time: 4s, memory: 512 megabytes

## Problem

This is the easy version of the problem. The difference between the versions is that in this version, the constraints on $n$ and $q$ are smaller. You can make hacks only if you have solved all versions of this problem.

For an array $b$ consisting of $m$ integers, define a transformation as follows:

*   Write down the values $b_i\oplus b_j$ for all $1\le i\lt j\le m$, where $\oplus$ denotes the bitwise XOR operation..
*   Take the $m$ smallest among the written values.
*   Replace the elements of the array with the taken $m$ values.

For example, consider the transformation of the array $[6, 7, 8, 9, 15]$. We write down the values $1, 1, 6, 7, 8, 9, 14, 14, 15, 15$. After the transformation, the array becomes $[1, 1, 6, 7, 8]$ — the $5$ smallest elements.

You are given an array $a$ consisting of $n$ non-negative integers. Let $\max(a)$ denote the maximum element of the array $a$, and $\min(a)$ — the minimum. Your task is to answer $q$ queries, each of which gives you one integer $x$. For each query, find the value of $\max(a) - \min(a)$ after $x$ transformations on the array. Note that the queries are independent, i.e. before each query, the array $a$ is restored to its original state.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($5\le n\le 2000, 1\le q\le 2000$) — the size of the array and the number of queries.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0\le a_i\lt 2^{30}$).

The next $q$ lines of each test case contain an integer $x$ ($0\le x\lt 2^{30}$).

It is guaranteed that the sum of $n$ and the sum of $q$ over all test cases do not exceed $2000$.

### Output

For each test case, output $q$ integers — the answer to each query.

## Examples
### Input
```
4
5 1
0 0 1 1 1
1
5 2
6 7 8 9 15
0
1
8 2
102 92 15 19 25 54 62 36
2
1
10 1
56 73 81 23 17 92 50 34 67 78
2
```

### Output
```
1
9
7
12
31
7
```

## Note
In the first test case, after one transformation, the array becomes $[0, 0, 0, 0, 1]$. Here $\max(a) - \min(a) = 1 - 0 = 1$.

In the second test case, the initial array is $[6, 7, 8, 9, 15]$. Initially, $\max(a) - \min(a) = 15 - 6 = 9$. After the transformation, the array becomes $[1, 1, 6, 7, 8]$, where $\max(a) - \min(a) = 8 - 1 = 7$.