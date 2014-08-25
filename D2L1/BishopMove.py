def howManyMoves(r1, c1, r2, c2):
    if r2 == r1 and c2 == c1:
        return 0
    if abs(r2 - r1) == abs(c2 - c1):
        return 1
    if (r1 + c1) % 2 != (r2 + c2) % 2:
        return -1 
    return 2
