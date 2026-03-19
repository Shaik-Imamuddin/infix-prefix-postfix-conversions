#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node *addr;
};

struct Node *top=NULL;

void push(char val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->addr = top;
    top=newNode;
}

char pop(){
    if(top==NULL)
        return '\0';
    
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
            while(top!=NULL && top->data!='('){
                postfix[k]=pop();
                k++;
            }
            pop();
        }

        else{
            while(top!=NULL && precedence(top->data)>=precedence(ch)){
                postfix[k]=pop();
                k++;
            }
            push(ch);
        }
    }

    while(top!=NULL){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("%s\n",postfix);
}


int main(){
    char infix[100];
    scanf("%s",infix);
    infixTOpostfix(infix);
    return 0;
}