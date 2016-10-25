fac 0 = 1
fac n = n * fac (n - 1)

powerOfTwo 0 = 1
powerOfTwo n = 2 *
    powerOfTwo (n - 1)

fib n = fib' 0 1 n
fib' a b 0 = a  -- Одна итерация цикла for
fib' a b n = fib' b (a + b) (n - 1)
