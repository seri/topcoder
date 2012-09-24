module SRMCards where

import Data.List

maxTurns' :: [Int] -> Int
maxTurns' [] = 0
maxTurns' [x] = 1
maxTurns' (x:y:ys) | x == y - 1 = 1 + maxTurns' ys 
                   | otherwise  = 1 + maxTurns' (y:ys)

maxTurns :: [Int] -> Int
maxTurns cards = maxTurns' (sort cards)
