#include <stadio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
void top = -1;
void push(char ch)
{
stack[++top] = ch;
}
char pop(){
	return stack[top--];
}
char peek(){
	return stack[top];
}
int isEmpty(){
	return top == -1;
}
int precedence(char op){
	if(op == '+' || op == '-') return 1;
	if(op == '*' || op == '/') return 2;
	return 0;
}
void infixToPostfix(char infix[]){
	char postfix[SIZE];
		 int j =0;
		 int i;
		 for(i = 0; infix[i] != '\0'; i++){
		 	char ch = infix[i];
		 	if(isalpha(ch)){
		 		postfix[j++] = ch;
	 		
		    }
		    else if(ch =='('){
		    	push(ch);
		    	
	    	}
	    	else if(ch ==')'){
	    		while(!isEmpty() && peek() != '('){
	    			postfix[j++] = pop();
				}
				pop();
				
			}
	    	
	    	
		 }
}
