module MovieSeating where

import Data.List
import Foreign.Marshal.Utils (fromBool)

count :: Eq a => (a -> Bool) -> [a] -> Int
count f = sum . map (fromBool . f)

countEmpty :: String -> Int
countEmpty = count (== '.')

perms :: Int -> Int -> Integer
perms k n = foldl f 1 [(n - k + 1) .. n]
    where f x n = x * toInteger n

arrange :: Int -> [String] -> Integer
arrange k = sum . map (perms k . countEmpty)

getSeatings :: Int -> [String] -> Integer
getSeatings 1 hall = toInteger . sum . map countEmpty $ hall
getSeatings k hall = arrange k hall + arrange k (transpose hall)
