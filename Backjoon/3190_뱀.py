n = int(input())
k = int(input())
apple = []
for _ in range(k) :
    row, col = input().split()
    apple.append(row + '_' + col)

l = int(input())
route = []
for _ in range(l) :
    x, c = input().split()
    x = int(x)
    route.append([x, c])

dir = ((0, 1), (1, 0), (0, -1), (-1, 0))
d = 0
second = 1
index = 0
snake = ['1_1']
while True :
    x, c = route[index]
    dr, dc = dir[d]
    head = snake[0]
    row, col = map(int, head.split('_'))
    row, col = row + dr, col + dc
    new_head = str(row) + '_' + str(col)
    if (row < 1 or row > n or col < 1 or col > n) or new_head in snake :
        break

    snake.insert(0, new_head)
    if new_head in apple :
        apple.remove(new_head)
    else :
        snake.pop()
    
    if x == second :
        if index < (len(route) - 1) :
            index += 1
        if c == 'L' :
            d = (d - 1) % 4
        else :
            d = (d + 1) % 4
    second += 1

print(second)