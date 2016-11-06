tests = []
inout = (
    ("\n", ""),
    ("set 123\n0\n",
        ["lock guard", "get flag", "set flag 1", "set result 123", "unlock guard"],
        ["lock guard", "get flag", "set result 123", "set flag 1", "unlock guard"]
    ),
    ("set 123\n1\n", ["lock guard", "get flag", "unlock guard"]),
    ("get\n0\n",     ["lock guard", "get flag", "unlock guard", "-1"]),
    ("get\n1\n123\n",
        ["lock guard", "get flag", "get result", "set flag 0", "unlock guard", "123"],
        ["lock guard", "get flag", "set flag 0", "get result", "unlock guard", "123"],
    ),
)

def fixout(l):
    return "\n".join(l)

def generate():
    res = []
    for k, *v in inout:
        v = list(map(fixout, v))
        res.append((k, v))
    return res

def solve(dataset):
    for k, v1, *v2 in out:
        if k == dataset:
            return v1

def check(reply, clue):
    return reply in clue

print(generate())
