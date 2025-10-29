# [Platinum V] Sum of a Function - 25853 

[문제 링크](https://www.acmicpc.net/problem/25853) 

### 성능 요약

메모리: 2092 KB, 시간: 164 ms

### 분류

수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2025년 10월 29일 16:17:11

### 문제 설명

<p>Everyone knows that Arup loves prime numbers! This is why he teaches the cryptography course at UCF. Recently, Arup defined the following function on positive integers, n, greater than 1:</p>

<p>f(n) = the smallest prime factor of n</p>

<p>For example, f(14) = 2, f(15) = 3, f(16) = 2 and f(17) = 17.</p>

<p>Using this function, we can generate a sequence of terms f(s), f(s+1), f(s+2), …, f(e), where s designates the starting function input and e designates the ending function input.</p>

<p>Arup thinks these sequences are interesting, but what he’s really curious about is finding the sum of the k minimum elements in one of these sequences. Can you write a program to help him?</p>

<p>Given s, e, and k, find the sum of the k minimum values in the sequence f(s), f(s+1), f(s+2), …, f(e).</p>

### 입력 

 <p>The first and only input line will contain three positive integers, s (2 ≤ s ≤ 10<sup>18</sup>), e (s+100 ≤ e ≤ s+10<sup>6</sup>), and k (1 ≤ k ≤ 0.9 * (e – s + 1)), representing (respectively) the starting function input, the ending function input, and the number of minimum terms to sum.</p>

### 출력 

 <p>On a line by itself, print the sum of the k minimum terms of the designated sequence.</p>

