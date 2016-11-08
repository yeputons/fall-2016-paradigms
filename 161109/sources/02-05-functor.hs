data List a = Empty | Cons a (List a) deriving Show

instance Functor List where
  fmap _ Empty = Empty
  fmap f (Cons x xs) = Cons (f x) (fmap f xs)
