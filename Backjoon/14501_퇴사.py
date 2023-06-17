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

day = 0
max_profit = 0
while (day + 1) < n :
    today_t = time[day]
    today_p = profit[day]
    iscouncel = True
    if today_t > (n - day + 1) :
        iscouncel = False
    elif today_t > 1 :
        p = sum(profit[day+1:day+today_t])
        if today_p < p :
            iscouncel = False
    if iscouncel :
        max_profit += today_p
        day += today_t
    else :
        day += 1
    print(day, max_profit)

print(max_profit)