module Target where

draw :: Int -> [String]
draw 1 = [ "#" ]
draw n = (surround . draw) (n - 4)

surround :: [String] -> [String]
surround spiral = top ++ map addSideMargin spiral ++ bottom where
    top = getTopMargin (head spiral)
    bottom = reverse top
    
getTopMargin :: String -> [String]
getTopMargin s = [ "##" ++ s ++ "##"
                 , addSideMargin (replicate (length s) ' ') ]

addSideMargin :: String -> String
addSideMargin s = "# " ++ s ++ " #"
