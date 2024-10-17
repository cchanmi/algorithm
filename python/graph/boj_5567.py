# 자신의 친구와 친구의 친구 초대
# 1부터 N까지

n = int(input())
m = int(input())

graph = [[] for _ in range(n+1)]

for i in range(m):
    start, end = map(int, input().split())
    graph[start].append(end)
    graph[end].append(start)

result = []
visited = [False] * (n+1)
print(graph)

def dfs(start, depth):
    if depth == 2:
        return
    else:
        for now in graph[start]:
            # 방문하지 않았을 때
            if not visited[now]:
                visited[now] = True
                result.append(now)
            
            dfs(now, depth+1)
# 1로 시작을 하면?
visited[1] = True
dfs(1, 0)
print(len(result))