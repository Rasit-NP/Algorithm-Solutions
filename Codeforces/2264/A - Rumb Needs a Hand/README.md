# [Rumb Needs a Hand](https://codeforces.com/contest/2264/problem/A)

### Limits

time: 1s, memory: 256 megabytes

## Problem

Mr. Rumb visits a prosthetist because his arms have gone numb. The prosthetist can assemble replacements, but their numbered components are out of order. Apparently, even getting a helping hand requires some assembly.

Formally, the labels on the components form a permutation$^{\text{∗}}$ $p$ of length $n$. Mr. Rumb can program a machine to perform the following operation exactly once:

*   choose an integer $m$ ($1 \le m \le n$) and indices $i_1 \lt i_2 \lt \ldots \lt i_m$;
*   reverse the elements of $p$ at the chosen indices. More precisely, for every $j$ from $1$ to $m$, the element at index $i_j$ moves to index $i_{m-j+1}$. All other elements remain unchanged.

The chosen indices do not have to be consecutive. For example, suppose $p = [1, {\color{red}{6}}, 3, {\color{red}{4}}, 5, {\color{red}{2}}]$. If you choose indices $2$, $4$, and $6$, the elements shown in red are reversed, and $p$ becomes $[1, {\color{red}{2}}, 3, {\color{red}{4}}, 5, {\color{red}{6}}]$.

Determine whether Mr. Rumb can sort $p$ in increasing order.

$^{\text{∗}}$A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$).

The second line contains a permutation $p_1, p_2, \ldots, p_n$ of the integers from $1$ to $n$.

### Output

For each test case, output `YES` if it is possible to sort $p$ in increasing order after performing exactly one operation. Otherwise, output `NO`.

You can output the answer in any case (upper or lower). For example, the strings `yEs`, `yes`, `Yes`, and `YES` will be recognized as positive responses.

## Examples
### Input
```
5
1
1
4
4 2 3 1
4
3 4 1 2
5
2 1 3 5 4
6
1 6 3 4 5 2
```

### Output
```
YES
YES
NO
NO
YES
```

## Note
In the first test case, choose the only index. Reversing a single element does not change the permutation, so the requirement to perform exactly one operation is satisfied.

In the second test case, choose indices $1$ and $4$. The resulting permutation is $[1, 2, 3, 4]$.

In the fifth test case, choose indices $2$, $4$, and $6$. Notice that the chosen indices are not consecutive.