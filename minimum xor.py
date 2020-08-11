import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')


from collections import defaultdict
import sys

def generate(src, graph):
    queue = []
    visited = [0] * n
    queue.append(src)
    visited[src] = 1
    len_q = 1
    while len_q:
        cur_node = queue.pop()
        len_q -= 1
        for node in graph[cur_node]:
            if visited[node]==0:
                parent[node] = cur_node
                rank[node] = rank[cur_node] + 1
                visited[node] = 1
                queue.append(node)
                len_q += 1
    return

def find_lca(a, b, path):
    if parent[a] == parent[b]:
        return parent[a]
    if rank[a] > rank[b]:
        a, b = b, a
    while rank[a] != rank[b]:
        b = parent[b]
    if a == b:
        return a
    else:
        while a!=b:
            a = parent[a]
            b = parent[b]
        return a

def find_path(a, b, lca):
    path = []
    while a!=lca:
        path.append(a)
        a = parent[a]

    while b!= lca:
        path.append(b)
        b = parent[b]
    path.append(lca)
    return path

def find_min_xor(path):
    min1 = sys.maxsize
    n = len(path)
    for i in range(1,n):
        min1 = min(min1, path[i] ^ path[i-1])
    return min1


n, q = map(int, input().split())
cost = list(map(int, input().split()))

graph = defaultdict(list)

for i in range(n-1):
    p1, p2 = map(int, input().split())
    graph[p1-1].append(p2-1)
    graph[p2-1].append(p1-1)

rank = [0]*n
parent = [i for i in range(n)]
generate(0, graph)
# print(parent)
# print(rank)

for i in range(q):
    p1, p2 = map(int, input().split())
    if p1==p2:
        print(2147483647)
    else:
        lca = find_lca(p1 -1, p2 -1, [])
        # print(lca)
        path = find_path(p1-1, p2-1, lca)
        # print(path)
        cost1 = [cost[i] for i in path]
        cost1.sort()
        # print(cost1)
        print(find_min_xor(cost1))




""""
11 7
20 20 20 20 20 20 20 20 20 20 20 20
1 2
1 3
2 6
6 7
3 4
4 8
8 9
3 5
5 10
10 11
1 6
1 1
1 3
3 2
4 6
7 4
9 11

"""