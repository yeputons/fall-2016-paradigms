class HasSize a where
  size :: a -> Int

instance HasSize [a] where
  size xs = length xs

data Tree a = Nil | Node a (Tree a) (Tree a)
instance HasSize (Tree a) where
  size Nil = 0
  size (Node _ l r) = 1 + size l + size r
