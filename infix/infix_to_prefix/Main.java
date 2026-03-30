import java.util.Scanner;

class Node{
    char data;
    Node addr;

    Node(char val){
        data=val;
        addr=null;
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

    void infixTOprefix(String infix){
        StringBuilder revstr = new StringBuilder(infix).reverse();

        for(int i=0;i<revstr.length();i++){
            if(revstr.charAt(i)=='('){
                revstr.setCharAt(i,')');
            }
            else if(revstr.charAt(i)==')'){
                revstr.setCharAt(i,'(');
            }
        }

        StringBuilder prefix = new StringBuilder();

        for(int i=0;i<infix.length();i++){
            char ch = infix.charAt(i);

            if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
                prefix.append(ch);
            }

            else if(ch=='('){
                push(ch);
            }

            else if(ch==')'){
                while(top!=null && top.data!='('){
                    prefix.append(pop());
                }
                pop();
            }

            else{
                while(top!=null && precedence(top.data)>precedence(ch)){
                    prefix.append(pop());
                }
                push(ch);
            }
        }
        while(top!=null){
            prefix.append(pop());
        }
        prefix.reverse();
        System.out.println(prefix);
    }

}



public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String infix = sc.nextLine();
        Stack s = new Stack();
        s.infixTOprefix(infix);
    }
}