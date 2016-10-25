fac 0 = 1
fac n = n * fac (n - 1)

fac_two n | n <= 1    = 1
          | otherwise = n * fac (n - 2)
