import sys

n = sys.stdin.readline()
nums = list(map(int, sys.stdin.readline().split()))
light = list(set(nums))
light.sort()
dic = {}

for i in range(len(light)):
    dic[light[i]] = i

for i in range(len(nums)-1):
    sys.stdout.write(f'{dic[nums[i]]} ')
sys.stdout.write(f'{dic[nums[-1]]}')