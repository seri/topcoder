class InfiniteString
    def equal(s, t)
        ls, lt = s.size, t.size
        n = ls.lcm(lt)
        ss = s * (n / ls)
        tt = t * (n / lt)
        return ss == tt ? "Equal" : "Not equal"
    end
end
