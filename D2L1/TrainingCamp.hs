module TrainingCamp where 

canSolve :: String -> String -> Char
canSolve student prob = g $ and $ map (uncurry f) $ zip student prob
    where f _   '-' = True
          f 'X' 'X' = True
          f _    _  = False
          g True    = 'X'
          g False   = '-'

determineSolvers :: [String] -> [String] -> [String]
determineSolvers students probs = 
    map (\student -> map (canSolve student) probs) students