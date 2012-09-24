module Spamatronic where
import Data.Char
import Data.Set (Set)
import qualified Data.Set as Set
import Data.List.Split

tokenize :: String -> Set String
tokenize = foldl (flip Set.insert) Set.empty . 
           map (map toUpper) . wordsBy (not . isLetter)

isSpam :: Set String -> Set String -> Bool
isSpam inner outer = 3 * n <= 4 * k
    where k = Set.size $ Set.intersection inner outer
          n = Set.size inner

filterSpam :: [String] -> [String] -> [Int]
filterSpam knownSpam newMail = 
    snd . foldl pair (Set.unions . map tokenize $ knownSpam, []) . 
    zip (iterate (+1) 0) . map tokenize $ newMail
    where pair (spams, ret) (i, mail) = 
              if isSpam mail spams then (Set.union mail spams, ret)
                                   else (spams, ret ++ [i])