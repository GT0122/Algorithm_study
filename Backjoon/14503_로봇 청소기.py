n, m = map(int, input().split())
r, c, d = map(int, input().split())

dir = ((-1, 0), (0, 1), (1, 0), (0, -1))
maps = [[int(i) for i in input().split()] for _ in range(n)]

count = 0
while True :
    if maps[r][c] == 0 :
        maps[r][c] = 2
        count += 1
        print(r, c)
    
    d = (d - 1) % 4
    sr, sc = dir[d]
    if maps[r+sr][c+sc] == 0 :
        r += sr
        c += sc
        continue

    for (sr, sc) in dir :
        tr, tc = r + sr, c + sc
        if tr >= 0 and tr < n and tc >= 0 and tc < m :
            if maps[tr][tc] == 0 :
                break
    else :
        sr, sc = dir[d]
        if maps[r-sr][c-sc] == 1 :
            break
        r -= sr
        c -= sc

print(count)