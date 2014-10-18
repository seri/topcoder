-- Start with D2L2 Jumping first
module PeriodicJumping where

type Range = (Int, Int)

-- Refer to D2L2 Jumping for intimacy with the problem
jump :: Range -> Int -> Range
jump (lo, hi) d | d <= lo   = (lo - d, hi + d)
                | d <= hi   = (0     , hi + d)
                | otherwise = (d - hi, hi + d)

-- In step one, we jump as many double cycles of jumpLengths as possible
-- Notice that the code already covers the case p == 0
stepOne :: Int -> [Int] -> (Int, Range)
stepOne target ds = (p * (2 * length ds), (0, target - q)) where
    (p, q) = target `divMod` (2 * sum ds)

-- The problem is then reduced to D2L2 Jumping except that we start with an
-- initial range we got from stepOne instead of (0, 0)
stepTwo :: Int -> Range -> [Int] -> Int
stepTwo target (lo, hi) = length . takeWhile notYet . 
                          scanl jump (lo, hi) . cycle where
    notYet (lo, hi) = target < lo || target > hi

-- The verbosity is intended for clarity
minimalTime :: Int -> [Int] -> Int
minimalTime x jumpLengths = stepOneTime + 
                            stepTwo target stepOneRange jumpLengths where
    target = abs x
    (stepOneTime, stepOneRange) = stepOne target jumpLengths
