import java.util.Scanner;

class Node{
    char data;
    Node addr;

    Node(char val){
        data=val;
        addr = null;
    }
}

class Stack{
    Node top;

    Stack(){
        top=null;
    }

    void push(char val){
        Node newNode = new Node(val);

        newNode.addr=top;
        top=newNode;
    }

    char pop(){
        if(top==null)
            return '\0';

        Node temp = top;
        char ch = temp.data;
        top=top.addr;
        return ch;
    }

    int precedence(char ch){
        if(ch=='+' || ch=='-')
            return 1;
        if(ch=='*' || ch=='/')
            return 2;
        return 0;
    }

    void infixTOpostfix(String infix){
        StringBuilder postfix = new StringBuilder();

        for(int i=0;i<infix.length();i++){

            char ch = infix.charAt(i);

            if((ch>='a' && ch<='z')||ch>='A' && ch<='Z'){
                postfix.append(ch);
            }

            else if(ch=='('){
                push(ch);
            }

            else if(ch==')'){
                while(top!=null && top.data!='('){
                    postfix.append(pop());
                }
                pop();
            }
            
            else{
                while(top!=null && precedence(top.data)>=precedence(ch)){
                    postfix.append(pop());
                }
                push(ch);
            }
        }
        while(top!=null){
            postfix.append(pop());
        }
        System.out.println(postfix);
    }

}

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String infix = sc.nextLine();
        Stack s = new Stack();
        s.infixTOpostfix(infix);
    }
}