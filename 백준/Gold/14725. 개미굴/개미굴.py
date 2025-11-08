import sys
sys.setrecursionlimit(1<<20)

class Node():
    def __init__(self, value=None):
        self.value = value
        self.childs = {}

def init(n):
    global root
    root = Node()
    for _ in range(n):
        inputs = sys.stdin.readline().rstrip().split()
        node = root
        k = int(inputs[0])
        for i in range(1, k+1):
            val = inputs[i]
            if val not in node.childs:
                node.childs[val] = Node(val)
            node = node.childs[val]

def dfs(node, depth):
    print('--'*depth, end='')
    print(node.value)
    for value in sorted(node.childs):
        dfs(node.childs[value], depth+1)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    init(n)
    for value in sorted(root.childs):
        dfs(root.childs[value], 0)