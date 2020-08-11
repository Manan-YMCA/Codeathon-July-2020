import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

from collections import defaultdict

def bfs(src, n):
    distance = [0]*(n+1)
    visited = [0]*(n+1)
    queue = [src]
    visited[src] = 1
    while queue:
        cur_node = queue.pop(0)
        for node in graph[cur_node]:
            if visited[node] == 0:
                distance[node] = distance[cur_node] + 1
                visited[node] = 1
                queue.append(node)
    answer = []
    max = 0
    for i in range(1, n+1):
        if distance[i] == max:
            answer.append(i)
        elif distance[i] > max:
            answer = [i]
            max = distance[i]
    # print(answer)
    return answer, max

for t in range(int(input())):
    n = int(input())

    graph = defaultdict(list)
    for i in range(n-1):
        x,y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)

    A_corner = []
    B_corner = []

    initial_nodes, max1 = bfs(1, n)
    max = 0
    # print(initial_nodes)
    for node in initial_nodes:
        if (node not in A_corner) and (node not in B_corner):
            points, max1 = bfs(node, n)
            if max1==max:
                A_corner.append(node)
                for j in points:
                    if (j not in B_corner) and (j not in A_corner):
                        B_corner.append(j)
            elif max1>max:
                A_corner = [node]
                B_corner = points
                max = max1

    # print(A_corner)
    # print(B_corner)
    print(len(A_corner)*len(B_corner)*2)
