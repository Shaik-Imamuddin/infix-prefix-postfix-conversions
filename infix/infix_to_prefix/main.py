class Node:
    def __init__(self,val):
        self.data=val
        self.addr=None
    
class Stack:
    def __init__(self):
        self.top=None
    
    def push(self,val):
        newNode = Node(val)

        newNode.addr = self.top
        self.top=newNode
    
    def pop(self):
        if self.top is None:
            return
        temp = self.top
        ch=temp.data
        self.top=self.top.addr
        return ch

    def precedence(self,ch):
        if ch=='+' or ch=='-':
            return 1
        if ch=='*' or ch=='/':
            return 2
        return 0

    def infixToprefix(self,infix):
        revstr = list(infix[::-1])

        for i in range(len(revstr)):
            if revstr[i]=='(':
                revstr[i]=')'
            elif revstr[i]==')':
                revstr[i]='('
        
        revstr = "".join(revstr)

        prefix=[]

        for ch in revstr:

            if ch.isalpha():
                prefix.append(ch)

            elif ch == '(':
                self.push(ch)

            elif ch == ')':
                while self.top is not None and self.top.data!='(':
                    prefix.append(self.pop())
                self.pop()
            
            else:
                while self.top is not None and self.precedence(self.top.data)>self.precedence(ch):
                    prefix.append(self.pop())
                self.push(ch)

        while self.top is not None:
            prefix.append(self.pop())
        
        prefix.reverse()
        print("".join(prefix))

infix=input()
s=Stack()
s.infixToprefix(infix)