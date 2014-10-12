module Jumping where

toString :: Bool -> String
toString False = "Not able"
toString True = "Able"

type Range = (Int, Int)

canReach :: Int -> Int -> Range -> Bool
canReach x y (lo, hi) = z >= lo * lo && z <= hi * hi where
    z = x * x + y * y

jump :: Range -> Int -> Range
jump (lo, hi) x | x <= lo   = (lo - x, hi + x)
                | x <= hi   = (0     , hi + x)
                | otherwise = (x - hi, hi + x)

ableToGet :: Int -> Int -> [Int] -> String
ableToGet x y = toString . canReach x y . foldl jump (0, 0)
