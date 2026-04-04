#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[100];
    struct Node *addr;
};

struct Node *top=NULL;

void push(char val[]){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->data,val);
    newNode->addr = top;
    top=newNode;
}

void pop(char res[]){
    if(top==NULL){
        strcpy(res,"");
        return;
    }

    struct Node* temp = top;
    strcpy(res,temp->data);
    top=top->addr;
    free(temp);
}

int isOperator(char ch){
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
}

void prefixTOInfix(char prefix[]){
    int len=strlen(prefix);

    for(int i=len-1;i>=0;i--){
        char ch = prefix[i];

        if(isOperator(ch)){
            char op1[50],op2[50],temp[100];

            pop(op1);
            pop(op2);

            strcpy(temp,"(");
            strcat(temp,op1);

            int len=strlen(temp);
            temp[len]=ch;
            temp[len+1]='\0';

            strcat(temp,op2);
            strcat(temp,")");
            push(temp);
        }
        //if operand covert into string and push into stack
        else{
            char operand[2];
            operand[0]=ch;
            operand[1]='\0';

            push(operand);
        }
    }
    char res[100];
    pop(res);
    printf("%s",res);
}

int main(){
    char prefix[100];
    scanf("%s",prefix);
    prefixTOInfix(prefix);
    return 0;
}