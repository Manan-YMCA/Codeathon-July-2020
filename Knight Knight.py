import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

from collections import defaultdict
def bfs(src):
    visited = [0] * n
    queue = [src]
    visited[src] = 1
    cost = [0] * n

    while queue:
        cur_node = queue.pop()
        for node in graph[cur_node]:
            if visited[node] == 0:
                cost[node] = cost[cur_node] + array[node]
                visited[node] = 1
                queue.append(node)
    return cost


n, c, h = map(int, input().split())
c -= 1
array = list(map(int, input().split()))

graph = defaultdict(list)
edges = [0] * n
for i in range(n - 1):
    p1, p2 = map(int, input().split())
    graph[p1 - 1].append(p2 - 1)
    graph[p2 - 1].append(p1 - 1)
    edges[p2 - 1] += 1
    edges[p1 - 1] += 1

leaf = []
for i in range(n):
    if edges[i] == 1:
        leaf.append(i)
cost = bfs(c)

n_leaf = len(leaf)
count = 0
for i in range(n_leaf):
    for j in range(i + 1, n_leaf):
        if h > cost[leaf[i]] + cost[leaf[j]] + array[c]:
            # print(leaf[i], leaf[j])
            count += 1

print(count * 2)