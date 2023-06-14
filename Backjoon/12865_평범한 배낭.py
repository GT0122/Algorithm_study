n, k = map(int, input().split())

items = []
for i in range(n) :
    items.append([int(j) for j in input().split()])
items.sort(key = lambda x : (x[1] / x[0], x[0]), reverse=True)

q = []
weight = 0
for item in items :
    if item[0] > k :
        continue
    
    if weight + item[0] <= k :
        q.append(item)
        weight += item[0]
    else :
        del_list = []
        cor_v = 0
        cor_w = 0
        while True :
            if weight + (item[0] - cor_w) <= k :
                break
            w, v = q.pop(0)
            del_list.append([w, v])
            cor_v += v
            cor_w += w
        if cor_v < item[1] :

            q.append(item)
            weight += item[0] - cor_w
        elif cor_v == item[1] :
            if cor_w >= item[0] :
                q.append(item)
                weight += item[0] - cor_w
            else :
                for w, v in del_list :
                    q.append([w, v])
        else :
            for w, v in del_list :
                q.append([w, v])
print(q)
print(sum([v for w, v in q]))
