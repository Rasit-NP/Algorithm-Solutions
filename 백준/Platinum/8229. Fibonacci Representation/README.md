# [Platinum IV] Fibonacci Representation - 8229 

[문제 링크](https://www.acmicpc.net/problem/8229) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 수학

### 제출 일자

2026년 1월 6일 15:33:51

### 문제 설명

<p>The Fibonacci sequence is a sequence of integers, called Fibonacci numbers, defined as follows:</p>

<ul>
	<li>Fib<sub>0</sub>=0, Fib<sub>1</sub>=1, Fib<sub>n</sub>=Fib<sub>n-2</sub>+Fib<sub>n-1</sub> for n > 1</li>
</ul>

<p>Its initial elements are: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...</p>

<p>Byteasar investigates representations of numbers as sums or differences of Fibonacci numbers. Currently he is wondering what is the minimum representation, i.e., one with the minimum number of (not necessarily different) Fibonacci numbers, for a given positive integer k. For example, the numbers 10, 19, 17, and 1070 can be minimally represented using, respectively, 2, 2, 3, and 4 Fibonacci numbers as follows:</p>

<ul>
	<li>10=5+5</li>
	<li>19=21-2</li>
	<li>17=13+5-1</li>
	<li>1070=987+89-5-1</li>
</ul>

<p>Help Byteasar! Write a program that, for a given positive integer k determines the minimum number of Fibonacci numbers required to represent k as their sum or difference.</p>

### 입력 

 <p>In the first line of the standard input a single positive integer p is given (1 ≤ p ≤ 10) that denotes the number of queries. The following p lines hold a single positive integer k each (1 ≤ k ≤ 4⋅10<sup>17</sup>).</p>

### 출력 

 <p>For each query your program should print on the standard output the minimum number of Fibonacci numbers needed to represent the number k as their sum or difference.</p>

