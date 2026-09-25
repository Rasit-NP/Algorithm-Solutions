# [Turn Into a Palindrome](https://codeforces.com/contest/2267/problem/A)

### Limits

time: 1s, memory: 256 megabytes

## Problem

Ali has a string $s$ consisting of $n$ lowercase Latin letters. He also has a character $c$, which is a lowercase Latin letter. In one coin, he can perform the following operation on the string $s$:

*   First, he chooses an index $1\le i\le n$.
*   Then he replaces $s_i$ with the character $c$.

Ali wants to turn the string $s$ into a palindrome$^{\text{∗}}$, but he does not want to spend too many coins on it. Your task — compute the minimum number of coins he has to spend to turn the string $s$ into a palindrome.

$^{\text{∗}}$A string $t$ of length $m$ is a palindrome if $t_i = t_{m-i+1}$ holds for every $1\le i\le m$

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains an integer $n$ and a lowercase Latin letter $c$ ($1\le n\le 100$) — the length of the string $s$ and the character $c$.

The second line of each test case contains the string $s$ consisting of $n$ lowercase Latin letters.

### Output

For each test case, output one number — the minimum number of coins Ali needs to spend for the string to become a palindrome.

## Examples
### Input
```
5
4 b
abca
3 p
xyx
5 e
abcbb
8 d
adbccbad
10 c
codeforces
```

### Output
```
1
0
2
2
8
```

## Note
In the first test case, in one coin, you can replace $s_3$ with $\texttt{b}$. After the replacement, the string becomes $\texttt{abba}$, which is already a palindrome. It can be proven that $1$ is the minimum number of coins required.

In the second test case, the string $s$ is already a palindrome.

In the third test case, it is enough to change $s_1$ and $s_5$ to $\texttt{e}$. After two replacements, the string becomes $\texttt{ebcbe}$, which is already a palindrome.

In the fourth test case, in two coins, you can replace $s_1$ and $s_7$.