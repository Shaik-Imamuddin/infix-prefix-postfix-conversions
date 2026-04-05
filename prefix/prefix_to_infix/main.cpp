#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    string data;
    Node *addr;

    Node(string val){
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

    void push(string val){
        Node *newNode = new Node(val);
        newNode->addr=top;
        top=newNode;
    }

    string pop(){
        if(top==nullptr)
            return "";
        string val = top->data;
        top=top->addr;
        return val;
    }

    bool isOperator(char ch){
        return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
    }

    void prefixTOinfix(string prefix){
        for(int i=prefix.length()-1;i>=0;i--){
            char ch = prefix[i];

            if(isOperator(ch)){
                string op1=pop();
                string op2=pop();

                string temp = "("+op1+ch+op2+")";
                push(temp);
            }
            else{
                push(string(1,ch));
            }
        }
        cout<<pop();
    }
};

int main(){

    string prefix;
    cin>>prefix;

    Stack s;
    s.prefixTOinfix(prefix);
    return 0;
}