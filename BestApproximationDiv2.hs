module BestApproximationDiv2 where 
import Data.Char 
import Data.List
import Data.Maybe

showResult :: (Int, Int, Int) -> String
showResult (a, b, x) = show a ++ "/" ++ show b ++ " has "  
                    ++ show x ++ " exact digits" 

compareDigits :: [Int] -> [Int] -> Ordering
compareDigits xs [] = EQ
compareDigits (x:xs) (y:ys) = case compare x y of
                                  EQ -> compareDigits xs ys
                                  order -> order

toDigit :: Char -> Int
toDigit c = ord c - ord '0'

preciseDivision :: Int -> Int -> [Int]
preciseDivision a b = div a' b : preciseDivision (mod a' b) b
           where a' = 10 * a

estimate :: [Int] -> Double
estimate = sum . zipWith (flip (/)) (iterate (*10) 10) . 
           map fromIntegral

bestNumerator :: [Int] -> Double -> Int -> Maybe Int
bestNumerator ds p b = 
    case find atLeast . map (pair ds b) $ [pivot .. ] of
        Just (a, EQ) -> Just a
        otherwise -> Nothing
    where pivot = truncate $ p * fromIntegral b
          pair ds b a = (a, compareDigits (preciseDivision a b) ds)
          atLeast (a, order) = order /= LT

bestResult :: Int -> [Int] -> Maybe (Int, Int, Int)
bestResult n ds = fromMaybe Nothing . find isJust . 
                  map (toResult ds $ estimate ds) $ [1..n]
    where toResult ds p b = case bestNumerator ds p b of
                                Just a -> Just (a, b, 1 + length ds)
                                Nothing -> Nothing

findFraction' :: Int -> [Int] -> (Int, Int, Int)
findFraction' n = fromJust . last . takeWhile isJust . 
                  map (bestResult n) . inits

findFraction :: Int -> String -> String
findFraction n = showResult . findFraction' n .
                 map toDigit . tail . tail      
