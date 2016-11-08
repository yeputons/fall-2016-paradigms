-- Уже объявлен в языке, писать не надо.
-- data Either a b = Left a | Right b

-- parseBool :: String -> Either String Bool
parseBool "true"  = Right True
parseBool "false" = Right False
parseBool x       = Left ("Invalid value: " ++ x)
