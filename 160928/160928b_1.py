class A:
    def foo(self):
        print("foo called")
        self.foo = lambda: print("new foo")
x = A()
x.foo()  # foo called
x.foo()  # new foo
del x.foo
x.foo()  # foo called
del A.foo
x.foo()  # new foo
del x.foo
x.foo()  # error
A.foo = lambda x: print("hi,", x)
x.foo()  # hi, <__main__.A object at ...>
