module SRMRoomAssignmentPhase where 

import Data.List
import Data.Array

count :: Array Int Int -> [Int] -> Int -> Int
count a is x = length $ filter (> x) $ map (a!) is

countCompetitors :: [Int] -> Int -> Int
countCompetitors ratings k = 
    case findIndex (== x) sorted of
        Just p -> count a (takeWhile (< n) (iterate (+k) (mod p k))) x
        Nothing -> -1
    where sorted = sortBy (flip compare) ratings
          n = length ratings
          x = head ratings
          a = listArray (0, n - 1) sorted
