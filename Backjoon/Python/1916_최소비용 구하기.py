import sys
import heapq

# 읽는 시간이 길어 python에선 필수
input = sys.stdin.readline

n = int(input())
m = int(input())

bus = {i:[] for i in range(1, n+1)}
for _ in range(m) :
    s, e, c = map(int, input().split())
    bus[s].append((e, c))

start, end = map(int, input().split())

# 시작점에서 최소 비용
s_cost = {i:float("inf") for i in range(1, n+1)}
s_cost[start] = 0
# 방문 여부
visited = {i:False for i in range(1, n+1)}

q = []
while start != end :
    # 방문하지 않은 노드라면 진행
    if not visited[start] :
        cost = bus[start]
        s = s_cost[start]
        if len(cost) > 0 :
            for (e, c) in cost :
                s_cost[e] = min(s_cost[e], s + c)
                heapq.heappush(q, (s_cost[e], e))
        visited[start] = True

    start = heapq.heappop(q)[1]    

print(s_cost[end])