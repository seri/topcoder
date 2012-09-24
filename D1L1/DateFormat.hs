module DateFormat where
import Text.Printf
import Data.Maybe

data Date = Date { day :: Int
                 , month :: Int } 
instance Eq Date where
    (==) (Date d1 m1) (Date d2 m2) = d1 == d2 && m1 == m2
instance Show Date where
    show (Date d m) = show' d ++ "/" ++ show' m
        where show' = printf "%02d"
instance Ord Date where
    (<) (Date d1 m1) (Date d2 m2) = m1 < m2 || (m1 == m2 && d1 < d2)
    (<=) (Date d1 m1) (Date d2 m2) = m1 < m2 || (m1 == m2 && d1 <= d2)

toDate :: String -> Date
toDate [a,b,c,d,e] = Date (read [a,b]) (read [d,e])

rotateDate :: Date -> Date
rotateDate (Date d m) = Date m d

validDate :: Date -> Bool
validDate (Date d m) = m <= 12
    
fixDate :: Maybe Date -> Date -> Maybe Date
fixDate Nothing _ = Nothing
fixDate (Just prev) cur = 
    if prev < cur then if validDate temp && temp < cur && prev < temp 
                           then Just temp
                           else if validDate cur then Just cur
                                                 else Nothing
                  else if validDate temp && prev < temp 
                           then Just temp
                           else Nothing
    where temp = rotateDate cur
    
fixDates :: [Date] -> String
fixDates ds = if length xs == length ds 
                 then unwords . map (show . rotateDate . fromJust) $ xs
                 else ""
   where xs = tail . takeWhile isJust . scanl fixDate (Just (Date 0 0)) $ ds

fromEuropeanToUs :: [String] -> String
fromEuropeanToUs = fixDates . map toDate . words . concat
