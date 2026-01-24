#include <iostream>
using namespace std;

string stack[50];
int top = -1;

void push(string ch)
{
    if(top == 49)
    return;

    stack[++top] = ch;
}
string pop()
{
    if(top == -1)
    return '\0';

    return stack[top--];
}
void postfix_to_infix(string postfix)
{
    for(int i=0; i<postfix.length(); i++)
    {
        char ch = postfix[i];
        
        if(ch == ' ')
        continue;

        else if(isalnum(ch))
        push(string(1 , ch));

        else
        {
            string opt1 = pop();
            string opt2 = pop();
            string final = "("+opt2 + ch + opt1 +")"; 
            push(final);
        }
    }
    cout<<"THE INFIX EXPRESSION IS  "<<pop()<<endl;
}

int main()
{
    string postfix;
    cout<<"ENTE THE POSTFIX EXPRESSION"<<endl;
    getline(cin , postfix);

    postfix_to_infix(postfix);
return 0;
}