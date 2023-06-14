n = int(input())
data = {}
parent = {}
for i in range(n) :
    node, l, r = map(int, input().split())
    data[node] = [l, r]
    parent[l] = node
    parent[r] = node

route = set(data.keys()) - set(parent.keys())

route = list(route)
visited = {i+1:False for i in range(n)}
levels = {}
level = 1
index = 0
while index < len(data) :
    start = route[-1]
    l, r = data[start]
    if l == -1 or visited[l] :
        visited[start] = True
        if level not in levels :
            levels[level] = [index, index]
        else :
            levels[level][1] = index
        index += 1

        if r != -1 :
            route.append(r)
            level += 1
    else :
        route.append(l)
        level += 1

    for _ in range(len(route)) :
        d = route.pop()
        if not visited[d] :
            route.append(d)
            break
        else :
            level -= 1

max_width = 0
max_level = 0
for key, (left, right) in levels.items() :
    level_width = right - left + 1
    if level_width > max_width :
        max_width = level_width
        max_level = key
    elif level_width == max_width and key < max_level :
        max_level = key

print(max_level, max_width)