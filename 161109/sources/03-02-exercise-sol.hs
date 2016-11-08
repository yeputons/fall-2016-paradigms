data Tree a = Leaf a | Node [Tree a] deriving Show

instance Eq a => Eq (Tree a) where
  (Leaf x) == (Leaf y) = x == y
  (Node x) == (Node y) = x == y
  _        == _        = False

class Reversible f where
   reverse' :: f a -> f a

instance Reversible [] where
   reverse' (x:xs) = (reverse' xs) ++ [x]
   reverse' _      = []

instance Reversible Tree where
   reverse' (Leaf x) = Leaf x
   reverse' (Node x) = Node (fmap reverse' (reverse' x))
