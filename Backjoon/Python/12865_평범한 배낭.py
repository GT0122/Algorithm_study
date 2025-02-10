n, k = map(int, input().split())

items = []
for i in range(n) :
    w, v = map(int, input().split())
    if w <= k :
        items.append([w, v])

# DP 최대값 저장
max_value = [0 for _ in range(k+1)]
for (w, v) in items :
    ismax = False # 해당 무게에서 최대 무게인지 확인
    if max_value[w] < v :
        pre = max_value[w] # 최대 무게라면 이전 무게를 저장
        max_value[w] = v
        ismax = True

    for i in range(k, w, -1) :
        if ismax and i == w * 2 : # 최대 무게라면 w * 2에서 자신의 무게를 두 번 더하게 되니 다르게 처리
            max_value[i] = max(max_value[i], pre + v) # 이전 무게와 더하여 최대값을 계산
            continue
        max_value[i] = max(max_value[i], max_value[i-w] + v)

print(max_value)