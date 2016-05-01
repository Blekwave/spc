while True:
    n = int(input())
    if n == -1:
        break
    l = [1, 1]
    for m in range(2, n + 1):
        l.append(sum(
            (l[i] * l[m - i - 1] for i in range(m))
        ))
    print(l[n])
