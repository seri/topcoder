module MissingParentheses where 

countCorrections :: String -> Int
countCorrections par = f par 0 0 
    where f [] p q = p + q
          f ('(':xs) p q = f xs (p + 1) q
          f (')':xs) p q = if p > 0 then f xs (p - 1) q
                                    else f xs p (q + 1)
