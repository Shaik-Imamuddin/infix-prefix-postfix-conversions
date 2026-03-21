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
public:
    Node *top;

    Stack(){
        top=nullptr;
    }

    void push(char val){
        Node *newNode = new Node(val);

        newNode->addr = top;
        top=newNode;
    }

    char pop(){
        if(top==nullptr)
            return '\0';
        
        Node *temp = top;
        char ch = temp->data;
        top=top->addr;
        free(temp);
        return ch;
    }

    int precedence(char ch){
        if(ch=='+' || ch=='-')
            return 1;
        if(ch=='*' || ch=='/')
            return 2;
        return 0;
    }

    void infixTOpostfix(char infix[]){
        char postfix[100];
        int k=0;

        for(int i=0;infix[i]!='\0';i++){

            char ch = infix[i];

            if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
                postfix[k]=ch;
                k++;
            }
            
            else if(ch=='('){
                push(ch);
            }

            else if(ch==')'){
                while(top!=nullptr && top->data!='('){
                    postfix[k]=pop();
                    k++;                   
                }
                pop();
            }

            else{
                while(top!=nullptr && precedence(top->data)>=precedence(ch)){
                    postfix[k]=pop();
                    k++;
                }
                push(ch);
            }
        }
        while(top!=nullptr){
            postfix[k]=pop();
            k++;
        }
        postfix[k]='\0';
        cout<<postfix;
    }
};

int main(){
    char infix[100];
    cin>>infix;
    Stack s;
    s.infixTOpostfix(infix);
    return 0;
}