module RedAndGreen where 

best :: String -> Int -> Int
best [] _ = 0
best ('R':xs) reds = best xs (reds - 1)
best ('G':xs) reds = min (1 + (best xs reds)) reds

minPaints :: String -> Int
minPaints row = best row (length $ filter (== 'R') row)
