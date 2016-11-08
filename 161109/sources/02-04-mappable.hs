data List a = Empty | Cons a (List a) deriving Show

class Mappable f where
  map' :: (a -> b) -> f a -> f b

instance Mappable List where
  map' _ Empty = Empty
  map' f (Cons x xs) = Cons (f x) (map' f xs)
