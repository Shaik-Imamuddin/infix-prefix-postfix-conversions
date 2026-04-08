class Node:
    def __init__(self,val):
        self.data=val
        self.addr=None
    

class Stack:
    def __init__(self):
        self.top = None

    def push(self,val):
        newNode = Node(val)
        newNode.addr = self.top
        self.top = newNode

    def pop(self):
        if self.top is None:
            return ""
    
        val = self.top.data
        self.top = self.top.addr
        return val

    def isOperator(self,ch):
        return ch in "+-*/"
    
    def prefixToinfix(self,prefix):
        for i in range(len(prefix)-1,-1,-1):
            ch = prefix[i]

            if self.isOperator(ch):
                op1 = self.pop()
                op2 = self.pop()

                temp = "("+op1+ch+op2+")"
                self.push(temp)
            else:
                self.push(ch)

        print(self.pop())

prefix=input()
s=Stack()
s.prefixToinfix(prefix)