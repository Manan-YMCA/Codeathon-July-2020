from sys import stdin
input=lambda : stdin.readline().strip()

def cw(a, b, c):
    return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) <= 0

def ccw(a, b, c):
    return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) >= 0

def convex_hull(points):
    points = sorted(points, key=lambda x: (x[0], x[1]))
    up = [points[0]]
    down = [points[0]]
    for i in range(1, len(points)):
        if (i == len(points) - 1 or cw(points[0], points[i], points[-1])):
            while (len(up) >= 2 and not cw(up[-2], up[-1], points[i])):
                up.pop(-1)
            up.append(points[i])
        if (i == len(points) - 1 or ccw(points[0], points[i], points[-1])):
            while len(down) >= 2 and not ccw(down[-2], down[-1], points[i]):
                down.pop(-1)
            down.append(points[i])
    points = up[:] + down[1:-1][::-1]
    return points

n = int(input())
points = []
for i in range(n):
    x, y = map(int, input().split())
    points.append([x,y])
hull = convex_hull(points)
# print(hull)
print(len(hull))
