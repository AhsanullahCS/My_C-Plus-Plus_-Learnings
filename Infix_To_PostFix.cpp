#include <iostream>
using namespace std;

char stack[40]; 
int top = -1;

void push(char ch)
{
    if(top == 39)
    return;

    stack[++top] = ch;
}
char pop()
{
    if(top == -1)
    return '\0';

    return stack[top--];
}
char peak()
{
    if(top == -1)
    return '\0';

    return stack[top];
}
int precidence(char op)
{
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
}
void infix_to_Postfix(string infix)
{
    string postfix = "";
    for(int i=0; i<infix.length(); i++)
    {
        char ch = infix[i];

        if(ch == ' ')
            continue;

        else if(isalnum(ch))
            postfix += ch;
        
        else if(ch == '(')
           push(ch);

        else if(ch == ')')
        {
            while(peak() != '(' && top != -1)
            {
            postfix += pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && precidence(peak()) >= precidence(ch))
            {
                postfix += pop();
            }
            push(ch);
        }

        while(top != -1)
        {
            postfix += pop();
        }
         cout << "POSTFIX EXPRESSION: " << postfix << endl;
    }
}






int main()
{
    string infix;
    cout<<"ENTER THE INFIX EXPRESSION"<<endl;
    getline(cin , infix);

    infix_to_Postfix(infix);
    return 0;
}