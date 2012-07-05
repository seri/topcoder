module LameKnight where

maxCells :: Int -> Int -> Int
maxCells 1 _ = 1
maxCells _ 1 = 1
maxCells 2 w = min 4 $ div (w + 1) 2
maxCells h w | w < 7 = min 4 w
             | otherwise = w - 2
