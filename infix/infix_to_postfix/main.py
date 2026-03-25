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
            return
        temp = self.top
        ch = temp.data
        self.top = self.top.addr
        return ch
    
    def precedence(self,ch):
        if ch=='+' or ch=='-':
            return 1
        if ch=='*' or ch=='/':
            return 2
        return 0
    
    def infixTopostfix(self,infix):
        postfix=""

        for i in infix:
            if (i>='a' and i<='z') or (i>='A' and i<='Z'):
                postfix+=i
            
            elif i=='(':
                self.push(i)

            elif i==')':
                while self.top is not None and self.top.data!='(':
                    postfix+=self.pop()
                self.pop()

            else:
                while self.top is not None and self.precedence(self.top.data)>=self.precedence(i):
                    postfix+=self.pop()
                
                self.push(i)

        while self.top is not None:
            postfix+=self.pop()
        print(postfix)

s=Stack()
infix = input()
s.infixTopostfix(infix)