from collections import deque

r, c, n = map(int, input().split())
n -= 1

graph = [[] for _ in range(r)]

for i in range(r):
    graph[i] = list(input())

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# 이거 말고 시작도 전부터 1이면 그대로 출력해야 됨
while n > 0:
    # 폭탄 설치
    queue = deque([])
    for i in range(r):
        for j in range(c):
            if graph[i][j] == ".":
                graph[i][j] = "O"
            else:
                queue.append((i, j))
    
    n -= 1
    if n == 0:
        break
        
    # 폭탄 터짐
    while queue:
        nowY, nowX = queue.popleft()
        graph[nowY][nowX] = "."
            
        for i in range(4):
            ny = nowY + dy[i]
            nx = nowX + dx[i]
                
            # 범위 안에 있을 때
            if 0 <= ny < r and 0 <= nx < c:
                # 폭탄 터짐
                graph[ny][nx] = "."
    n -= 1

for i in graph:
    print(''.join(i))