n, k = map(int, input().split())

items = []
for i in range(n) :
    items.append([int(j) for j in input().split()])

max_value = 0
while k > 0 :
    pot = 0
    index = 0
    weight = k
    value = 0
    for i, (w, v) in enumerate(items) :
        temp = v * (w / k)
        if temp > pot :
            pot = temp
            weight = w
            value = v
            index = i
        elif temp == pot and w < weight :
            weight = w
            value = v
            index = i

    items.pop(index)
    k -= weight
    max_value += value
    print(max_value, value, pot)
print(max_value)