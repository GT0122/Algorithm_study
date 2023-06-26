n, k = map(int, input().split())

items = []
for i in range(n) :
    w, v = map(int, input().split())
    if w <= k :
        items.append([w, v])

max_value = [0 for _ in range(k+1)]
for w, v in items :
    max_value[w] = max(max_value[w], v)
    for i in range(k, w, -1) :
        max_value[i] = max(max_value[i], max_value[i-w] + v)
    
print(max_value[k])