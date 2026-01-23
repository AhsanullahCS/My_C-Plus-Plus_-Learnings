#include <iostream>
using namespace std;

string stack[40]; 
int top = -1;

void push(string ch)
{
    if(top == 39)
    return ;

    stack[++top] = ch;
}
string pop()
{
    if(top == -1)
    return '\0';

    return stack[top--];
}
string peak()
{
    if(top == -1)
    return '\0';

    return stack[top];
}

string reverse(string str)
{
    string reverse = "";
    for(int i=str.length()-1; i>=0; i--)
    {
        reverse += str[i];
    }
    return reverse;
}
            
void prefix_to_infix(string prefix)
{
    string PreFix = reverse(prefix);

    for(int i=0; i<PreFix.length(); i++)
    {
        char ch = PreFix[i];

        if(ch == ' ')
        continue;

        else if(isalnum(ch))
        push(string(1, ch));

        else
        {
           string opt1 = pop();
           string opt2 = pop();
           string Ans = "("+opt1 + ch + opt2 +")";
           push(Ans);
        }
    }
     cout << "INFIX EXPRESSION: " << pop() << endl;
}

int main()
{
    string prefix;
    cout<<"ENTER THE INFIX EXPRESSION"<<endl;
    getline(cin , prefix);

    prefix_to_infix(prefix);
return 0;
}
