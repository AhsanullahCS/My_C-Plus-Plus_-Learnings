#include <iostream>
using namespace std;

char stack[50]; int top = -1;

void push(char ch)
{
    if(top == 49)
    return;

    stack[++top] = ch;
}
char pop()
{
    if(top == -1)
    return '\0';

    return stack[top --];
}
char precidence(char ch)
{
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
}
char peak()
{
    if(top == -1)
    return '\0';

    return stack[top];
}
string reverseIt(string str)
{
    string reverse = "";
    for(char i=str.length(); i>=0; i--)
    {
        reverse += str[i];
    }
    return reverse;
}
void infix_to_prefix(string infix)
{
    string prefix = "";
    string InFix = reverseIt(infix);

    for(int i=0; i<InFix.length(); i++)
    {
        char ch = InFix[i];

        if(ch == ' ')
        continue;

        else if(isalnum(ch))
        push(ch);
        
        else if(ch == '(')
        push(ch);

        else if(ch == ')')
        {
            while(top != -1 && peak() != '(')
            {
                prefix += pop();
            }
            pop();
        }
        else
        {
        while(top != -1 && precidence(peak()) >= precidence(ch))
        {
            prefix += pop();
        }
        push(ch); 
        }
    }
    while(top!=-1)
    {
        prefix += pop();
    }
    string PreFix = reverseIt(prefix);
    cout<<"THE PREFIX OF THE EXPRESSION IS ::  "<<PreFix<<endl;
}

int main()
{
    string infix;
    cout<<"ENTER YOUR INFIX"<<endl;
    getline(cin , infix);

    infix_to_prefix(infix);

    return 0;
}
