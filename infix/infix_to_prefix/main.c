#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node *addr;
};

struct Node *top = NULL;

void push(char val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->addr=top;
    top=newNode;
}

char pop(){
    if(top==NULL){
        return '\0';
    }

    struct Node *temp = top;
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


void infixTOprefix(char infix[]){
    
    int n=strlen(infix);

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

        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
            prefix[ind++]=ch;
        
        else if(ch=='(')
            push(ch);
        
        else if(ch==')'){
            while(top!=NULL && top->data!='('){
                prefix[ind++]=pop();
            }
            pop();
        }

        else{
            while(top!=NULL && precedence(top->data)>precedence(ch)){
                prefix[ind++]=pop();
            }
            push(ch);
        }
    }
    while(top!=NULL)
        prefix[ind++]=pop();
    prefix[ind]='\0';

    for(int i=0;i<ind/2;i++){
        char temp = prefix[i];
        prefix[i]=prefix[ind-i-1];
        prefix[ind-i-1]=temp;
    }
    printf("%s",prefix);
}

int main(){

    char infix[100];
    scanf("%s",infix);
    infixTOprefix(infix);
    return 0;
}