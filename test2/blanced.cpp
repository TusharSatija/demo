#include<iostream>
#include<stack>
using namespace std;
bool solve(string s,stack<char> stk)
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(' or s[i]=='[' or s[i]=='{')
        {
            stk.push(s[i]);
        }
        else if(s[i]==')' or s[i]==']' or s[i]=='}')
        {
            if(stk.empty())
            {
                return false;
            }
            else if(s[i]==')' and stk.top()=='('  or s[i]==']' and stk.top()=='[' or stk.top()=='{' and  s[i]=='}')
            {
                stk.pop();
            }
        }
    }
        return stk.empty();
}
int main()
{
    stack<char> stk;
    string s;
    cin>>s;
    solve(s,stk)?cout<<"string is balanced ":cout<<"string is not balanced";
    int count=0;
    while (!stk.empty())
    {
        ++count;
    }
    cout<<count;
    
    return 0;
}
