# [Fashionable Array](https://codeforces.com/contest/2267/problem/B)

### Limits

time: 1s, memory: 256 megabytes

## Problem

The mode of an array — is the number that appears the maximum number of times in the array. If several numbers appear the maximum number of times, the mode is the largest among them. For example, the mode of the array $[1, 1, 2]$ is $1$, and the mode of the array $[3, 4]$ is $4$.

You are given an array $a$ consisting of $n$ integers. You may arbitrarily permute the numbers in array $a$ in any order. Your task — is to rearrange the numbers in array $a$ so that the sum of the modes over all prefixes of the array is maximized.

For example, the array $[2, 3, 2]$ can be rearranged as $[3, 2, 2]$. Then the sum of the modes over all prefixes is determined as follows:

*   The prefix of length $1$ is $[3]$. The mode of this prefix is $3$.
*   The prefix of length $2$ is $[3, 2]$. The mode of this prefix is $3$.
*   The prefix of length $3$ is $[3, 2, 2]$. The mode of this prefix is $2$.

Thus, the sum of the modes is $3 + 3 + 2 = 8$. It can be proven that for this arrangement of array $a$, the answer is maximal.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($1 \le n \le 100$) — the size of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots a_n$ ($1 \le a_i \le 100$) — the elements of the array.

### Output

For each test case, output a new array whose sum of the modes over all prefixes is maximal. If there are several optimal answers, output any of them.

## Examples
### Input
```
7
3
2 3 2
6
4 4 2 1 3 1
5
1 3 2 4 2
4
1 1 1 2
7
1 2 3 4 5 6 7
8
1 1 4 2 3 3 3 2
8
4 3 3 3 2 1 4 1
```

### Output
```
3 2 2
4 4 3 2 1 1
4 1 3 2 2
2 1 1 1
7 1 2 3 4 5 6
4 3 2 1 3 3 1 2
4 4 3 3 2 1 1 3
```

## Note
The first test case is described in the statement of the problem.

In the second test case, one suitable arrangement is $[4, 4, 3, 2, 1, 1]$. The mode of each prefix is $4$.

In the third test case, the arrangement $[4, 1, 3, 2, 2]$ is a valid answer. The mode of each prefix:

*   The prefix of length $1$ is $[4]$. The mode of this prefix is $4$.
*   The prefix of length $2$ is $[4, 1]$. The mode of this prefix is $4$.
*   The prefix of length $3$ is $[4, 1, 3]$. The mode of this prefix is $4$.
*   The prefix of length $4$ is $[4, 1, 3, 2]$. The mode of this prefix is $4$.
*   The prefix of length $5$ is $[4, 1, 3, 2, 2]$. The mode of this prefix is $2$.

Then the sum of the modes is $4 + 4 + 4 + 4 + 2 = 18$. It can be proven that this arrangement maximizes the sum of the modes.