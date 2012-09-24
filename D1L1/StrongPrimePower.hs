module StrongPrimePower where 
import Data.List
import Data.Maybe

isPrime :: Int -> Bool
isPrime n = null . filter (\i -> mod n i == 0) . 
            takeWhile (\i -> i * i <= n) $ [2..]

baseExp :: Integer -> [Int]
baseExp n = concatMap tupleToList . maybeToList . find (check n) . 
            filter (isPrime . fst) .  map (getPQ n) $ [2..59]
    where getPQ n q = (round $ (fromIntegral n) ** (1.0 / (fromIntegral q)), q)
          check n (p, q) = (fromIntegral p) ^ q == n
          tupleToList (p, q) = [p, q]

baseAndExponent :: String -> [Int]
baseAndExponent s = baseExp (read s :: Integer)
