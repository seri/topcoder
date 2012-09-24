module GravityBomb where
import Data.List

boardToDepths :: [[Char]] -> [Int]
boardToDepths = map $ length . filter (== 'X')

simplifyDepths :: [Int] -> [Int]
simplifyDepths xs = map (\x -> x - y) xs
          where y = minimum xs

depthsToBoard :: Int -> [Int] -> [[Char]]
depthsToBoard n = map (\d -> replicate (n - d) '.' ++ replicate d 'X')

aftermath :: [String] -> [String]
aftermath board = transpose . depthsToBoard (length board) .
                  simplifyDepths . boardToDepths . transpose $ board