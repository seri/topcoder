module SlimeXSlimesCity where 
import Data.List
import Data.Maybe

possibleName :: Int -> [Int] -> Int -> Bool
possibleName target xs k = (foldl (addExcept k) (xs!!k) $ zip [0..] xs) >= target 
    where addExcept k acc (i, x) = if i == k then acc
                                             else if acc >= x then acc + x
                                                              else acc

mergeSorted :: [Int] -> Int
mergeSorted xs = length xs - (fst . fromJust . find snd . zip [0..] . 
                 map (possibleName (last xs) xs) $ [0..])

merge :: [Int] -> Int
merge = mergeSorted . sort
