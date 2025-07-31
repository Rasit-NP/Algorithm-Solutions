import sys, math

up, down, h = map(int, sys.stdin.readline().split())

print(math.ceil((h-up)/(up-down)) + 1)