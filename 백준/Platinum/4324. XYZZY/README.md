# [Platinum IV] XYZZY - 4324 

[문제 링크](https://www.acmicpc.net/problem/4324) 

### 성능 요약

메모리: 2164 KB, 시간: 4 ms

### 분류

그래프 이론, 그래프 탐색, 최단 경로, 벨만–포드

### 제출 일자

2026년 1월 12일 16:34:47

### 문제 설명

<blockquote>
<p>ADVENT: /ad´vent/, n.</p>

<p>The prototypical computer adventure game, first designed by Will Crowther on the PDP-10 in the mid-1970s as an attempt at computer-refereed fantasy gaming, and expanded into a puzzle-oriented game by Don Woods at Stanford in 1976. (Woods had been one of the authors of INTERCAL.) Now better known as Adventure or Colossal Cave Adventure, but the TOPS-10 operating system permitted only six-letter filenames in uppercase. See also vadding, Zork, and Infocom.</p>
</blockquote>

<p>It has recently been discovered how to run open-source software on the Y-Crate gaming device. A number of enterprising designers have developed Advent-style games for deployment on the Y-Crate. Your job is to test a number of these designs to see which are winnable.</p>

<p>Each game consists of a set of up to 100 rooms. One of the rooms is the start and one of the rooms is the finish. Each room has an energy value between -100 and +100. One-way doorways interconnect pairs of rooms.</p>

<p>The player begins in the start room with 100 energy points. She may pass through any doorway that connects the room she is in to another room, thus entering the other room. The energy value of this room is added to the player's energy. This process continues until she wins by entering the finish room or dies by running out of energy (or quits in frustration). During her adventure the player may enter the same room several times, receiving its energy each time.</p>

### 입력 

 <p>The input consists of several test cases. Each test case begins with n, the number of rooms. The rooms are numbered from 1 (the start room) to n (the finish room). Input for the n rooms follows. The input for each room consists of one or more lines containing:</p>

<ul>
	<li>the energy value for room i</li>
	<li>the number of doorways leaving room i</li>
	<li>a list of the rooms that are reachable by the doorways leaving room i</li>
</ul>

<p>The start and finish rooms will always have enery level 0. A line containing -1 follows the last test case.</p>

### 출력 

 <p>In one line for each case, output "winnable" if it is possible for the player to win, otherwise output "hopeless".</p>

