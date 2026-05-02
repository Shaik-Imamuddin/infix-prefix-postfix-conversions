import java.util.Scanner;

class Node{
    String data;
    Node addr;

    Node(String val){
        data=val;
        addr=null;
    }
}

class Stack{

    Node top;

    void push(String val){
        Node newNode=new Node(val);
        newNode.addr=top;
        top=newNode;
    }

    String pop(){
        if(top==null)
            return "";

        String val=top.data;
        top=top.addr;
        return val;
    }

    boolean isOperator(char ch){
        return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
    }

    void postfixTOPrefix(String postfix){

        for(int i=0;i<postfix.length();i++){

            char ch=postfix.charAt(i);

            if(isOperator(ch)){

                String op2=pop();
                String op1=pop();

                String temp=ch+op1+op2;
                push(temp);
            }

            else{
                push(String.valueOf(ch));
            }
        }

        System.out.println(pop());
    }
}

public class Main{

    public static void main(String args[]){

        Scanner sc=new Scanner(System.in);
        String postfix=sc.next();

        Stack s=new Stack();
        s.postfixTOPrefix(postfix);
    }
}