data Tree = Leaf Int | Node Int Tree Tree deriving Show

tree_sum (Leaf x) = x
tree_sum (Node x l r) = x + tree_sum l + tree_sum r

inf_tree = level 1
  where
    level x = Node x level' level'
      where
        level' = level (x + 1)
