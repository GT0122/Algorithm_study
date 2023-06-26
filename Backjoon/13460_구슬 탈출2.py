n, m = map(int, input().split())

maps = []
red = []
blue = []
for i in range(n) :
    inp = input()
    maps.append(list(inp))
    for j, s in enumerate(inp) :
        if s == 'R' :
            red.append([i, j])
        elif s == 'B' :
            blue.append([i, j])

count = 0
dir = ((-1, 0), (0, 1), (1, 0), (0, -1))
visited = [[[[False for _ in range(m)] for _ in range(n)] for _ in range(m)] for _ in range(n)]
while True :
    goal = False
    for (r, b) in zip(red, blue) :
        for (dr, dc) in dir :
            rr, rc = r
            br, bc = b
            if maps[rr+dr][rc+dc] != '#' or maps[br+dr][bc+dc] != '#' :
                r_c = 0
                while True :
                    if maps[rr+dr][rc+dc] == '#' :
                        break
                    rr += dr
                    rc += dc
                    r_c += 1
                b_c = 0
                while True :
                    if maps[br+dr][bc+dc] == '#' :
                        break
                    br += dr
                    bc += dc
                    b_c += 1

                if rr == br and rc == bc :
                    if r_c > b_c :
                        rr -= dr
                        rc -= dc
                    else :
                        br -= dr
                        bc -= dc

    if goal or count > 10 :
        break