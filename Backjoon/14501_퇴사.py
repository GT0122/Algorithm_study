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

day = n-1
profits = []
while day >= 0 :
    today_t, today_p = time[day], profit[day]
    profits.append(day)
    if today_t > 1 :
        temp_profits = set(profits[-today_t:-1])
        loss = 0
        for temp in temp_profits :
            if temp != -1 :
                loss += profit[temp]
        if today_p > loss :
            for i in range(1, today_t) :
                profits[-(i+1)] = day
            for temp in temp_profits :
                if temp != -1 :
                    while temp in profits and profits.index(temp) != -1 :
                        profits[profits.index(temp)] = -1
        else :
            profits[-1] = -1
    day -= 1
    
max_profit = 0
for i in set(profits) :
    if i != -1 :
        max_profit += profit[i]

print(max_profit)