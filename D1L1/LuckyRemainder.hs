module LuckyRemainder where
import Data.Char

pow2mod9 :: Int -> Int
pow2mod9 0 = 1
pow2mod9 1 = 2
pow2mod9 2 = 4
pow2mod9 3 = 8
pow2mod9 4 = 7
pow2mod9 5 = 5
pow2mod9 n = pow2mod9 $ mod n 6

luckyRemainder :: [Int] -> Int
luckyRemainder ds = mod (mod (sum ds) 9 * pow2mod9 (length ds - 1)) 9

getLuckyRemainder :: String -> Int
getLuckyRemainder = luckyRemainder . map toDigit
    where toDigit c = ord c - ord '0'
