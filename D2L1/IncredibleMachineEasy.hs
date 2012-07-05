module IncredibleMachineEasy where

gravitationalAcceleration :: [Int] -> Int -> Double
gravitationalAcceleration height t = 2/(x*x)
    where x = (fromIntegral t)/s
          s = sum . (map  $ sqrt . fromIntegral) $ height 
