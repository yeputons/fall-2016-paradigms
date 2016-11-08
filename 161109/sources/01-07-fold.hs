data BinOp = Add | Sub | Mul | Div deriving Show
data Tree = Number Int
          | Reference String
          | BinaryOperation BinOp Tree Tree
          deriving Show
-- Глубокий pattern matching
fold' Sub (Reference a) (Reference b) | a == b = Number 0
fold' Mul (Reference _) (Number 0)             = Number 0
fold' Mul (Number 0)    (Reference _)          = Number 0
fold' op a b = BinaryOperation op a b
-- Рекурсивное сворачивание выражений
fold (BinaryOperation op a b) =
    fold' op (fold a) (fold b)
fold x = x
