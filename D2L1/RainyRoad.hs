module RainyRoad where 

toString :: Bool -> String
toString False = "NO"
toString True  = "YES"

passable :: (Char, Char) -> Bool
passable ('W', 'W') = False
passable _ = True

isReachable :: [String] -> String
isReachable road = toString $ all passable $ zip (road!!0) (road!!1)
