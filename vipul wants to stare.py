import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

def bfs(vipul, matrix):

    stack = []
    stack.append(vipul)
    visited = [[0 for i in range(m)] for j in range(n)]
    distance = [[0 for i in range(m)] for j in range(n)]
    visited[vipul[0]][vipul[1]] = 1
    addx = [0, 0, 1, -1]
    addy = [1, -1, 0, 0]

    while stack:
        cur_node = stack.pop(0)
        for i in range(4):
            node = [cur_node[0]+addx[i], cur_node[1]+addy[i]]
            if (n > node[0] > -1 and m > node[1] > -1) and matrix[node[0]][node[1]]!="S" and matrix[node[0]][node[1]]!="R" and visited[node[0]][node[1]] == 0:
                if (node[0]==rx+1 and node[1] == ry+1) or (node[0]==rx+1 and node[1] == ry-1) or (node[0]==rx and node[1] == ry+1) or (node[0]==rx and node[1] == ry-1):
                    return distance[cur_node[0]][cur_node[1]] + 1
                else:
                    stack.append(node)
                    visited[node[0]][node[1]] = 1
                    distance[node[0]][node[1]] = distance[cur_node[0]][cur_node[1]] + 1
    return -1



for t in range(int(input())):
    n, m = map(int, input().split())
    matrix = []

    for i in range(n):
        a1 = input()
        matrix.append(a1)
        if "V" in a1:
            vx = i
            vy = a1.index("V")
        if "R" in a1:
            rx = i
            ry = a1.index("R")

    print(bfs([vx,vy],[rx,ry], matrix))
