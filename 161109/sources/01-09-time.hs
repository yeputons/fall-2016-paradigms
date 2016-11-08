data Time = Sec  Double | Min  Double
          | Msec Double | Usec Double
          deriving Show
diff (Sec x) (Sec y) = Sec (x - y)
diff x y = diff (to_sec x) (to_sec y)

diff' x y = Sec (x' - y')
  where (Sec x') = to_sec x -- pattern matching
        (Sec y') = to_sec y

to_sec (Sec x) = Sec x
to_sec (Msec x) = Sec (x / 1000)
to_sec (Usec x) = Sec (x / 1000000)
to_sec (Min x) = Sec (x * 60)
