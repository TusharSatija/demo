#include<iostream>
#include<bits/stdc++.h>
using namespace std;
stack<char> stk;
int toGetInvalidCount(string s,stack<char> stk)
{
 for (int i = 0;s[i]!='\0'; i++)
    {
        if(s[i]=='(')
        {
            stk.push(s[i]);
        }
        else{
        if(!stk.empty() and stk.top()=='(')
        {
                stk.pop();
        }
        else{
               stk.push(s[i]);
             }
        }
    }
    return stk.size();
}
unordered_set<string> uni;
void solve(string s,int minIvalid)
{
    if(minIvalid<0)
    {
        return ;
    }
    if(minIvalid==0)
    {
        if(!toGetInvalidCount(s,stk))
        {
            uni.insert(s);
        }
        return;
    }
    for (int i = 0; s[i]!='\0'; i++)
    {

        string  left_sub=s.substr(0,i);
        string right_sub=s.substr(i+1);
        solve(left_sub+right_sub,minIvalid-1);
    }
    
}
int main()
{
    string s;
    cin>>s;
    
    solve(s,toGetInvalidCount(s,stk));
    cout<<toGetInvalidCount(s,stk)<<endl;
    for(auto &i : uni)
    {
        cout<<i<<"    ";
    }
    return 0;
}