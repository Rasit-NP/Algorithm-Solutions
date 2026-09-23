# [Knife's Pill Farm](https://codeforces.com/contest/2264/problem/B)

### Limits

time: 1.5s, memory: 256 megabytes

## Problem

Mr. Knife has drafted $n$ absurd posts for a channel on a chat platform. His goal is to farm pill emoji reactions. Unfortunately, the channel's pill-farming bot uses an unnecessarily elaborate scoring rule.

The drafts have absurdity ratings $a_1, a_2, \ldots, a_n$, which may be negative. Mr. Knife must publish exactly $m$ drafts in their original order. Their ratings form a subsequence$^{\text{∗}}$ $b$ of $a$ with length $m$.

His pill score starts at $0$. When he publishes the $i$\-th chosen draft, the bot changes his score by $i \cdot (b_i - b_{i-1})$, where $b_0 = 0$. A negative change deducts points, and the score is allowed to become negative. Thus, his final pill score is 

$$\sum_{i = 1}^{m} i \cdot (b_i - b_{i - 1}).$$

What is the maximum pill score Mr. Knife can obtain by choosing which drafts to publish?

$^{\text{∗}}$A sequence $a$ is a subsequence of a sequence $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) elements from arbitrary positions.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le m \le n \le 2 \cdot 10^5$) — the number of drafts and the number of posts Mr. Knife must publish.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^7 \le a_i \le 10^7$) — the absurdity ratings of the drafts.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the maximum pill score Mr. Knife can obtain by publishing exactly $m$ drafts in their original order.

## Examples
### Input
```
6
5 3
0 8 1 7 3
4 3
0 -4 10 -2
4 2
0 5 -2 4
6 3
0 9 8 7 6 5
1 1
7
3 2
5 -100 4
```

### Output
```
20
34
10
15
7
108
```

## Note
In the first test case, Mr. Knife can publish the drafts with ratings $[0, 1, 7]$. His final pill score is 

$$1 \cdot (0 - 0) + 2 \cdot (1 - 0) + 3 \cdot (7 - 1) = 20.$$

In the second test case, he can publish the drafts with ratings $[0, -4, 10]$. The second post deducts points, but the third post more than makes up for it. His final pill score is 

$$1 \cdot (0 - 0) + 2 \cdot (-4 - 0) + 3 \cdot (10 - (-4)) = 34.$$