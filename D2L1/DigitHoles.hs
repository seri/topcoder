module DigitHoles where

hole :: Int -> Int
hole 0 = 1
hole 4 = 1
hole 6 = 1
hole 8 = 2
hole 9 = 1
hole _ = 0

numHoles :: Int -> Int
numHoles 0 = 0
numHoles n = hole (mod n 10) + numHoles (div n 10)
