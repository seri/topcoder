package BishopMove

func HowManyMoves(r1 int, c1 int, r2 int, c2 int) int {
    switch {
    case r2 == r1 && c2 == c1:
        return 0
    case (r2 - r1 == c2 - c1) || (r2 - r1 == c1 - c2):
        return 1
    case (r1 + c1) % 2 != (r2 + c2) % 2:
        return -1
    }
    return 2
}