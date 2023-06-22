n = int(input())

time, profit = [], []
for i in range(n) :
    t, p = map(int, input().split())
    if (n - i) < t :
        time.append(1)
        profit.append(0)
        continue
    time.append(t)
    profit.append(p)

# DP 해결법 참조
profits = [0 for _ in range(n+1)]
for i in range(n) :
    t, p = time[i], profit[i]
    # 각각의 날자에 최대값으로 갱신
    # 일을 한다면 받을 수 있는 수익
    profits[i + t] = max(profits[i + t], profits[i] + p)
    # 일을 하지 않는 경우의 수익
    profits[i + 1] = max(profits[i + 1], profits[i])
    print(profits)

print(profits[n])