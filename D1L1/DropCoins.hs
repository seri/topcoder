module DropCoins where 

import Data.Array

area :: Array Int (Array Int Char) -> Int -> Int -> Int -> Int -> Int
area a y1 x1 y2 x2 = sum [ isCoin ((a!y)!x) | y <- [y1 .. y2]
                                            , x <- [x1 .. x2] ]
    where isCoin c = if c == 'o' then 1
                                 else 0


cost :: Int -> Int -> Int -> Int -> Int -> Int -> Int
cost h w y1 x1 y2 x2 = x1 + y1 + x3 + y3 + (min x1 x3) + (min y1 y3)
    where x3 = w - x2
          y3 = h - y2

getMinimum :: [String] -> Int -> Int
getMinimum board k = convert $ minimum [ best y1 x1 y2 x2 | y1 <- [0 .. h]
                                                          , x1 <- [0 .. w]
                                                          , y2 <- [y1 .. h]
                                                          , x2 <- [x1 .. w] ]
    where h = (length board) - 1
          w = (length (head board)) - 1
          best y1 x1 y2 x2 = if area a y1 x1 y2 x2 == k then cost h w y1 x1 y2 x2
                                                        else 27000
          convert x = if x == 27000 then -1
                                    else x
          a = fmap (listArray (0, w)) (listArray (0, h) board)
