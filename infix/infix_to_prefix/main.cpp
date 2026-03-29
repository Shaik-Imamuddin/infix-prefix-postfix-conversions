#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *addr;

    Node(char val){
        data=val;
        addr=nullptr;
    }
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top=nullptr;
    }

    void push(char val){
        Node *newNode = new Node(val);
        
        newNode->addr=top;
        top=newNode;
    }

    char pop(){
        if(top==nullptr)
            return '\0';
        Node *temp=top;
        char ch =temp->data;
        top=top->addr;
        delete temp;
        return ch;
    }

    int precedence(char ch){
        if(ch=='+' || ch=='-')
            return 1;
        if(ch=='*' || ch=='/')
            return 2;
        return 0;
    }

    void infixToprefix(string infix){
        
        int n=infix.length();

        for(int i=0;i<n/2;i++){
            char temp = infix[i];
            infix[i] = infix[n-i-1];
            infix[n-i-1] = temp;
        }

        for(int i=0;i<n;i++){
            if(infix[i]=='(')
                infix[i]=')';
            else if(infix[i]==')')
                infix[i]='(';
        }

        char prefix[100];
        int ind=0;

        for(int i=0;i<n;i++){
            char ch = infix[i];

            if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')){
                    prefix[ind++]=ch;
            }

            else if(ch=='(')
                push(ch);

            else if(ch==')'){
                while(top!=nullptr && top->data!='('){
                    prefix[ind++]=pop();
                }
                pop();
            }
            
            else{
                while(top!=nullptr && precedence(top->data)>precedence(ch)){
                    prefix[ind++]=pop();
                }
                push(ch);
            }
        }
        while(top!=nullptr)
            prefix[ind++]=pop();
        
        prefix[ind]='\0';

        for(int i=0;i<ind/2;i++){
            char temp = prefix[i];
            prefix[i] = prefix[ind-i-1];
            prefix[ind-i-1] = temp;
        }
        cout<<prefix;
    }
};


int main(){

    string infix;
    cin>>infix;
    Stack s;
    s.infixToprefix(infix);
    return 0;
}