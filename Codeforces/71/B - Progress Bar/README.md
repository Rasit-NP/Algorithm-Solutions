# [Progress Bar](https://codeforces.com/contest/71/problem/B)

### Limits

time: 1s, memory: 256 megabytes

## Problem

A progress bar is an element of graphical interface that displays the progress of a process for this very moment before it is completed. Let's take a look at the following form of such a bar.

A bar is represented as _n_ squares, located in line. To add clarity, let's number them with positive integers from 1 to _n_ from the left to the right. Each square has saturation (_a__i_ for the _i_\-th square), which is measured by an integer from 0 to _k_. When the bar for some _i_ (1 ≤ _i_ ≤ _n_) is displayed, squares 1, 2, ... , _i_ - 1 has the saturation _k_, squares _i_ + 1, _i_ + 2, ... , _n_ has the saturation 0, and the saturation of the square _i_ can have any value from 0 to _k_.

So some first squares of the progress bar always have the saturation _k_. Some last squares always have the saturation 0. And there is no more than one square that has the saturation different from 0 and _k_.

The degree of the process's completion is measured in percents. Let the process be _t_% completed. Then the following inequation is fulfilled:

![](https://espresso.codeforces.com/b409a1d17f3e5356e7e72566ff1b99fd47ec1b59.png)

An example of such a bar can be seen on the picture.

![](https://espresso.codeforces.com/c5c3951d407b9d376bf210a8c1a4010bfedcaf36.png)

For the given _n_, _k_, _t_ determine the measures of saturation for all the squares _a__i_ of the progress bar.

### Input

We are given 3 space-separated integers _n_, _k_, _t_ (1 ≤ _n_, _k_ ≤ 100, 0 ≤ _t_ ≤ 100).

### Output

Print _n_ numbers. The _i_\-th of them should be equal to _a__i_.

## Examples
### Input
```
10 10 54
```

### Output
```
10 10 10 10 10 4 0 0 0 0
```