class Node:
    def __init__(self, val):
        self.data = val
        self.addr = None


class Stack:
    def __init__(self):
        self.top = None

    def push(self, val):
        newNode = Node(val)
        newNode.addr = self.top
        self.top = newNode

    def pop(self):
        if self.top is None:
            return ""

        val = self.top.data
        self.top = self.top.addr
        return val

    def isOperator(self, ch):
        return ch in "+-*/"

    def postfixTOinfix(self, postfix):

        for ch in postfix:

            if self.isOperator(ch):
                op2 = self.pop()
                op1 = self.pop()

                temp = "(" + op1 + ch + op2 + ")"
                self.push(temp)

            else:
                self.push(ch)

        print(self.pop())


postfix = input()
s = Stack()
s.postfixTOinfix(postfix)